//
// Created by lucian on 19/09/19.
//

#include "../Views/MainFrame.h"
#include "DayViewController.h"

DayViewController::DayViewController(Model *pModel, wxWindow *pWindow) {
    model = pModel;
    window = pWindow;
}

void DayViewController::ShowEditTaskView(wxWindow *currentView, wxDateTime *date, bool editMode, Task *task) {
    auto tmp = (MainFrame *) (window);
    tmp->ShowEditTaskView(currentView, date, editMode, task, true);
}

void DayViewController::RemoveTask(Task task) {
    model->removeTask(task);
}

void DayViewController::BackToHomeView(wxWindow *currentView) {
    auto tmp = (MainFrame *) (window);
    tmp->GoBack(currentView, 1);
}

void DayViewController::GoHome(wxWindow *pView) {
    auto tmp = (MainFrame *) (window);
    tmp->ShowMainView(pView);
}
