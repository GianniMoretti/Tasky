//
// Created by lucian on 10/10/19.
//

#ifndef TASKY_WXTOOLPANEL_H
#define TASKY_WXTOOLPANEL_H


#include <wx/wx.h>

class wxToolPanel : public wxPanel {
public:
    wxBitmapButton *wxBackButton;
    wxBitmapButton *wxAddButton;
    wxBitmapButton *wxRemoveButton;
    wxBitmapButton *wxEditButton;
    wxBitmapButton *wxSwapButton;
    wxBitmapButton *wxCheckUnButton;
    wxBitmapButton *m_bpButton21;
    wxBitmapButton *wxHomeButton;

    wxToolPanel(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);

};


#endif //TASKY_WXTOOLPANEL_H