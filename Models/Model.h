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
#include "../FileManagement/IFIleRepository.h"
#include <wx/wx.h>


class Model : public IModel {
public:
    explicit Model(IFIleRepository *repository);

    void subscribe(IObserver *obs) override;

    void unsubscribe(IObserver *obs) override;

    ~Model() override;

    void addTask(const Task &task);

    bool removeTask(const Task &task);

    bool updateTask(const Task &old, const Task &New);

    std::list<Task *> researchTasks(wxString str, bool unChecked = false);

    const std::multimap<wxDateTime, Task> &getTaskMap() const;

    void setTaskMap(const std::multimap<wxDateTime, Task> &taskMap);

    int numberOfCompletedTasks(wxDateTime dateTime) const;

    int numberOfTasks(wxDateTime dt) const;

    std::pair<std::multimap<wxDateTime, Task>::iterator, std::multimap<wxDateTime, Task>::iterator>
    GetTasks(wxDateTime date);

    std::list<wxDateTime> GetKeysOnce();

    std::list<Task> getTaskList(bool unChecked = false);

private:
    void notify() const override;
    std::multimap<wxDateTime, Task> taskMap;
    std::list<IObserver *> observers;
    IFIleRepository *repo;
};


#endif //TASKY_MODEL_H
