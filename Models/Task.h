//
// Created by lucian on 13/06/19.
//

#ifndef TASKY_TASK_H
#define TASKY_TASK_H


#include <string>

using std::string;

enum Priority {
    High,
    Medium,
    Low
};

class Task {
public:
    string name;
    string description;
    Priority priority;
    bool checked;

    Task(string name, string description, Priority priority, bool checked = false)
            : name(name), description(description), priority(priority), checked(checked) {};
};


#endif //TASKY_TASK_H
