//dayView
// Created by giannimoretti on 17/06/19.
//

#include <algorithm>
#include "Model.h"
#include <exception>

Model::Model(IFIleRepository *repository) {
    this->repo = repository;
}

void Model::notify() const {
    for (auto obs : observers)
        obs->update();
}

void Model::subscribe(IObserver *obs) {
    observers.push_back(obs);
}

void Model::unsubscribe(IObserver *obs) {
    observers.remove(obs);
}

bool Model::addTask(const Task &task) {
    if (repo->addTask(task)) {
        taskMap.insert(std::make_pair(task.getDate(), task));
        notify();
        return true;
    }

    return false;
}

bool Model::removeTask(const Task &task) {
    bool ok = false;
    auto ref = taskMap.equal_range(task.getDate());

    for (auto itr = ref.first; itr != ref.second; itr++) {
        if (itr->second == task) {
            if (repo->deleteTask(task)) {
                taskMap.erase(itr);
                ok = true;
            }
            ok = false;
            break;
        }
    }
    notify();
    return ok;
}

bool Model::removeDay(const wxDateTime date) {
    bool ok = true;
    auto ref = taskMap.equal_range(date);

    for (auto itr = ref.first; itr != ref.second; itr++) {
        repo->deleteTask(itr->second);
    }
    taskMap.erase(ref.first, ref.second);
    notify();
    return ok;
}

Model::~Model() {}

const std::multimap<wxDateTime, Task> &Model::getTaskMap() const {
    return taskMap;
}

void Model::setTaskMap(const std::multimap<wxDateTime, Task> &taskMap) {
    Model::taskMap = taskMap;
}

int Model::numberOfTasks(wxDateTime dt) const {
    auto ref=taskMap.equal_range(dt);
    int count = std::distance(ref.first,ref.second);
    return count;
}

int Model::numberOfCompletedTasks(wxDateTime dateTime) const {
    int count = 0;
    auto ref=taskMap.equal_range(dateTime);
    for (auto itr = ref.first; itr != ref.second; itr++) {
        if (itr->second.isChecked())
            count++;
    }
    return count;
}

std::list<Task *> Model::researchTasks(const wxString str, bool unChecked) {
    //TODO: Fare test
    std::list<Task *> ris;

    if (unChecked)  // cerco solo quelli non verificati
        for (auto itr = taskMap.begin(); itr != taskMap.end(); itr++) {
            if (!itr->second.isChecked() && (itr->second.getName().find(str) != std::string::npos ||
                                             itr->second.getDescription().find(str) != std::string::npos))
                ris.push_back(&itr->second);
        }
    else
        for (auto itr = taskMap.begin(); itr != taskMap.end(); itr++) {
            if (itr->second.getName().find(str) != std::string::npos ||
                itr->second.getDescription().find(str) != std::string::npos)
                ris.push_back(&itr->second);
        }

    return ris;
}

std::pair<std::multimap<wxDateTime, Task>::iterator, std::multimap<wxDateTime, Task>::iterator>
Model::GetTasks(wxDateTime date) {
    return taskMap.equal_range(date);
}

std::list<wxDateTime> Model::GetKeysOnce() {
    std::list<wxDateTime> keys;
    for (auto itr = getTaskMap().begin(); itr != getTaskMap().end(); itr++) {
        if (std::find(keys.begin(), keys.end(), itr->first) == keys.end())
            keys.push_back(itr->first);
    }
    return keys;
}

std::list<Task *> Model::getTaskList(bool unChecked) {
    std::list<Task *> ris;

    if(unChecked){
        for (auto itr = taskMap.begin(); itr != taskMap.end(); itr++) {
            if (!itr->second.isChecked())
                ris.push_back(&(itr->second));
        }
    }
    else {
        for (auto itr = taskMap.begin(); itr != taskMap.end(); itr++) {
            ris.push_back(&(itr->second));
        }
    }
    return ris;
}

bool Model::updateTask(const Task &old, const Task &New) {
    auto ref = taskMap.equal_range(old.getDate());
    bool ok = false;

    for (auto itr = ref.first; itr != ref.second; itr++) {
        if (itr->second == old) {
            if (repo->updateTask(old, New)) {
                taskMap.erase(itr);
                taskMap.insert(std::make_pair(New.getDate(), New));
                ok = true;
            }
            break;
        }
    }
    notify();
    return ok;
}



