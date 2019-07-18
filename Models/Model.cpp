//
// Created by giannimoretti on 17/06/19.
//

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

void Model::addTask(wxDateTime dateTime, const Task &task) {
    taskMap.insert(std::make_pair(dateTime, task));
    notify();
}

bool Model::removeTask(wxDateTime dateTime, const Task &task) {
    bool ok = false;
    for (auto itr = taskMap.find(dateTime); itr != taskMap.end(); itr++) {
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
    int count = 0;
    for (auto itr = taskMap.find(dt); itr != taskMap.end(); itr++) {
        count++;
    }
    return count;
}

int Model::numberOfCompletedTasks(wxDateTime dateTime) const {
    int count = 0;
    for (auto itr = taskMap.find(dateTime); itr != taskMap.end(); itr++) {
        if (itr->second.isChecked())
            count++;
    }
    return count;
}

std::list<Task> Model::researchTasks(const wxString str) {
    //TODO: Come ricerca? Cossa ritorna?
    return std::list<Task>();
}
