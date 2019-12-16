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
#include "../Controllers/DayViewController.h"
#include "wxToolPanel.h"
#include <wx/checklst.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif


class wxDayView : public wxPanel, IObserver {
protected:
    wxPanel *wxTopPanel;
    wxStaticText *m_staticText3;
    wxStaticText *wxMonthDayLabel;
    wxStaticText *wxStatTasksLabel;
    wxStaticLine *wxStaticline1;
    wxCheckListBox *listBox;
    wxStaticLine *wxStaticline2;
    wxGauge *wxProgressbar;

public:

    wxDayView(wxWindow *parent, Model *m ,wxDateTime date, wxWindowID id = wxID_ANY,
              const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(600, 500),
              long style = wxTAB_TRAVERSAL, const wxString &name = wxEmptyString);


    wxDayView()= default;

    ~wxDayView();

    void update() override;

    void attach() override;

    void detach() override;

    void LinkEvents();


private:
    wxDateTime dateTime;
    int numberOfCompletedTasks;
    int numberOfTasks;
    Model *model;
    DayViewController *controller;
    std::list<Task> tasks;
    wxToolPanel *toolPanel;

    void render();

    void AddTasksToGrid();

    void OnButtonClickRemoveTask(wxEvent &event);

    void OnButtonClickEditTask(wxEvent &event);

    void OnButtonClickAddNewTask(wxEvent &event);

    void OnButtonClickGoBack(wxEvent &event);

    void OnButtonClickGoHome(wxEvent &event);

    void OnButtonClickDeleteDay(wxEvent &event);

    void OnCheckedItem(wxCommandEvent &event);
    void refreshList();
};


#endif //TASKY_WXDAYVIEW_H
