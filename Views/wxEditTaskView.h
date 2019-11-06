//
// Created by lucian on 21/07/19.
//

#ifndef TASKY_WXEDITTASKVIEW_H
#define TASKY_WXEDITTASKVIEW_H

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/choice.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/panel.h>
#include "../IObserver.h"
#include "../Models/Task.h"
#include "../Models/Model.h"
#include "../Controllers/EditTaskViewController.h"


class wxEditTaskView : public wxPanel, IObserver {

protected:
    wxStaticText *m_staticText1;
    wxTextCtrl *wxNameTxt;
    wxStaticText *m_staticText3;
    wxChoice *wxPriorityCmbox;
    wxStaticText *m_staticText4;
    wxDatePickerCtrl *m_datePicker2;
    wxStaticText *m_staticText2;
    wxTextCtrl *wxDescriptionTxt;
    wxButton *wxSaveButton;
    wxButton *wxCancelButton;

public:

    wxEditTaskView(wxWindow *parent, Model *model, wxDateTime *pTime, bool editMode, Task *pTask, bool isDayViewLast,
                   const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(500, 300),
                   long style = wxTAB_TRAVERSAL, const wxString &name = wxEmptyString, wxWindowID id = wxID_ANY);

    ~wxEditTaskView();

    void update() override;


private:

    Model *model;

    Task *task;

    wxDateTime *date;

    bool editMode;

    bool isDayViewLast;

    EditTaskViewController *controller;

    void attach() override;

    void detach() override;

    //events
    void OnButtonClickSaveEditTask(wxEvent &event);

    void OnButtonClickSaveNewTask(wxEvent &event);

    void OnButtonClickCancelOperation(wxEvent &event);

    Task GetTask();
};


#endif //TASKY_WXEDITTASKVIEW_H
