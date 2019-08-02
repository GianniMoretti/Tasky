//
// Created by giannimoretti on 13/06/19.
//

#include "MainView.h"


MainView::MainView(Model *model, const wxString &title, const wxPoint &pos, const wxSize &size)
        : wxFrame(nullptr, wxID_ANY, title, pos, size) {

    this->model = model;

    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *wxMainSizer;
    wxMainSizer = new wxBoxSizer(wxVERTICAL);

    wxButtonSwap = new wxButton(this, wxID_ANY, wxT("!"), wxDefaultPosition, wxDefaultSize, 0);
    wxMainSizer->Add(wxButtonSwap, 0, wxALL | wxALIGN_RIGHT, 5);

    wxGridSizer *GridSizer;
    GridSizer = new wxGridSizer(4, 7, 0, 0);
    FillGridSizer(GridSizer);


    wxMainSizer->Add(GridSizer, 1, wxEXPAND | wxTOP, 5);


    this->SetSizer(wxMainSizer);
    this->Layout();

    this->Centre(wxBOTH);
    attach();
}

void MainView::update() {

}

MainView::~MainView() {
    detach();
    for (auto itr = wxDayBoxViewsList.begin(); itr != wxDayBoxViewsList.end(); itr++) {
        delete (*itr);
    }
    wxDayBoxViewsList.clear();
}

void MainView::attach() {
    model->subscribe(this);
}

void MainView::detach() {
    model->unsubscribe(this);
}

void MainView::FillGridSizer(wxGridSizer *pSizer) {
    std::list<wxDateTime> keys = model->GetKeysOnce();
    //TODO:sort della lista
    //keys.sort(dateCmp);
    for (auto &key : keys) {
        wxDayBoxView *box = new wxDayBoxView(model, key, this);
        pSizer->Add(box);
        wxDayBoxViewsList.push_back(box);
    }
}

