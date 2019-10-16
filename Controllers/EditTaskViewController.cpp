//
// Created by lucian on 19/09/19.
//

#include "EditTaskViewController.h"
#include "../Views/MainFrame.h"

EditTaskViewController::EditTaskViewController(Model *pModel, wxWindow *pWindow) {
    model = pModel;
    window = pWindow;
}

void EditTaskViewController::SaveNewTask(wxWindow *pWindows, Task task) {
    model->addTask(task);
    auto tmp = (MainFrame *) (window);
    tmp->ShowDayView(pWindows);
}

void EditTaskViewController::SaveEditTask(wxWindow *pWindows, Task newTask, Task oldTask, bool isLastDayView) {
    model->updateTask(oldTask, newTask);
    auto tmp = (MainFrame *) (window);
    if (isLastDayView)
        tmp->ShowDayView(pWindows);
    else
        tmp->ShowTaskListView(pWindows);
}

