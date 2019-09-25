//
// Created by giannimoretti on 13/06/19.
//

#ifndef TASKY_MAINVIEW_H
#define TASKY_MAINVIEW_H

#include <wx/wxprec.h>
#include "wxDayBoxView.h"
#include "../Controllers/MainViewController.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class MainView : public wxPanel, IObserver {
protected:
    wxButton *wxButtonSwap;


public:
    MainView(Model *model,wxWindow*parent,wxWindowID id, const wxPoint &pos, const wxSize &size);

    ~MainView() override;

    void update() override;

private:
    Model *model;
    std::list<wxDayBoxView *> wxDayBoxViewsList;
    MainViewController *controller;

    void FillGridSizer(wxGridSizer *pSizer);

    void attach() override;

    void detach() override;

    void buttonOneClickSwapViews(wxEvent &event);
};


#endif //TASKY_MAINVIEW_H
