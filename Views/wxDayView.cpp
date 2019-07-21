//
// Created by lucian on 20/07/19.
//

//#include <wx/gtk/checkbox.h>
#include "wxDayView.h"


wxDayView::wxDayView(wxWindow *parent, Model *m, wxDateTime date, wxWindowID id, const wxPoint &pos, const wxSize &size,
                     long style, const wxString &name) : wxPanel(parent, id, pos, size, style, name) {
    model = m;
    numberOfTasks = model->numberOfTasks(dateTime);
    numberOfCompletedTasks = model->numberOfCompletedTasks(dateTime);

    //TODO:Call attach();
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

    wxBoxSizer *wxMainSizer;
    wxMainSizer = new wxBoxSizer(wxVERTICAL);

    wxMainSizer->SetMinSize(wxSize(5000, 5000));
    wxTopPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 20), wxTAB_TRAVERSAL);
    wxTopPanel->SetFont(
            wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false,
                   wxEmptyString));
    wxTopPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxTopPanel->SetMaxSize(wxSize(-1, 20));

    wxMainSizer->Add(wxTopPanel, 1, wxEXPAND, 5);

    wxBoxSizer *wxDetailsSizer;
    wxDetailsSizer = new wxBoxSizer(wxHORIZONTAL);

    wxDetailsSizer->SetMinSize(wxSize(5000, 5000));
    wxBoxSizer *wxDayInfoOperetionSizer;
    wxDayInfoOperetionSizer = new wxBoxSizer(wxVERTICAL);


    wxDayInfoOperetionSizer->Add(0, 0, 1, wxEXPAND, 5);

    wxBoxSizer *wxTopLabelSizer;
    wxTopLabelSizer = new wxBoxSizer(wxHORIZONTAL);

    wxString num = date.Format(wxT("%d"), wxDateTime::CET).c_str();
    m_staticText3 = new wxStaticText(this, wxID_ANY, num, wxDefaultPosition, wxSize(150, 100), 0);
    m_staticText3->Wrap(-1);
    m_staticText3->SetFont(
            wxFont(80, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

    wxTopLabelSizer->Add(m_staticText3, 1, wxALL | wxEXPAND | wxSHAPED | wxALIGN_CENTER_VERTICAL, 5);

    wxString day = date.Format(wxT("%a"), wxDateTime::CET).c_str();
    wxString month = date.Format(wxT("%b"), wxDateTime::CET).c_str();
    wxString fulldate = wxString::Format(day + "\n" + month);
    wxMonthDayLabel = new wxStaticText(this, wxID_ANY, fulldate, wxDefaultPosition, wxSize(100, 100), 0);
    wxMonthDayLabel->Wrap(-1);
    wxMonthDayLabel->SetFont(
            wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString));

    wxTopLabelSizer->Add(wxMonthDayLabel, 0, wxALIGN_CENTER_VERTICAL | wxEXPAND | wxSHAPED | wxTOP, 30);


    wxDayInfoOperetionSizer->Add(wxTopLabelSizer, 1, wxEXPAND, 5);


    wxDayInfoOperetionSizer->Add(0, 0, 1, wxEXPAND, 5);

    wxBoxSizer *wxButtonSizer;
    wxButtonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxString stat = wxString::Format("%d / %d", numberOfCompletedTasks, numberOfTasks);
    wxStatTasksLabel = new wxStaticText(this, wxID_ANY, stat, wxDefaultPosition, wxSize(-1, 40),
                                        wxALIGN_CENTER_HORIZONTAL);
    wxStatTasksLabel->Wrap(-1);
    wxStatTasksLabel->SetFont(
            wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString));

    wxButtonSizer->Add(wxStatTasksLabel, 1, wxALIGN_BOTTOM, 10);


    wxDayInfoOperetionSizer->Add(wxButtonSizer, 1, wxALIGN_BOTTOM | wxEXPAND, 5);


    wxDetailsSizer->Add(wxDayInfoOperetionSizer, 1, wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);

    wxStaticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL);
    wxStaticline1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    wxStaticline1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

    wxDetailsSizer->Add(wxStaticline1, 0, wxALL | wxEXPAND, 0);

    wxBoxSizer *bSizer8;
    bSizer8 = new wxBoxSizer(wxVERTICAL);

    wxScrolledWindowTask = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(-1, -1),
                                                wxHSCROLL | wxVSCROLL);
    wxScrolledWindowTask->SetScrollRate(5, 5);
    wxBoxSizer *wxTasksSizer;
    wxTasksSizer = new wxBoxSizer(wxVERTICAL);

    wxTasksSizer->SetMinSize(wxSize(50000, -1));

    wxScrolledWindowTask->SetSizer(wxTasksSizer);
    wxScrolledWindowTask->Layout();
    wxTasksSizer->Fit(wxScrolledWindowTask);
    bSizer8->Add(wxScrolledWindowTask, 1, wxALL | wxEXPAND, 10);

    wxBoxSizer *bSizer4;
    bSizer4 = new wxBoxSizer(wxHORIZONTAL);

    wxRemoveButton = new wxButton(this, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(wxRemoveButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);

    wxEditButton = new wxButton(this, wxID_ANY, wxT("Edit"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(wxEditButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);

    wxNewTaskButton = new wxButton(this, wxID_ANY, wxT("New task"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(wxNewTaskButton, 0, wxALIGN_CENTER_VERTICAL | wxALL, 10);


    bSizer8->Add(bSizer4, 0, wxALIGN_CENTER | wxLEFT | wxSHAPED, 5);


    wxDetailsSizer->Add(bSizer8, 1, wxEXPAND, 5);


    wxMainSizer->Add(wxDetailsSizer, 1, wxEXPAND, 5);

    wxStaticline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    wxStaticline2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

    wxMainSizer->Add(wxStaticline2, 0, wxEXPAND | wxALL, 0);

    wxProgressbar = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxSize(1000, 10), wxGA_HORIZONTAL);
    int progressbarValue = (numberOfCompletedTasks * numberOfTasks) / 100;
    wxProgressbar->SetValue(progressbarValue);
    wxMainSizer->Add(wxProgressbar, 0, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxBOTTOM | wxRIGHT | wxLEFT, 5);

    AddTasksToScrolledWindow(date);

    this->SetSizer(wxMainSizer);
    this->Layout();
}

wxDayView::~wxDayView() {
    detach();
}

void wxDayView::update() {
    numberOfTasks = model->numberOfTasks(dateTime);
    numberOfCompletedTasks = model->numberOfCompletedTasks(dateTime);
    render();
}

void wxDayView::attach() {
    model->subscribe(this);
}

void wxDayView::detach() {
    model->unsubscribe(this);
}

void wxDayView::render() {
    //TODO:Aggiornare label stats e progressbar
}

void wxDayView::AddTasksToScrolledWindow(wxDateTime date) {
    //TODO:Creazione CheckBox
    for (auto iterator = model->GetTasks(date); iterator != model->getTaskMap().end(); iterator++) {
        //wxCheckBox box = new wxCheckBox(wxScrolledWindowTask, wxID_ANY, iterator->second.getName(), wxDefaultPosition,
        //                                wxDefaultSize, 0);
    }
}
