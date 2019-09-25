//dayView
// Created by giannimoretti on 17/06/19.
//

#include <algorithm>
#include "Model.h"



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

void Model::addTask(const Task &task) {
    taskMap.insert(std::make_pair(task.getDate(), task));
    notify();
}

bool Model::removeTask(const Task &task) {
    bool ok = false;
    for (auto itr = taskMap.find(task.getDate()); itr != taskMap.end(); itr++) {
        if (itr->second == task) {
            taskMap.erase(itr);
            ok = true;
            break;
        }
    }
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
    bool l=dt.IsValid();
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

std::list<Task *> Model::researchTasks(const wxString str, bool onlyUnchecked) {
    //TODO: Fare test
    std::list<Task *> ris;

    if (onlyUnchecked)  // cerco solo quelli non verificati
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

std::multimap<wxDateTime, Task>::iterator Model::GetTasks(wxDateTime date) {
    //TODO:meglio usare equal range e dare in out il risultato
    return taskMap.find(date);
}

std::list<wxDateTime> Model::GetKeysOnce() {
    std::list<wxDateTime> keys;
    for (auto itr = getTaskMap().begin(); itr != getTaskMap().end(); itr++) {
        if (std::find(keys.begin(), keys.end(), itr->first) == keys.end())
            keys.push_back(itr->first);
    }
    return keys;
}

