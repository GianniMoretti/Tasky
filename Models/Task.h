//
// Created by lucian on 13/06/19.
//

#ifndef TASKY_TASK_H
#define TASKY_TASK_H


#include <string>

using std::string;

enum class Priority {
    High,
    Medium,
    Low
};

class Task {
public:

    Task(string name, string description, Priority priority, bool checked = false)
            : name(name), description(description), priority(priority), checked(checked) {};

    bool operator==(const Task &task) const;

    const string &getName() const;

    const string &getDescription() const;

    Priority getPriority() const;

    bool isChecked() const;

private :
    string name;

private:
    string description;
    Priority priority;
    bool checked;

    bool isEqual(const Task &task) const;
};


#endif //TASKY_TASK_H
