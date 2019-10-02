//
// Created by giannimoretti on 25/09/19.
//

#ifndef TASKY_LISTTASKSVIEW_H
#define TASKY_LISTTASKSVIEW_H
#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/bmpbuttn.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/scrolwin.h>
#include <wx/panel.h>
#include "../Models/Model.h"

class ListTasksView : public wxPanel
{
private:
    Model* model;
protected:
    wxTextCtrl* m_textCtrl1;
    wxBitmapButton* m_bpButton1;
    wxBitmapButton* m_bpButton4;
    wxScrolledWindow* m_scrolledWindow1;
    wxButton* m_button3;
    wxButton* m_button4;

public:

    ListTasksView( wxWindow* parent,Model* pModel, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 892,531 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );
    ~ListTasksView();
    void FillScorlledWindow(std::list<Task> list);

};




#endif //TASKY_LISTTASKSVIEW_H
