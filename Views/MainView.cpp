//
// Created by giannimoretti on 13/06/19.
//

#include "MainView.h"
#include "MainFrame.h"


MainView::MainView(Model *model,wxWindow*parent,wxWindowID id, const wxPoint &pos, const wxSize &size)
        : wxPanel(parent, id, pos, size) {

    this->model = model;
    controller=new MainViewController(this->model,parent);

    this->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DDKSHADOW));
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));

    wxBoxSizer *bSizer1;
    bSizer1 = new wxBoxSizer(wxHORIZONTAL);

    wxLeftButton = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer1->Add(wxLeftButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    gSizer4 = new wxGridSizer(4, 7, 0, 0);
    FillGridSizer(gSizer4);


    bSizer1->Add(gSizer4, 1, wxEXPAND, 5);

    wxRightButton = new wxBitmapButton(this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize,
                                       wxBU_AUTODRAW | 0);
    bSizer1->Add(wxRightButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    //TODO::Bind dei eventi
    auto toolPanel = ((MainFrame *) (parent))->GetToolPanel();
    toolPanel->wxSwapButton->Bind(wxEVT_BUTTON, &MainView::OnButtonClickSwapView, this);
    this->SetSizer(bSizer1);
    this->Layout();
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

