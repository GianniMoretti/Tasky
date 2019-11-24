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

    bSizer1->Add(wxCtrlText, 0, wxALIGN_CENTER_VERTICAL | wxALIGN_CENTER_HORIZONTAL, 5);

    listBox = new wxCheckListBox(this, wxID_ANY);
    bSizer1->Add(listBox, 1, wxALL | wxEXPAND, 5);

    auto tool = ((MainFrame *) (parent))->GetToolPanel();
    toolPanel = tool;
    LinkEvents();

    update();
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
        tmp = wxString::Format(
                "\n\n\n\nDate:\t%s\t\tName:\t%s\n\n\t\t\t\t\t\tDescription:\t%s\n\n\t\t\t\t\t\tPriority:\t%s",
                task->getDate().Format(wxT("%x"), wxDateTime::CET).c_str(), task->getName(), task->getDescription(),
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
    toolPanel->HideButtons();
    toolPanel->wxHomeButton->Show();
    toolPanel->wxEditButton->Show();
    toolPanel->wxCheckUnButton->Show();
    toolPanel->wxEditButton->Bind(wxEVT_BUTTON, &ListTasksView::OnButtonClickEditTask, this);
    toolPanel->wxCheckUnButton->Bind(wxEVT_BUTTON, &ListTasksView::OnButtonClickChecked, this);
    toolPanel->wxHomeButton->Bind(wxEVT_BUTTON, &ListTasksView::OnButtonClickHome, this);
    wxCtrlText->Bind(wxEVT_TEXT, &ListTasksView::OnTextCtrlChanged, this);
}

void ListTasksView::OnTextCtrlChanged(wxCommandEvent &event) {
    update();
}

void ListTasksView::update() {
    taskList = model->researchTasks(wxCtrlText->GetValue(), onlyUnchecked);
    FillCheckBoxList(taskList);
}

void ListTasksView::attach() {
    model->subscribe(this);
}

void ListTasksView::detach() {
    model->unsubscribe(this);
}

void ListTasksView::OnButtonClickChecked(wxEvent &event) {
    onlyUnchecked = !onlyUnchecked;
    update();
}

void ListTasksView::OnButtonClickEditTask(wxEvent &event) {
    int index = listBox->GetSelection();
    if (index != -1) {
        auto iter = taskList.begin();
        std::advance(iter, index);
        controller->EditTask(this, *iter);
    }
}


