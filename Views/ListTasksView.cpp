//
// Created by giannimoretti on 25/09/19.
//

#include "ListTasksView.h"
#include "MainFrame.h"

ListTasksView::ListTasksView( wxWindow* parent,Model* pModel, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
    model=pModel;
    controller = new ListTasksViewController(model, parent);

    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer( wxVERTICAL );

    wxCtrlText = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    wxCtrlText->SetMinSize(wxSize(250, -1));

    bSizer1->Add(wxCtrlText, 0, wxALIGN_CENTER_HORIZONTAL | wxALL, 5);

    listBox = new wxCheckListBox(this, wxID_ANY);
    bSizer1->Add(listBox, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxEXPAND, 5);

    FillCheckBoxList(model->getTaskList(onlyUnchecked));
    onlyUnchecked = !onlyUnchecked;

    auto tool = ((MainFrame *) (parent))->GetToolPanel();
    toolPanel = tool;
    LinkEvents();

    bSizer1->Fit(this);
    this->SetSizer( bSizer1 );
    this->Layout();
}

ListTasksView::~ListTasksView()
{
}

void ListTasksView::FillCheckBoxList(std::list<Task *> list) {
    listBox->Clear();
    int index = 0;
    wxString tmp;
    for (auto task:list) {
        tmp = wxString::Format("%s | %s | %s", task->getName(), task->getDescription(),
                               task->getPriorityString());
        listBox->Append(tmp);
        listBox->Check(index, task->isChecked());
        index++;
    }
}

void ListTasksView::OnButtonClickHome(wxEvent &event) {
    controller->GoHome(this);
}

void ListTasksView::LinkEvents() {
    //TODO::Bind dei eventi
    toolPanel->HideButtons();
    toolPanel->wxHomeButton->Show();
    toolPanel->wxEditButton->Show();
    toolPanel->wxCheckUnButton->Show();
    toolPanel->wxEditButton->Bind(wxEVT_BUTTON, &ListTasksView::OnButtonClickEditTask, this);
    toolPanel->wxCheckUnButton->Bind(wxEVT_BUTTON, &ListTasksView::OnButtonClickChecked, this);
    toolPanel->wxHomeButton->Bind(wxEVT_BUTTON, &ListTasksView::OnButtonClickHome, this);
}

void ListTasksView::OnButtonClickChecked(wxEvent &event) {
    FillCheckBoxList(model->getTaskList(onlyUnchecked));
    onlyUnchecked = !onlyUnchecked;
}

void ListTasksView::OnButtonClickEditTask(wxEvent &event) {
    auto list = model->getTaskList(!onlyUnchecked);
    int index = listBox->GetSelection();
    auto iter = list.begin();
    std::advance(iter, index);
    controller->EditTask(this, *iter);
}


