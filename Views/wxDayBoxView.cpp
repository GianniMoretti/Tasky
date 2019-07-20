//
// Created by lucian on 27/06/19.
//

#include "wxDayBoxView.h"

wxDayBoxView::wxDayBoxView(Model *m, wxDateTime dt, wxWindow *parent, wxWindowID id, const wxPoint &pos,
                           const wxSize &size, long style, const wxString &name) : wxPanel(parent, id, pos, size, style,
                                                                                           name) {
    //TODO:Call attach();
    model = m;
    numberOfTasks = model->numberOfTasks(dateTime);
    numberOfCompletedTasks = model->numberOfCompletedTasks(dateTime);

    this->SetFont(
            wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false,
                   wxEmptyString));
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));

    //FIXME:Devo liberare la memoria?
    wxBoxSizer *wxMainSizer;
    wxMainSizer = new wxBoxSizer(wxHORIZONTAL);

    m_staticline7 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(2, -1), wxLI_HORIZONTAL);
    m_staticline7->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));

    wxMainSizer->Add(m_staticline7, 0, wxEXPAND, 0);

    wxBoxSizer *wxMainSizer2;
    wxMainSizer2 = new wxBoxSizer(wxVERTICAL);

    m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 2), wxLI_HORIZONTAL);
    m_staticline1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HIGHLIGHT));

    wxMainSizer2->Add(m_staticline1, 0, wxEXPAND, 0);

    wxBoxSizer *wxMainSizer3;
    wxMainSizer3 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *wxDateSizer;
    wxDateSizer = new wxBoxSizer(wxHORIZONTAL);

    wxString num = dt.Format(wxT("%d"), wxDateTime::CET).c_str();
    wxDayButton = new wxButton(this, wxID_ANY, num, wxDefaultPosition, wxDefaultSize, 0);
    wxDayButton->SetFont(wxFont(26, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Sans")));
    wxDayButton->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxDayButton->SetMaxSize(wxSize(75, -1));

    wxDateSizer->Add(wxDayButton, 0, wxALIGN_CENTER_VERTICAL | wxALL | wxEXPAND, 5);

    wxString day = dt.Format(wxT("%a"), wxDateTime::CET).c_str();
    wxString month = dt.Format(wxT("%b"), wxDateTime::CET).c_str();
    wxString date = wxString::Format(day + "\n" + month);
    wxDayInfoLabel = new wxStaticText(this, wxID_ANY, date, wxDefaultPosition, wxSize(-1, 45),
                                      wxALIGN_CENTER_HORIZONTAL);
    wxDayInfoLabel->Wrap(-1);
    wxDayInfoLabel->SetFont(
            wxFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString));

    wxDateSizer->Add(wxDayInfoLabel, 1, wxALIGN_CENTER_VERTICAL | wxALL, 5);


    wxMainSizer3->Add(wxDateSizer, 1, wxEXPAND, 5);

    wxString t = wxString::Format("%d / %d", numberOfCompletedTasks, numberOfTasks);
    wxStatTasksLabel = new wxStaticText(this, wxID_ANY, t, wxDefaultPosition, wxSize(-1, 20),
                                        wxALIGN_CENTER_HORIZONTAL);
    wxStatTasksLabel->Wrap(-1);
    wxStatTasksLabel->SetFont(
            wxFont(16, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString));

    wxMainSizer3->Add(wxStatTasksLabel, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL, 5);

    wxProgressbar = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxSize(-1, 10), wxGA_HORIZONTAL);
    int progressbarValue = (numberOfCompletedTasks * numberOfTasks) / 100;
    wxProgressbar->SetValue(progressbarValue);
    wxMainSizer3->Add(wxProgressbar, 0, wxALL | wxEXPAND, 5);


    wxMainSizer2->Add(wxMainSizer3, 1, wxEXPAND, 5);

    m_staticline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 2), wxLI_HORIZONTAL);
    m_staticline2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));

    wxMainSizer2->Add(m_staticline2, 0, wxEXPAND, 0);


    wxMainSizer->Add(wxMainSizer2, 1, wxEXPAND, 5);

    m_staticline8 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxSize(2, -1), wxLI_HORIZONTAL);
    m_staticline8->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));

    wxMainSizer->Add(m_staticline8, 0, wxEXPAND, 0);


    this->SetSizer(wxMainSizer);
    this->Layout();
}

wxDayBoxView::~wxDayBoxView() {
    detach();
}

void wxDayBoxView::update() {
    numberOfTasks = model->numberOfTasks(dateTime);
    numberOfCompletedTasks = model->numberOfCompletedTasks(dateTime);
    render();
}

void wxDayBoxView::attach() {
    model->subscribe(this);
}

void wxDayBoxView::detach() {
    model->unsubscribe(this);
}

void wxDayBoxView::render() {
    //TODO: Aggiornare labels e progressbar
    wxStatTasksLabel->SetLabel(wxString());
    wxProgressbar->SetValue((100 * numberOfCompletedTasks) / numberOfTasks);
}
