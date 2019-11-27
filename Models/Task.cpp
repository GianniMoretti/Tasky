//
// Created by lucian on 13/06/19.
//

#include "Task.h"


bool Task::operator==(const Task &task) const {
    return isEqual(task);
}

bool Task::isEqual(const Task &task) const {
    return task.name == this->name && task.description == this->description && task.priority == this->priority &&
           task.getDate() == this->getDate();
}

const string &Task::getName() const {
    return name;
}

const string &Task::getDescription() const {
    return description;
}

Priority Task::getPriority() const {
    return priority;
}

bool Task::isChecked() const {
    return checked;
}

const wxDateTime Task::getDate() const {
    return date.GetDateOnly();
}

const string Task::getPriorityString() const {
    string ris;

    switch (priority) {
        case Priority::High:
            ris = "High";
            break;
        case Priority::Medium:
            ris = "Medium";
            break;
        case Priority::Low:
            ris = "Low";
            break;
    }
    return ris;
}
