//
// Created by lucian on 19/09/19.
//

#include "MainViewController.h"
#include "../Views/MainFrame.h"

MainViewController::MainViewController(Model* pModel,wxWindow* pFrame) {
    model=pModel;
    frame=pFrame;
}

void MainViewController::ShowDayView(wxWindow *pWindow, wxDateTime pDate) {
    auto tmp=(MainFrame*)(frame);
    tmp->ShowDayView(pWindow, &pDate);
}

void MainViewController::ShowReserchView(wxWindow *pWindow) {
    auto tmp = (MainFrame *) (frame);
    tmp->ShowTaskListView(pWindow);
}
