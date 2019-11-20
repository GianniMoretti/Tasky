//
// Created by lucian on 27/06/19.
//

#ifndef TASKY_WXDAYBOXVIEW_H
#define TASKY_WXDAYBOXVIEW_H

#pragma once

#include <wx/wx.h>
#include <wx/statline.h>
#include "../IObserver.h"
#include "../Models/Model.h"
#include "../Controllers/MainViewController.h"


class wxDayBoxView : public wxPanel, public IObserver {
protected:
    wxStaticLine *m_staticline7;
    wxStaticLine *m_staticline1;
    wxButton *wxDayButton;
    wxStaticText *wxDayInfoLabel;
    wxStaticText *wxStatTasksLabel;
    wxGauge *wxProgressbar;
    wxStaticLine *m_staticline2;
    wxStaticLine *m_staticline8;

public:

    wxDayBoxView(Model *m,MainViewController* pController, wxDateTime dt, wxWindow *parent, wxWindowID id = wxID_ANY,
                 const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(150, 150),
                 long style = wxTAB_TRAVERSAL, const wxString &name = wxEmptyString);

    ~wxDayBoxView() override;

    void update() override;

    void attach() override;

    void detach() override;

private:
    MainViewController* controller;
    wxDateTime dateTime;
    int numberOfCompletedTasks;
    int numberOfTasks;
    Model *model;

    void buttonOneClickShowDay(wxEvent &event);
    void render();
};


#endif //TASKY_WXDAYBOXVIEW_H
