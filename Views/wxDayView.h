//
// Created by lucian on 20/07/19.
//

#ifndef TASKY_WXDAYVIEW_H
#define TASKY_WXDAYVIEW_H


#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/scrolwin.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/gauge.h>
#include "../IObserver.h"
#include "../Models/Model.h"

class wxDayView : public wxPanel, IObserver {
protected:
    wxPanel *wxTopPanel;
    wxStaticText *m_staticText3;
    wxStaticText *wxMonthDayLabel;
    wxStaticText *wxStatTasksLabel;
    wxStaticLine *wxStaticline1;
    wxScrolledWindow *wxScrolledWindowTask;
    wxButton *wxRemoveButton;
    wxButton *wxEditButton;
    wxButton *wxNewTaskButton;
    wxStaticLine *wxStaticline2;
    wxGauge *wxProgressbar;

public:

    wxDayView(wxWindow *parent, Model *m, wxDateTime date, wxWindowID id = wxID_ANY,
              const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(600, 500),
              long style = wxTAB_TRAVERSAL, const wxString &name = wxEmptyString);

    ~wxDayView();

    void update() override;

    void attach() override;

    void detach() override;


private:
    wxDateTime dateTime;
    int numberOfCompletedTasks;
    int numberOfTasks;
    Model *model;

    void render();

    void AddTasksToScrolledWindow(wxDateTime date);

};


#endif //TASKY_WXDAYVIEW_H
