//
// Created by giannimoretti on 17/06/19.
//

#ifndef TASKY_MODEL_H
#define TASKY_MODEL_H


#include <wx/datetime.h>
#include <map>
#include <list>
#include "IModel.h"
#include "Task.h"


class Model : public IModel {
public:
    Model() = default;

    void subscribe(IObserver *obs) override;

    void unsubscribe(IObserver *obs) override;

    ~Model() override;

    void addTask(wxDateTime dateTime, const Task &task);

    void removeTask(wxDateTime dateTime, const Task &task);

    //TODO: controllare se ha operatore
    const std::multimap<wxDateTime, Task> &getTaskMap() const;

    void setTaskMap(const std::multimap<wxDateTime, Task> &taskMap);

    int numberOfCompletedTasks(wxDateTime dateTime) const;

    int numberOfTasks(wxDateTime dt) const;

    std::multimap<wxDateTime, Task>::iterator GetTasks(wxDateTime date);

private:
    void notify() const override;
    std::multimap<wxDateTime, Task> taskMap;
    std::list<IObserver *> observers;
};


#endif //TASKY_MODEL_H