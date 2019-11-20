//
// Created by lucian on 19/09/19.
//

#include "EditTaskViewController.h"
#include "../Views/MainFrame.h"

EditTaskViewController::EditTaskViewController(Model *pModel, wxWindow *pWindow) {
    model = pModel;
    window = pWindow;
}

void EditTaskViewController::SaveNewTask(wxWindow *pWindows, const Task &task, bool isLastDayView) {
    model->addTask(task);
    auto tmp = (MainFrame *) (window);
    if (isLastDayView)
        tmp->ShowDayView(pWindows);
    tmp->ShowMainView(pWindows);
}

void
EditTaskViewController::SaveEditTask(wxWindow *pWindow, const Task &newTask, const Task &oldTask, bool isLastDayView) {
    model->updateTask(oldTask, newTask);
    auto tmp = (MainFrame *) (window);
    if (isLastDayView)
        tmp->ShowDayView(pWindow);
    else
        tmp->ShowTaskListView(pWindow);
}

void EditTaskViewController::CancelOperation(wxWindow *pWindow, bool isDayViewLastView) {
    auto tmp = (MainFrame *) (window);
    if (isDayViewLastView)
        tmp->ShowDayView(pWindow);
    else
        tmp->ShowTaskListView(pWindow);
}

