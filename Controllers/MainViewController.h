//
// Created by lucian on 19/09/19.
//

#ifndef TASKY_MAINVIEWCONTROLLER_H
#define TASKY_MAINVIEWCONTROLLER_H


#include <wx/event.h>
#include "../Models/Model.h"

class MainViewController {
public:
    MainViewController(Model* pModel,wxWindow* pFrame);

    void ShowDayView(wxWindow *pWindow, wxDateTime pDate);

    void ShowReserchView(wxWindow *pWindow);

    void AddNewDay(wxWindow *pWindow);

private:
    Model* model;
    wxWindow* frame;
};


#endif //TASKY_MAINVIEWCONTROLLER_H
