//
// Created by giannimoretti on 17/06/19.
//

#include "Model.h"

Model::Model() {
    //TODO: Ancora da implementare
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

void Model::addTask(wxDateTime dateTime, const Task &task) {
    taskMap.insert(std::make_pair(dateTime, task));
    notify();
}

void Model::removeTask(wxDateTime dateTime, const Task &task) {
    //TODO:: come si rimuove un elemento?
    //Come distinguiamo un elemento uno dall'altro?
    notify();
}

Model::~Model() {

}

const std::multimap<wxDateTime, Task> &Model::getTaskMap() const {
    return taskMap;
}

void Model::setTaskMap(const std::multimap<wxDateTime, Task> &taskMap) {
    Model::taskMap = taskMap;
}

int Model::numberTasksCompleted(wxDateTime dateTime) {
    int count = 0;
    for (auto itr = taskMap.find(dateTime); itr != taskMap.end(); itr++) {
        if (itr->second.checked)
            count++;
    }
    return count;
}
