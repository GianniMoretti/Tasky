//
// Created by lucian on 19/09/19.
//

#include "../Views/MainFrame.h"
#include "DayViewController.h"

DayViewController::DayViewController(Model *pModel, wxWindow *pWindow) {
    model = pModel;
    window = pWindow;
}

void DayViewController::ShowEditTaskView(wxDateTime *date, bool editMode, Task *task) {
    auto tmp = (MainFrame *) (window);
    tmp->ShowEditTaskView(date, editMode, task);
}

void DayViewController::RemoveTask(Task task) {
    model->removeTask(task);
}
