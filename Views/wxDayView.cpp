//
// Created by lucian on 20/07/19.
//

#include "wxDayView.h"
#include "MainFrame.h"


wxDayView::wxDayView(wxWindow *parent, Model *m, wxDateTime date, wxWindowID id, const wxPoint &pos, const wxSize &size,
                     long style, const wxString &name) : wxPanel(parent, id, pos, wxSize(1000, 900), style, name) {
    model = m;
    controller = new DayViewController(model, parent);
    dateTime=date;
    numberOfTasks = model->numberOfTasks(dateTime);
    numberOfCompletedTasks = model->numberOfCompletedTasks(dateTime);
    for (auto iter = model->GetTasks(dateTime); iter.first != iter.second; iter.first++) {
        tasks.push_back(iter.first->second);
    }

    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));

    wxBoxSizer *wxMainSizer;
    wxMainSizer = new wxBoxSizer(wxVERTICAL);

    wxMainSizer->SetMinSize(wxSize(-1, -1));
    wxTopPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1, 20), wxTAB_TRAVERSAL);
    wxTopPanel->SetFont(
            wxFont(wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false,
                   wxEmptyString));
    wxTopPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVECAPTION));
    wxTopPanel->SetMaxSize(wxSize(-1, -1));

    wxMainSizer->Add(wxTopPanel, 1, wxEXPAND, 5);

    wxBoxSizer *wxDetailsSizer;
    wxDetailsSizer = new wxBoxSizer(wxHORIZONTAL);

    wxDetailsSizer->SetMinSize(wxSize(-1, -1));
    wxBoxSizer *wxDayInfoOperetionSizer;
    wxDayInfoOperetionSizer = new wxBoxSizer(wxVERTICAL);


    wxDayInfoOperetionSizer->Add(0, 0, 1, wxEXPAND, 5);

    wxBoxSizer *wxTopLabelSizer;
    wxTopLabelSizer = new wxBoxSizer(wxHORIZONTAL);

    wxString num = dateTime.Format(wxT("%d"), wxDateTime::CET).c_str();
    m_staticText3 = new wxStaticText(this, wxID_ANY, num, wxDefaultPosition, wxSize(-1, -1), 0);
    m_staticText3->Wrap(-1);
    m_staticText3->SetFont(
            wxFont(80, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString));

    wxTopLabelSizer->Add(m_staticText3, 1, wxALL | wxEXPAND | wxALIGN_CENTER_VERTICAL, 5);

    wxString day = dateTime.Format(wxT("%a"), wxDateTime::CET).c_str();
    wxString month = dateTime.Format(wxT("%b"), wxDateTime::CET).c_str();
    wxString fulldate = wxString::Format(day + "\n" + month);
    wxMonthDayLabel = new wxStaticText(this, wxID_ANY, fulldate, wxDefaultPosition, wxSize(100, 100), 0);
    wxMonthDayLabel->Wrap(-1);
    wxMonthDayLabel->SetFont(
            wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString));

    wxTopLabelSizer->Add(wxMonthDayLabel, 1, wxALIGN_CENTER_VERTICAL | wxEXPAND | wxTOP, 30);


    wxDayInfoOperetionSizer->Add(wxTopLabelSizer, 1, wxEXPAND, 5);


    wxDayInfoOperetionSizer->Add(0, 0, 1, wxEXPAND, 5);

    wxBoxSizer *wxButtonSizer;
    wxButtonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxStatTasksLabel = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 40),
                                        wxALIGN_CENTER_HORIZONTAL);
    wxStatTasksLabel->Wrap(-1);
    wxStatTasksLabel->SetFont(
            wxFont(18, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString));

    wxButtonSizer->Add(wxStatTasksLabel, 1, wxALIGN_BOTTOM, 10);


    wxDayInfoOperetionSizer->Add(wxButtonSizer, 1, wxALIGN_BOTTOM | wxEXPAND, 5);


    wxDetailsSizer->Add(wxDayInfoOperetionSizer, 1, wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);

    wxStaticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL);
    wxStaticline1->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    wxStaticline1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

    wxDetailsSizer->Add(wxStaticline1, 1, wxALL | wxEXPAND, 0);

    wxBoxSizer *bSizer8;
    bSizer8 = new wxBoxSizer(wxVERTICAL);

    listBox = new wxCheckListBox(this, wxID_ANY);

    wxBoxSizer *wxTasksSizer;
    wxTasksSizer = new wxBoxSizer(wxVERTICAL);

    wxTasksSizer->SetMinSize(wxSize(-1, -1));

    wxTasksSizer->Fit(listBox);
    bSizer8->Add(listBox, 1, wxALL | wxEXPAND, 10);

    wxBoxSizer *bSizer4;
    bSizer4 = new wxBoxSizer(wxHORIZONTAL);

    //Link toolBar's events
    auto tool = ((MainFrame *) (parent))->GetToolPanel();
    toolPanel = tool;
    LinkEvents();


    bSizer8->Add(bSizer4, 1, wxALIGN_CENTER | wxLEFT , 5);


    wxDetailsSizer->Add(bSizer8, 1, wxEXPAND, 5);


    wxMainSizer->Add(wxDetailsSizer, 1, wxEXPAND, 5);

    wxStaticline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    wxStaticline2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));

    wxMainSizer->Add(wxStaticline2, 1, wxEXPAND | wxALL, 0);

    wxProgressbar = new wxGauge(this, wxID_ANY, 100, wxDefaultPosition, wxSize(1000, 10), wxGA_HORIZONTAL);
    wxMainSizer->Add(wxProgressbar, 1, wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxBOTTOM | wxRIGHT | wxLEFT, 5);

    render();
    this->SetSizer(wxMainSizer);
    this->Layout();

    attach();
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
    auto ref = model->GetTasks(dateTime);
    std::advance(ref.first, index);
    controller->ShowEditTaskView(this, &dateTime, true, &(ref.first->second));
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

void wxDayView::OnButtonClickGoBack(wxEvent &event) {
    controller->BackToHomeView(this);
}

void wxDayView::LinkEvents() {
    toolPanel->HideButtons();
    toolPanel->wxRemoveButton->Show();
    toolPanel->wxEditButton->Show();
    toolPanel->wxAddButton->Show();
    toolPanel->wxBackButton->Show();
    toolPanel->wxHomeButton->Show();
    toolPanel->wxRemoveButton->Bind(wxEVT_BUTTON, &wxDayView::OnButtonClickRemoveTask, this);
    toolPanel->wxEditButton->Bind(wxEVT_BUTTON, &wxDayView::OnButtonClickEditTask, this);
    toolPanel->wxAddButton->Bind(wxEVT_BUTTON, &wxDayView::OnButtonClickAddNewTask, this);
    toolPanel->wxBackButton->Bind(wxEVT_BUTTON, &wxDayView::OnButtonClickGoBack, this);
    toolPanel->wxHomeButton->Bind(wxEVT_BUTTON, &wxDayView::OnButtonClickGoHome, this);
}

void wxDayView::OnButtonClickGoHome(wxEvent &event) {
    controller->GoHome(this);
}


