//
// Created by giannimoretti on 25/09/19.
//

#ifndef TASKY_LISTTASKSVIEW_H
#define TASKY_LISTTASKSVIEW_H
#pragma once

#include <wx/wx.h>
#include "../Models/Model.h"
#include "../Controllers/ListTasksViewController.h"
#include "wxToolPanel.h"

class ListTasksView : public wxPanel, public IObserver
{
private:
    Model* model;
    ListTasksViewController *controller;
    std::list<Task> taskList;
    wxToolPanel *toolPanel;

    void FillCheckBoxList(std::list<Task> list);

    void OnButtonClickSwapView(wxEvent &event);

    void OnButtonClickHome(wxEvent &event);

    void OnButtonClickBack(wxEvent &event);

    void OnTextCtrlChanged(wxCommandEvent &event);

protected:
    wxTextCtrl *wxCtrlText;
    wxCheckListBox *listBox;

public:

    ListTasksView( wxWindow* parent,Model* pModel, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 892,531 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

    ~ListTasksView();

    void setTaskList(std::list<Task> &list);

    void LinkEvents();

    void update() override;

    void attach() override;

    void detach() override;
};




#endif //TASKY_LISTTASKSVIEW_H
