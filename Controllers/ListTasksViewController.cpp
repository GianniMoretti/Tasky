//
// Created by lucian on 02/10/19.
//

#include "ListTasksViewController.h"
#include "../Views/MainFrame.h"

ListTasksViewController::ListTasksViewController(Model *pModel, wxWindow *pWindow) {
    model = pModel;
    window = pWindow;
}

void ListTasksViewController::SwapOnMainView(wxWindow *pView) {
    auto tmp = (MainFrame *) (window);
    tmp->ShowMainView(pView);

}

void ListTasksViewController::GoHome(wxWindow *pView) {
    auto tmp = (MainFrame *) (window);
    tmp->ShowMainView(pView);
}

void ListTasksViewController::GoBack(wxWindow *pView) {
    auto tmp = (MainFrame *) (window);
    tmp->GoBack(pView, -1);
}
