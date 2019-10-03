//
// Created by lucian on 02/10/19.
//

#ifndef TASKY_LISTTASKSVIEWCONTROLLER_H
#define TASKY_LISTTASKSVIEWCONTROLLER_H

#ifndef WX_PRECOMP

#include <wx/wx.h>

#endif

#include "../Models/Model.h"


class ListTasksViewController {
private:
    Model *model;
    wxWindow *window;
public:
    ListTasksViewController(Model *pModel, wxWindow *pWindow);

    void SwapOnMainView();
};


#endif //TASKY_LISTTASKSVIEWCONTROLLER_H
