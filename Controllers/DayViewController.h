//
// Created by lucian on 19/09/19.
//

#ifndef TASKY_DAYVIEWCONTROLLER_H
#define TASKY_DAYVIEWCONTROLLER_H


#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

#include "../Models/Model.h"


class DayViewController {

public:
    DayViewController(Model *pModel, wxWindow *pWindow);

    void ShowEditTaskView(wxWindow *currentView, wxDateTime *date, bool editMode = false, Task *task = nullptr);

    void RemoveTask(Task task);

    void BackToHomeView(wxWindow *currentView);

    void GoHome(wxWindow *pView);

private:
    Model *model;
    wxWindow *window;
};


#endif //TASKY_DAYVIEWCONTROLLER_H
