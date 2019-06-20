#include <iostream>

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#include "Views/MainView.h"

#endif

class Tasky : public wxApp {
public:
    bool OnInit() override;
};


//potrebbe dare eccezzione da catturare
wxIMPLEMENT_APP(Tasky);

bool Tasky::OnInit() {
    MainView *mainView = new MainView("Tasky", wxPoint(50, 50), wxSize(500, 500));
    mainView->Show(true);
    return true;
}

