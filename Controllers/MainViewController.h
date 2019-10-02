//
// Created by lucian on 19/09/19.
//

#ifndef TASKY_MAINVIEWCONTROLLER_H
#define TASKY_MAINVIEWCONTROLLER_H


#include "../Models/Model.h"

class MainViewController {
public:
    MainViewController(Model* pModel,wxWindow* pFrame);
    void ShowDayView(wxDateTime pDate);

    void ShowReserchView();

private:
    Model* model;
    wxWindow* frame;
};


#endif //TASKY_MAINVIEWCONTROLLER_H