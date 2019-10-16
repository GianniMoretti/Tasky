//
// Created by lucian on 24/09/19.
//

#include "MainFrame.h"

MainFrame::MainFrame(Model* pModel,wxWindow *parent, wxString title, wxWindowID id, const wxPoint &pos, const wxSize &size)
:wxFrame(parent,id,title,pos,size){
    model=pModel;

    //TODO:Controllare perchè tasksView non è null pur non essendo inizializzata
    tasksView = nullptr;
    sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer2 = new wxBoxSizer(wxHORIZONTAL);
    toolPanel = new wxToolPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);

    mainView = new MainView(pModel,this,wxID_ANY, wxPoint(0, 0), wxSize(1200, 700));
    sizer2->Add(mainView);
    sizer->Add(sizer2);

    sizer->Add(toolPanel, wxEXPAND | wxALL, 5);

    sizer->Fit(this);
    this->SetSizer(sizer);
    this->Show(true);
    this->SetMaxSize(this->GetSize());
    this->SetMinSize(this->GetSize());
    this->Layout();
}

void MainFrame::ShowDayView(wxWindow *currentView, wxDateTime *pTime) {
    currentView->Hide();
    if (pTime == nullptr)
        dayView->Show();
    else {
        dayView = new wxDayView(this, model, *pTime);
        sizer2->Add(dayView);
    }

    dayView->Show(true);
    dayView->LinkEvents();
    this->Layout();
}

void MainFrame::ShowTaskListView(wxWindow *currentView) {
    currentView->Hide();
    if (tasksView == nullptr) {
        tasksView = new ListTasksView(this, model);
        sizer2->Add(tasksView);
    }
    mainView->Hide();
    tasksView->setTaskList(model->getTaskList());
    tasksView->Show(true);
    tasksView->LinkEvents();

    this->Layout();
}

void MainFrame::ShowMainView(wxWindow *currentView) {
    currentView->Hide();
    mainView->Show();
    mainView->LinkEvents();
    this->Layout();
}

void MainFrame::ShowEditTaskView(wxWindow *currentView, wxDateTime *pTime, bool editMode, Task *pTask) {
    currentView->Hide();
    editTaskView = new wxEditTaskView(this, model, pTime, editMode, pTask);
    sizer2->Add(editTaskView);
    editTaskView->Show();
    this->Layout();
}

void MainFrame::GoBack(wxWindow *pWindow, int currentIndex) {

    switch (currentIndex - 1) {
        case 0:
            ShowMainView(pWindow);
            break;
        case -2:
            ShowMainView(pWindow);
            break;
        case 1:
            ShowDayView(pWindow);
            break;
        case 2:
            ShowTaskListView(pWindow);
            break;
    }
}

wxToolPanel *MainFrame::GetToolPanel() {
    return toolPanel;
}


