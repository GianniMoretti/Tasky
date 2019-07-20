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

void Model::removeTask(wxDateTime dateTime, const Task &task) {
    //FIXME:: come si rimuove un elemento? Se possibile trovare un'alternativa.
    //Come distinguiamo un elemento uno dall'altro?Possibile soluzione: utilizzo operator ==.(Non unica soluzione)
    for (auto itr = taskMap.find(dateTime); itr != taskMap.end(); itr++) {
        if (itr->second == task) {
            taskMap.erase(itr);
            break;
        }
    }
    notify();
}

Model::~Model() {}

const std::multimap<wxDateTime, Task> &Model::getTaskMap() const {
    return taskMap;
}

void Model::setTaskMap(const std::multimap<wxDateTime, Task> &taskMap) {
    Model::taskMap = taskMap;
}

int Model::numberOfTasks(wxDateTime dt) const {
    //TODO: Dobbiamo controllare find()?
    int count = 0;
    for (auto itr = taskMap.find(dt); itr != taskMap.end(); itr++) {
        count++;
    }
    return count;
}

int Model::numberOfCompletedTasks(wxDateTime dateTime) const {
    //TODO: Dobbiamo controllare find()?
    int count = 0;
    for (auto itr = taskMap.find(dateTime); itr != taskMap.end(); itr++) {
        if (itr->second.isChecked())
            count++;
    }
    return count;
}

std::multimap<wxDateTime, Task>::iterator Model::GetTasks(wxDateTime date) {
    return taskMap.find(date);
}