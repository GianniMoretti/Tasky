//
// Created by giannimoretti on 13/06/19.
//

#include "MainView.h"


MainView::MainView(Model *model,wxWindow*parent,wxWindowID id, const wxPoint &pos, const wxSize &size)
        : wxPanel(parent, id, pos, size) {

    this->model = model;
    controller=new MainViewController(this->model,parent);

    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *wxMainSizer;
    wxMainSizer = new wxBoxSizer(wxVERTICAL);

    wxButtonSwap = new wxButton(this, wxID_ANY, wxT("!"), wxDefaultPosition, wxDefaultSize, 0);
    //Crezione evento pulsante swap per passare alla view dell ricerca
    wxButtonSwap->Bind(wxEVT_BUTTON, &MainView::OnButtonClickSwapView, this);
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
    for (auto &key : keys) {
        wxDayBoxView *box = new wxDayBoxView(model,controller, key, this);
        pSizer->Add(box);
        wxDayBoxViewsList.push_back(box);
    }
}

void MainView::OnButtonClickSwapView(wxEvent &event) {
    controller->ShowReserchView();
}

