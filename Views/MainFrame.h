//
// Created by lucian on 24/09/19.
//

#ifndef TASKY_MAINFRAME_H
#include <wx/wx.h>
#include "../Views/MainView.h"
#include "wxDayView.h"
#include "wxEditTaskView.h"
#include "ListTasksView.h"

#define TASKY_MAINFRAME_H


class MainFrame:public wxFrame {
public:
    MainFrame(Model* pModel,wxWindow*parent,wxString title,wxWindowID id, const wxPoint &pos, const wxSize &size);

    void ShowDayView(wxDateTime pTime);

    void SwapOnTaskListView();

    void SwapOnMainView();

    void ShowEditTaskView(wxDateTime *pTime, bool editMode, Task *pTask);

    void BackToDayView();

private:
    Model*model;
    MainView* mainView;
    ListTasksView* tasksView;
    wxDayView* dayView;
    wxEditTaskView* editTaskView;
};


#endif //TASKY_MAINFRAME_H
