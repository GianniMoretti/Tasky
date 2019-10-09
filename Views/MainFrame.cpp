//
// Created by lucian on 24/09/19.
//

#include "MainFrame.h"

MainFrame::MainFrame(Model* pModel,wxWindow *parent, wxString title, wxWindowID id, const wxPoint &pos, const wxSize &size)
:wxFrame(parent,id,title,pos,size){
    model=pModel;
    //TODO:Controllare perchè tasksView non è null pur non essendo inizializzata
    tasksView = nullptr;
    this->SetMinSize(wxSize(1000, 700));
    auto sizer=new wxBoxSizer(wxVERTICAL);

    mainView = new MainView(pModel,this,wxID_ANY, wxPoint(0, 0), wxSize(1200, 700));
    sizer->Add(mainView);

    this->SetSizer(sizer);
    this->Show(true);
    this->Layout();
}

void MainFrame::ShowDayView(wxDateTime pTime) {
    mainView->Hide();
    dayView=new wxDayView(this,model,pTime);
    (wxBoxSizer*)this->GetSizer()->Add(dayView);
    dayView->Show(true);
    this->Layout();
}

void MainFrame::SwapOnTaskListView() {
    if (tasksView == nullptr) {
        tasksView = new ListTasksView(this, model);
        (wxBoxSizer *) this->GetSizer()->Add(tasksView);
    }
    mainView->Hide();
    tasksView->setTaskList(model->getTaskList());
    tasksView->Show(true);
    this->Layout();
}

void MainFrame::SwapOnMainView() {
    tasksView->Hide();
    mainView->Show();
}

void MainFrame::ShowEditTaskView(wxDateTime *pTime, bool editMode, Task *pTask) {
    dayView->Hide();
    editTaskView = new wxEditTaskView(this, model, pTime, editMode, pTask);
    (wxBoxSizer *) this->GetSizer()->Add(editTaskView);
}

void MainFrame::BackToDayView() {
    editTaskView->Hide();
    dayView->Show();
}
