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


class MainView : public wxFrame, IObserver {
protected:
    wxButton *wxButtonSwap;



public:
    MainView(Model *model, const wxString &title, const wxPoint &pos, const wxSize &size);

    ~MainView() override;

    void update() override;

private:
    Model *model;
    std::list<wxDayBoxView *> wxDayBoxViewsList;

    void FillGridSizer(wxGridSizer *pSizer);

    void attach() override;

    void detach() override;

};


#endif //TASKY_MAINVIEW_H
