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

    void addTask(const Task &task);

    bool removeTask(const Task &task);

    std::list<Task> researchTasks(wxString str, bool Unchecked = false);

    const std::multimap<wxDateTime, Task> &getTaskMap() const;

    void setTaskMap(const std::multimap<wxDateTime, Task> &taskMap);

    int numberOfCompletedTasks(wxDateTime dateTime) const;

    int numberOfTasks(wxDateTime dt) const;

private:
    void notify() const override;
    std::multimap<wxDateTime, Task> taskMap;
    std::list<IObserver *> observers;
};


#endif //TASKY_MODEL_H
