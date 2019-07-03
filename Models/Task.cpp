//
// Created by lucian on 13/06/19.
//

#include "Task.h"


bool Task::operator==(const Task &task) const {
    return isEqual(task);
}

bool Task::isEqual(const Task &task) const {
    return task.name == this->name && task.description == this->description && task.priority == this->priority &&
           task.checked == this->checked;
}
