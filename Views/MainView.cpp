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

    wxBitmap *b = new wxBitmap("../ApplicationIcons/arrow-left-icon.png", wxBITMAP_DEFAULT_TYPE);
    wxLeftButton = new wxBitmapButton(this, wxID_ANY, *b, wxDefaultPosition, wxDefaultSize,
                                      wxBU_AUTODRAW | 0);
    bSizer1->Add(wxLeftButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    gSizer4 = new wxGridSizer(4, 7, 0, 0);
    renderGrid();


    bSizer1->Add(gSizer4, 1, wxEXPAND, 5);

    b = new wxBitmap("../ApplicationIcons/arrow-right-icon.png", wxBITMAP_DEFAULT_TYPE);
    wxRightButton = new wxBitmapButton(this, wxID_ANY, *b, wxDefaultPosition, wxDefaultSize,
                                       wxBU_AUTODRAW | 0);
    bSizer1->Add(wxRightButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    auto tool = ((MainFrame *) (parent))->GetToolPanel();
    toolPanel = tool;
    LinkEvents();

    this->SetSizer(bSizer1);
    this->Layout();
    this->Show();
    attach();
}

void MainView::update() {
    renderGrid();
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
    for (auto &box : wxDayBoxViewsList) {
        pSizer->Add(box);
    }
    this->Layout();
}

void MainView::OnButtonClickSwapView(wxEvent &event) {
    controller->ShowReserchView(this);
}

void MainView::LinkEvents() {
    toolPanel->HideButtons();
    toolPanel->wxSwapButton->Show();
    toolPanel->wxNewDayButton->Show();
    toolPanel->wxRemoveDayButton->Show();
    toolPanel->wxSwapButton->Bind(wxEVT_BUTTON, &MainView::OnButtonClickSwapView, this);
    wxLeftButton->Bind(wxEVT_BUTTON, &MainView::OnButtonClickLeftPage, this);
    wxRightButton->Bind(wxEVT_BUTTON, &MainView::OnButtonClickRightPage, this);
}

void MainView::OnButtonClickNewDay(wxEvent &event) {

}

void MainView::OnButtonClickLeftPage(wxEvent &event) {
    if (currentPage == 0)
        return;

    currentPage -= 1;
    renderGrid();
}

void MainView::OnButtonClickRightPage(wxEvent &event) {
    int numOfPage = (int) (model->GetKeysOnce().size() / boxForPage);
    if (currentPage == numOfPage)
        return;

    currentPage += 1;
    renderGrid();
}

void MainView::renderGrid() {
    //FIXME:Non funziona .
    if (model->GetKeysOnce().size() % boxForPage == 0)
        currentPage -= 1;

    int init = (currentPage * boxForPage);

    for (auto itr = wxDayBoxViewsList.begin(); itr != wxDayBoxViewsList.end(); itr++) {
        delete (*itr);
    }
    wxDayBoxViewsList.clear();

    int count = 0;
    std::list<wxDateTime> keys = model->GetKeysOnce();
    int size = model->GetKeysOnce().size();

    for (auto &key : keys) {
        if (count < init) {
            count++;
            continue;
        } else if (count >= init && count < init + 28 && count < size) {
            wxDayBoxView *box = new wxDayBoxView(model, controller, key, this);
            wxDayBoxViewsList.push_back(box);
        } else
            break;

        count++;
    }

    gSizer4->Clear();
    FillGridSizer(gSizer4);
}

