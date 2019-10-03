//
// Created by lucian on 02/10/19.
//

#include "ListTasksViewController.h"
#include "../Views/MainFrame.h"

ListTasksViewController::ListTasksViewController(Model *pModel, wxWindow *pWindow) {
    model = pModel;
    window = pWindow;
}

void ListTasksViewController::SwapOnMainView() {
    auto tmp = (MainFrame *) (window);
    tmp->SwapOnMainView();

}
