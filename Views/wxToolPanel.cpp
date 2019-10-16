//
// Created by lucian on 10/10/19.
//

#include "wxToolPanel.h"

wxToolPanel::wxToolPanel(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size) : wxPanel(parent, id,
                                                                                                            pos, size,
                                                                                                            wxTAB_TRAVERSAL) {
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    this->SetMaxSize(wxSize(80, -1));

    wxBoxSizer *bSizer;
    bSizer = new wxBoxSizer(wxVERTICAL);


    wxBackButton = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer->Add(wxBackButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


    bSizer->Add(0, 0, 1, wxEXPAND, 5);

    wxAddButton = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);
    wxAddButton->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));

    bSizer->Add(wxAddButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    wxRemoveButton = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize,
                                        wxBU_AUTODRAW | 0);
    bSizer->Add(wxRemoveButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    wxEditButton = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer->Add(wxEditButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    wxSwapButton = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer->Add(wxSwapButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    wxCheckUnButton = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize,
                                         wxBU_AUTODRAW | 0);
    bSizer->Add(wxCheckUnButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    m_bpButton21 = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer->Add(m_bpButton21, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    bSizer->Add(0, 0, 1, wxEXPAND, 5);

    wxHomeButton = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer->Add(wxHomeButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    bSizer->Fit(this);
    this->SetSizer(bSizer);
    this->Layout();
}
