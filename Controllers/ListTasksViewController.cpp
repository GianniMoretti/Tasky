//
// Created by lucian on 02/10/19.
//

#include "ListTasksViewController.h"
#include "../Views/MainFrame.h"

ListTasksViewController::ListTasksViewController(Model *pModel, wxWindow *pWindow) {
    model = pModel;
    window = pWindow;
}

void ListTasksViewController::GoHome(wxWindow *pView) {
    auto tmp = (MainFrame *) (window);
    tmp->ShowMainView(pView);
}

void ListTasksViewController::EditTask(wxWindow *pWindow, Task *task) {
    auto tmp = (MainFrame *) (window);
    tmp->ShowEditTaskView(pWindow, new wxDateTime(task->getDate()), true, task, false);
}
