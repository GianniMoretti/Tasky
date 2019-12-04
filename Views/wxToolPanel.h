//
// Created by lucian on 10/10/19.
//

#ifndef TASKY_WXTOOLPANEL_H
#define TASKY_WXTOOLPANEL_H


#include <wx/wx.h>

class wxToolPanel : public wxPanel {
public:
    wxBitmapButton *wxAddButton;
    wxBitmapButton *wxRemoveButton;
    wxBitmapButton *wxEditButton;
    wxBitmapButton *wxSwapButton;
    wxBitmapButton *wxCheckUnButton;
    wxBitmapButton *wxHomeButton;
    wxBitmapButton *wxNewDayButton;
    wxBitmapButton *wxRemoveDayButton;

    wxToolPanel(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size);

    void HideButtons();
};


#endif //TASKY_WXTOOLPANEL_H
