//
// Created by lucian on 19/09/19.
//

#include "MainViewController.h"
#include "../Views/MainFrame.h"

MainViewController::MainViewController(Model* pModel,wxWindow* pFrame) {
    model=pModel;
    frame=pFrame;
}

void MainViewController::ShowDayView(wxDateTime pDate) {
    auto tmp=(MainFrame*)(frame);
    tmp->ShowDayView(pDate);
}

void MainViewController::ShowReserchView() {
    auto tmp = (MainFrame *) (frame);
    tmp->ShowReserchView();
}
