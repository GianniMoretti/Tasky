//
// Created by lucian on 27/06/19.
//

#ifndef TASKY_WXDAYBOXVIEW_H
#define TASKY_WXDAYBOXVIEW_H

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/statline.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/gauge.h>
#include <wx/panel.h>
#include "../IObserver.h"
#include "../Models/Model.h"


class wxDayBoxView : public wxPanel, public IObserver {
protected:
    //TODO: é meglio utilizzare smart pointer?
    wxStaticLine *m_staticline7;
    wxStaticLine *m_staticline1;
    wxButton *wxDayButton;
    wxStaticText *wxDayInfoLabel;
    wxStaticText *wxStatTasksLabel;
    wxGauge *wxProgressbar;
    wxStaticLine *m_staticline2;
    wxStaticLine *m_staticline8;

public:

    wxDayBoxView(Model *m, wxDateTime dt, wxWindow *parent, wxWindowID id = wxID_ANY,
                 const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(150, 150),
                 long style = wxTAB_TRAVERSAL, const wxString &name = wxEmptyString);

    ~wxDayBoxView() override;

    void update() override;

    void attach() override;

    void detach() override;

private:
    wxDateTime dateTime;
    int numberOfCompletedTasks;
    int numberOfTasks;
    Model *model;

    void render();
};


#endif //TASKY_WXDAYBOXVIEW_H
