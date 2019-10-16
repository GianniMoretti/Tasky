//
// Created by lucian on 10/10/19.
//

#include "wxToolPanel.h"

wxToolPanel::wxToolPanel(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size) : wxPanel(parent, id,
                                                                                                            pos, size,
                                                                                                            wxTAB_TRAVERSAL) {
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    this->SetMaxSize(wxSize(-1, -1));

    wxBoxSizer *bSizer;
    bSizer = new wxBoxSizer(wxVERTICAL);

    //TODO::Creare pulsanti in base alla view
    wxBitmap *b = new wxBitmap("../ApplicationIcons/back-icon.png", wxBITMAP_DEFAULT_TYPE);
    wxBackButton = new wxBitmapButton(this, wxID_ANY, *b, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer->Add(wxBackButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    bSizer->Add(0, 0, 1, wxEXPAND, 5);

    b = new wxBitmap("../ApplicationIcons/new-icon.png", wxBITMAP_DEFAULT_TYPE);
    wxAddButton = new wxBitmapButton(this, wxID_ANY, *b, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW | 0);
    wxAddButton->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));

    bSizer->Add(wxAddButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    b = new wxBitmap("../ApplicationIcons/remove-icon.png", wxBITMAP_DEFAULT_TYPE);
    wxRemoveButton = new wxBitmapButton(this, wxID_ANY, *b, wxDefaultPosition, wxDefaultSize,
                                        wxBU_AUTODRAW | 0);
    bSizer->Add(wxRemoveButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    b = new wxBitmap("../ApplicationIcons/edit-icon.png", wxBITMAP_DEFAULT_TYPE);
    wxEditButton = new wxBitmapButton(this, wxID_ANY, *b, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer->Add(wxEditButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    b = new wxBitmap("../ApplicationIcons/research-icon.png", wxBITMAP_DEFAULT_TYPE);
    wxSwapButton = new wxBitmapButton(this, wxID_ANY, *b, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer->Add(wxSwapButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    b = new wxBitmap("../ApplicationIcons/check-icon.png", wxBITMAP_DEFAULT_TYPE);
    wxCheckUnButton = new wxBitmapButton(this, wxID_ANY, *b, wxDefaultPosition, wxDefaultSize,
                                         wxBU_AUTODRAW | 0);
    bSizer->Add(wxCheckUnButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    b = new wxBitmap("../ApplicationIcons/home-icon.png", wxBITMAP_DEFAULT_TYPE);
    wxHomeButton = new wxBitmapButton(this, wxID_ANY, *b, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer->Add(wxHomeButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    b = new wxBitmap("../ApplicationIcons/newday-icon.png", wxBITMAP_DEFAULT_TYPE);
    wxNewDayButton = new wxBitmapButton(this, wxID_ANY, *b, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer->Add(wxNewDayButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    b = new wxBitmap("../ApplicationIcons/removeday-icon.png", wxBITMAP_DEFAULT_TYPE);
    wxRemoveDayButton = new wxBitmapButton(this, wxID_ANY, *b, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer->Add(wxRemoveDayButton, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    bSizer->Fit(this);
    this->SetSizer(bSizer);
    this->Layout();
}
