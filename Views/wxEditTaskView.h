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
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/panel.h>
#include "../IObserver.h"
#include "../Models/Task.h"
#include "../Models/Model.h"


class wxEditTaskView : public wxPanel, IObserver {

protected:
    wxStaticText *m_staticText1;
    wxTextCtrl *wxNameTxt;
    wxStaticText *m_staticText3;
    wxChoice *wxPriorityCmbox;
    wxStaticText *m_staticText2;
    wxTextCtrl *wxDescriptionTxt;
    wxButton *wxSaveButton;
    wxButton *wxCancelButton;

public:

    wxEditTaskView(wxWindow *parent, Model *model, Task task, wxWindowID id = wxID_ANY,
                   const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(500, 300),
                   long style = wxTAB_TRAVERSAL, const wxString &name = wxEmptyString);

    ~wxEditTaskView();

    void update() override;

private:

    Model *model;

    void attach() override;

    void detach() override;

};


#endif //TASKY_WXEDITTASKVIEW_H
