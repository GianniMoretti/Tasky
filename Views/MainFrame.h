//
// Created by lucian on 24/09/19.
//

#ifndef TASKY_MAINFRAME_H
#include <wx/wx.h>
#include "../Views/MainView.h"
#include "wxDayView.h"
#include "wxEditTaskView.h"
#define TASKY_MAINFRAME_H


class MainFrame:public wxFrame {
public:
    MainFrame(Model* pModel,wxWindow*parent,wxString title,wxWindowID id, const wxPoint &pos, const wxSize &size);

    void ShowDayView(wxDateTime pTime);

private:
    Model*model;
    MainView* mainView;
    wxDayView* dayView;
    wxEditTaskView* editTaskView;
};


#endif //TASKY_MAINFRAME_H
