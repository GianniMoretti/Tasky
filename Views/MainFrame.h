//
// Created by lucian on 24/09/19.
//

#ifndef TASKY_MAINFRAME_H
#include <wx/wx.h>
#include "../Views/MainView.h"
#include "wxDayView.h"
#include "wxEditTaskView.h"
#include "ListTasksView.h"
#include "wxToolPanel.h"

#define TASKY_MAINFRAME_H


class MainFrame:public wxFrame {
public:

    MainFrame(Model* pModel,wxWindow*parent,wxString title,wxWindowID id, const wxPoint &pos, const wxSize &size);

    wxToolPanel *GetToolPanel();

    void ShowDayView(wxWindow *currentView, wxDateTime *pTime = nullptr);

    void ShowTaskListView(wxWindow *currentView);

    void ShowMainView(wxWindow *currentView);

    void ShowEditTaskView(wxWindow *currentView, wxDateTime *pTime, bool editMode, Task *pTask);


    void GoBack(wxWindow *pWindow, int currentIndex);

private:
    Model*model;
    MainView* mainView;
    ListTasksView* tasksView;
    wxDayView* dayView;
    wxEditTaskView* editTaskView;
    wxToolPanel *toolPanel;


protected:
    wxBoxSizer *sizer;
    wxBoxSizer *sizer2;

};


#endif //TASKY_MAINFRAME_H
