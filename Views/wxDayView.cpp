//
// Created by lucian on 20/07/19.
//

#include "wxDayView.h"
#include "MainFrame.h"


wxDayView::wxDayView(wxWindow *parent, Model *m, wxDateTime date, wxWindowID id, const wxPoint &pos, const wxSize &size,
                     long style, const wxString &name) : wxPanel(parent, id, pos, size, style, name) {
    model = m;
    controller = new DayViewController(model, parent);
    dateTime=date;
    numberOfTasks = model->numberOfTasks(dateTime);
    numberOfCompletedTasks = model->numberOfCompletedTasks(dateTime);
    for (auto iter = model->GetTasks(dateTime); iter.first != iter.second; iter.first++) {
        tasks.push_back(iter.first->second);
    }

    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

    wxBoxSizer *bSizer1;
    bSizer1 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *bSizer2;
    bSizer2 = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer *bSizer3;
    bSizer3 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *bSizer4;
    bSizer4 = new wxBoxSizer(wxHORIZONTAL);


    wxString num = dateTime.Format(wxT("%d"), wxDateTime::CET).c_str();
    m_staticText3 = new wxStaticText(this, wxID_ANY, num, wxDefaultPosition, wxSize(-1, -1), 0);
    m_staticText3->Wrap(-1);
    m_staticText3->SetFont(
            wxFont(80, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

    bSizer4->Add(m_staticText3, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    wxString day = dateTime.Format(wxT("%a"), wxDateTime::CET).c_str();
    wxString month = dateTime.Format(wxT("%b"), wxDateTime::CET).c_str();
    wxString fulldate = wxString::Format(day + "\n" + month);
    wxMonthDayLabel = new wxStaticText(this, wxID_ANY, fulldate, wxDefaultPosition, wxSize(100, 100), 0);
    wxMonthDayLabel->Wrap(-1);
    wxMonthDayLabel->SetFont(
            wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString));

    bSizer4->Add(wxMonthDayLabel, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


    bSizer3->Add(bSizer4, 1, wxALIGN_CENTER_HORIZONTAL, 5);

    wxStatTasksLabel = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 40),
                                        wxALIGN_CENTER_HORIZONTAL);
    wxStatTasksLabel->Wrap(-1);
    wxStatTasksLabel->SetFont(
            wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString));

    bSizer3->Add(wxStatTasksLabel, 0, wxALL, 5);


    bSizer2->Add(bSizer3, 1, wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);

    listBox = new wxCheckListBox(this, wxID_ANY);
    listBox->SetWindowStyle(wxLB_SINGLE);

    bSizer2->Add(listBox, 1, wxALL | wxEXPAND, 5);

    bSizer1->Add(bSizer2, 1, wxEXPAND, 5);
    wxProgressbar = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
    bSizer1->Add(wxProgressbar, 0, wxALL | wxEXPAND, 5);

    render();
    this->SetSizer(bSizer1);
    this->Layout();

    attach();

    //Link toolBar's events
    auto tool = ((MainFrame *) (parent))->GetToolPanel();
    toolPanel = tool;
    LinkEvents();
}

wxDayView::~wxDayView() {
    detach();
}

void wxDayView::update() {
    numberOfTasks = model->numberOfTasks(dateTime);
    numberOfCompletedTasks = model->numberOfCompletedTasks(dateTime);
    render();
}

void wxDayView::attach() {
    model->subscribe(this);
}

void wxDayView::detach() {
    model->unsubscribe(this);
}

void wxDayView::render() {
    listBox->Clear();
    AddTasksToGrid(dateTime);
    wxString stat = wxString::Format("%d / %d", numberOfCompletedTasks, numberOfTasks);
    wxStatTasksLabel->SetLabel(stat);
    if (numberOfTasks != 0)
        wxProgressbar->SetValue((int) ((100 * numberOfCompletedTasks) / numberOfTasks));
    else
        wxProgressbar->SetValue(0);
}

void wxDayView::AddTasksToGrid(wxDateTime date) {
    int index = 0;
    wxString tmp;
    for (auto iter = model->GetTasks(date); iter.first != iter.second; iter.first++) {
        tmp = wxString::Format("%s | %s | %s", iter.first->second.getName(), iter.first->second.getDescription(),
                               iter.first->second.getPriorityString());
        listBox->Append(tmp);
        listBox->Check(index, iter.first->second.isChecked());
        index++;
    }
}

void wxDayView::OnButtonClickEditTask(wxEvent &event) {
    auto index = listBox->GetSelection();
    if (index != -1) {
        auto ref = model->GetTasks(dateTime);
        std::advance(ref.first, index);
        controller->ShowEditTaskView(this, &dateTime, true, &(ref.first->second));
    }
}

void wxDayView::OnButtonClickAddNewTask(wxEvent &event) {
    controller->ShowEditTaskView(this, &dateTime, false);
}

void wxDayView::OnButtonClickRemoveTask(wxEvent &event) {
    int index = listBox->GetSelection();
    listBox->Delete(index);
    auto ref = model->GetTasks(dateTime);
    std::advance(ref.first, index);
    controller->RemoveTask((ref.first)->second);
}

void wxDayView::LinkEvents() {
    toolPanel->HideButtons();
    toolPanel->wxRemoveButton->Show();
    toolPanel->wxEditButton->Show();
    toolPanel->wxAddButton->Show();
    toolPanel->wxHomeButton->Show();
    toolPanel->wxRemoveDayButton->Show();
    toolPanel->wxRemoveButton->Bind(wxEVT_BUTTON, &wxDayView::OnButtonClickRemoveTask, this);
    toolPanel->wxEditButton->Bind(wxEVT_BUTTON, &wxDayView::OnButtonClickEditTask, this);
    toolPanel->wxAddButton->Bind(wxEVT_BUTTON, &wxDayView::OnButtonClickAddNewTask, this);
    toolPanel->wxHomeButton->Bind(wxEVT_BUTTON, &wxDayView::OnButtonClickGoHome, this);
    toolPanel->wxRemoveDayButton->Bind(wxEVT_BUTTON, &wxDayView::OnButtonClickDeleteDay, this);
    listBox->Bind(wxEVT_CHECKLISTBOX, &wxDayView::OnCheckedItem, this);
}

void wxDayView::OnButtonClickGoHome(wxEvent &event) {
    controller->GoHome(this);
}

void wxDayView::OnCheckedItem(wxCommandEvent &event) {
    int index = event.GetInt();
    auto ref = model->GetTasks(dateTime);
    std::advance(ref.first, index);
    controller->CheckUncheckTask((ref.first)->second);
}

void wxDayView::OnButtonClickDeleteDay(wxEvent &event) {
    controller->DeleteDay(this, dateTime);
}


