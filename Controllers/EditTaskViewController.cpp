//
// Created by lucian on 19/09/19.
//

#include "EditTaskViewController.h"
#include "../Views/MainFrame.h"

EditTaskViewController::EditTaskViewController(Model *pModel, wxWindow *pWindow) {
    model = pModel;
    window = pWindow;
}

void EditTaskViewController::SaveNewTask(Task task) {
    model->addTask(task);
    auto tmp = (MainFrame *) (window);
    tmp->BackToDayView();
}

void EditTaskViewController::SaveEditTask(Task newTask, Task oldTask) {
    //TODO::Call model metodo update (dopo il push)
    model->updateTask(oldTask, newTask);
    auto tmp = (MainFrame *) (window);
    tmp->BackToDayView();
}

void EditTaskViewController::CancelOperation() {
    auto tmp = (MainFrame *) (window);
    tmp->BackToDayView();
}
