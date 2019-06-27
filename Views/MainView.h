//
// Created by giannimoretti on 13/06/19.
//

#ifndef TASKY_MAINVIEW_H
#define TASKY_MAINVIEW_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>
#include "wxDayBoxView.h"

#endif


class MainView : public wxFrame {
public:
    MainView(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    wxDayBoxView *Day;
};


#endif //TASKY_MAINVIEW_H
