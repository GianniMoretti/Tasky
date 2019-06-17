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
    Model();

    void notify() const override;

    void subscribe(IObserver *obs) override;

    void unsubscribe(IObserver *obs) override;

    ~Model() override;

    void addTask(wxDateTime dateTime, const Task &task);

    void RemoveTask(wxDateTime dateTime, const Task &task);

private:
    std::multimap<wxDateTime, Task> taskMap;
    std::list<IObserver *> observers;
};


#endif //TASKY_MODEL_H