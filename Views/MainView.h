//
// Created by giannimoretti on 13/06/19.
//

#ifndef TASKY_MAINVIEW_H
#define TASKY_MAINVIEW_H

#include <wx/wxprec.h>
#include "wxDayBoxView.h"
#include "../Controllers/MainViewController.h"
#include "wxToolPanel.h"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif


class MainView : public wxPanel, IObserver {
protected:
    wxBitmapButton *wxLeftButton;
    wxBitmapButton *wxRightButton;
    wxGridSizer *gSizer4;


public:
    MainView(Model *model,wxWindow*parent,wxWindowID id, const wxPoint &pos, const wxSize &size);

    ~MainView() override;

    void update() override;


    void LinkEvents();

private:
    Model *model;
    std::list<wxDayBoxView *> wxDayBoxViewsList;
    MainViewController *controller;
    wxToolPanel *toolPanel;

    void FillGridSizer(wxGridSizer *pSizer);

    void OnButtonClickSwapView(wxEvent &event);

    void OnShow(wxShowEvent &event);

    void attach() override;

    void detach() override;

};


#endif //TASKY_MAINVIEW_H
