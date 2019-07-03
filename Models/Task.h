//
// Created by lucian on 13/06/19.
//

#ifndef TASKY_TASK_H
#define TASKY_TASK_H


#include <string>

using std::string;

//TODO: Classe num
enum Priority {
    High,
    Medium,
    Low
};

//TODO: Privati get setter
class Task {
public:
    string name;
    string description;
    Priority priority;
    bool checked;

    Task(string name, string description, Priority priority, bool checked = false)
            : name(name), description(description), priority(priority), checked(checked) {};

    bool operator==(const Task &task) const;

private :
    bool isEqual(const Task &task) const;
};


#endif //TASKY_TASK_H
