//
// Created by lucian on 21/07/19.
//

#include "wxEditTaskView.h"


wxEditTaskView::wxEditTaskView(wxWindow *parent, Model *model, Task task, wxWindowID id, const wxPoint &pos,
                               const wxSize &size, long style, const wxString &name) : wxPanel(parent, id, pos, size,
                                                                                               style, name) {
    this->model = model;

    wxBoxSizer *wxMainSizer;
    wxMainSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *wxTopSizer;
    wxTopSizer = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer *wxNameSizer;
    wxNameSizer = new wxBoxSizer(wxHORIZONTAL);

    m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText1->Wrap(-1);
    wxNameSizer->Add(m_staticText1, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);

    wxNameTxt = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0);
    wxNameSizer->Add(wxNameTxt, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);


    wxTopSizer->Add(wxNameSizer, 1, wxALIGN_CENTER | wxBOTTOM | wxTOP, 5);

    wxBoxSizer *wxPrioritySizer;
    wxPrioritySizer = new wxBoxSizer(wxHORIZONTAL);

    m_staticText3 = new wxStaticText(this, wxID_ANY, wxT("Priority"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_staticText3->Wrap(-1);
    wxPrioritySizer->Add(m_staticText3, 0, wxALIGN_CENTER | wxALL, 5);

    wxString wxPriorityCmboxChoices[] = {wxT("Low"), wxT("Medium"), wxT("High")};
    int wxPriorityCmboxNChoices = sizeof(wxPriorityCmboxChoices) / sizeof(wxString);
    wxPriorityCmbox = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPriorityCmboxNChoices,
                                   wxPriorityCmboxChoices, 0);
    wxPriorityCmbox->SetSelection(2);
    wxPrioritySizer->Add(wxPriorityCmbox, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);


    wxTopSizer->Add(wxPrioritySizer, 1, wxALIGN_CENTER_HORIZONTAL | wxSHAPED, 5);


    wxMainSizer->Add(wxTopSizer, 0, wxEXPAND | wxSHAPED | wxALIGN_CENTER_HORIZONTAL, 5);

    wxBoxSizer *wxDescriptionSizer;
    wxDescriptionSizer = new wxBoxSizer(wxVERTICAL);

    m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("Description"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText2->Wrap(-1);
    wxDescriptionSizer->Add(m_staticText2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    wxDescriptionTxt = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(5000, 200),
                                      wxTE_MULTILINE);
    wxDescriptionSizer->Add(wxDescriptionTxt, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


    wxMainSizer->Add(wxDescriptionSizer, 0, 0, 5);

    wxBoxSizer *wxButtonSizer;
    wxButtonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxSaveButton = new wxButton(this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0);
    wxButtonSizer->Add(wxSaveButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    wxCancelButton = new wxButton(this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
    wxButtonSizer->Add(wxCancelButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


    wxMainSizer->Add(wxButtonSizer, 1, wxALIGN_CENTER_HORIZONTAL, 5);


    this->SetSizer(wxMainSizer);
    this->Layout();
}

wxEditTaskView::~wxEditTaskView() {
    detach();
}

void wxEditTaskView::update() {

}

void wxEditTaskView::attach() {
    model->subscribe(this);
}

void wxEditTaskView::detach() {
    model->unsubscribe(this);
}
