//
// Created by lucian on 19/09/19.
//

#ifndef TASKY_EDITTASKVIEWCONTROLLER_H
#define TASKY_EDITTASKVIEWCONTROLLER_H


#include "../Models/Model.h"

class EditTaskViewController {

public:
    EditTaskViewController(Model *pModel, wxWindow *pWindow);

    void SaveNewTask(wxWindow *pWindows, Task task);

    void SaveEditTask(wxWindow *pWindows, Task newTask, Task oldTask, bool isLastDayView = true);

private:
    Model *model;
    wxWindow *window;
};


#endif //TASKY_EDITTASKVIEWCONTROLLER_H
