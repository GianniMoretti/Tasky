//
// Created by lucian on 19/09/19.
//

#ifndef TASKY_DAYVIEWCONTROLLER_H
#define TASKY_DAYVIEWCONTROLLER_H


#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

#include "../Models/Model.h"


class DayViewController {

public:
    DayViewController(Model *pModel, wxWindow *pWindow);

private:
    Model *model;
    wxWindow *window;
};


#endif //TASKY_DAYVIEWCONTROLLER_H
