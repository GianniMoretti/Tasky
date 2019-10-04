//
// Created by giannimoretti on 20/06/19.
//

#ifndef TASKY_IFILEREPOSITORY_H
#define TASKY_IFILEREPOSITORY_H

#include <map>
#include <wx/datetime.h>

#include "../Models/Task.h"
#include "../IObserver.h"

class IFIleRepository {
public:
    virtual ~IFIleRepository() = default;

    virtual bool addTask(const Task &t) = 0;

    virtual bool deleteTask(const Task &t) = 0;

    virtual bool updateTask(const Task &oldTask, const Task &newTask) = 0;

    virtual std::multimap<wxDateTime, Task> loadTaskFromFile() = 0;
};


#endif //TASKY_IFILEREPOSITORY_H
