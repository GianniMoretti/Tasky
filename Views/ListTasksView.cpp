//
// Created by giannimoretti on 25/09/19.
//

#include "ListTasksView.h"

ListTasksView::ListTasksView( wxWindow* parent,Model* pModel, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
    model=pModel;

    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer2;
    bSizer2 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer6;
    bSizer6 = new wxBoxSizer( wxHORIZONTAL );

    m_textCtrl1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
    m_textCtrl1->SetMinSize( wxSize( 200,-1 ) );

    bSizer6->Add( m_textCtrl1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

    m_bpButton1 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
    bSizer6->Add( m_bpButton1, 0, wxALL, 5 );


    bSizer2->Add( bSizer6, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

    m_bpButton4 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
    bSizer2->Add( m_bpButton4, 0, wxALL|wxALIGN_RIGHT, 5 );


    bSizer1->Add( bSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );

    wxBoxSizer* bSizer3;
    bSizer3 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer( wxHORIZONTAL );


    bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );

    m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    m_scrolledWindow1->SetScrollRate( 5, 5 );

    FillScorlledWindow(model->getTaskList(false));

    bSizer4->Add( m_scrolledWindow1, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );


    bSizer4->Add( 0, 0, 1, wxEXPAND, 5 );


    bSizer3->Add( bSizer4, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer5;
    bSizer5 = new wxBoxSizer( wxHORIZONTAL );

    m_button3 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer5->Add( m_button3, 0, wxALL, 5 );

    m_button4 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer5->Add( m_button4, 0, wxALL, 5 );


    bSizer3->Add( bSizer5, 0, wxALIGN_RIGHT|wxSHAPED, 5 );


    bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );


    this->SetSizer( bSizer1 );
    this->Layout();
}

ListTasksView::~ListTasksView()
{
}

void ListTasksView::FillScorlledWindow(std::list<Task> list) {
    wxBoxSizer* bSizer7;
    bSizer7 = new wxBoxSizer( wxVERTICAL );

    for (auto task:list) {
        //Da usare per mettere i task nella scolled window
        wxString num = task.getDate().Format(wxT("%d"), wxDateTime::CET).c_str();
        wxString day = task.getDate().Format(wxT("%a"), wxDateTime::CET).c_str();
        wxString month = task.getDate().Format(wxT("%b"), wxDateTime::CET).c_str();
        wxString full = wxString::Format(task.getDescription()+" | "+num+" "+day+"/" + month);
        wxCheckBox* m_checkBox1 = new wxCheckBox( m_scrolledWindow1, wxID_ANY,full, wxDefaultPosition, wxDefaultSize, 0 );
        m_checkBox1->SetValue(task.isChecked());
        bSizer7->Add( m_checkBox1, 0, wxALL, 5 );
    }

    m_scrolledWindow1->SetSizer( bSizer7 );
    m_scrolledWindow1->Layout();
    bSizer7->Fit( m_scrolledWindow1 );
}
