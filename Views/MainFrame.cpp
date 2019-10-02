//
// Created by lucian on 24/09/19.
//

#include "MainFrame.h"

MainFrame::MainFrame(Model* pModel,wxWindow *parent, wxString title, wxWindowID id, const wxPoint &pos, const wxSize &size)
:wxFrame(parent,id,title,pos,size){
    model=pModel;
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

void MainFrame::ShowReserchView() {
    //TODO::Appena gianni fa il push della view va fatta la creazione della view e il hide della mainView.

}
