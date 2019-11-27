//
// Created by lucian on 21/07/19.
//

#include "wxEditTaskView.h"


wxEditTaskView::wxEditTaskView(wxWindow *parent, Model *model, wxDateTime *pTime, bool editMode, Task *pTask,
                               bool isDayViewLast,
                               const wxPoint &pos, const wxSize &size, long style, const wxString &name, wxWindowID id)
        : wxPanel(parent, id, pos, size,
                                                                                               style, name) {
    this->model = model;
    task = pTask;
    this->isDayViewLast = isDayViewLast;
    date = pTime;
    this->editMode = editMode;
    controller = new EditTaskViewController(model, parent);

    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *wxMainSizer;
    wxMainSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *wxTopSizer;
    wxTopSizer = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer *wxNameSizer;
    wxNameSizer = new wxBoxSizer(wxHORIZONTAL);

    m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("Name"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText1->Wrap(-1);
    wxNameSizer->Add(m_staticText1, 0, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);

    wxNameTxt = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(200, -1), 0);
    wxNameSizer->Add(wxNameTxt, 0, wxALL | wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);


    wxTopSizer->Add(wxNameSizer, 1, wxALIGN_CENTER | wxBOTTOM | wxTOP, 5);

    wxBoxSizer *wxPrioritySizer;
    wxPrioritySizer = new wxBoxSizer(wxHORIZONTAL);

    m_staticText3 = new wxStaticText(this, wxID_ANY, wxT("Priority"), wxDefaultPosition, wxSize(-1, -1), 0);
    m_staticText3->Wrap(-1);
    wxPrioritySizer->Add(m_staticText3, 0, wxALIGN_CENTER | wxALL, 5);

    wxString wxPriorityCmboxChoices[] = {wxT("High"), wxT("Medium"), wxT("Low")};
    int wxPriorityCmboxNChoices = sizeof(wxPriorityCmboxChoices) / sizeof(wxString);
    wxPriorityCmbox = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPriorityCmboxNChoices,
                                   wxPriorityCmboxChoices, 0);
    wxPriorityCmbox->SetSelection(2);
    wxPrioritySizer->Add(wxPriorityCmbox, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);


    wxTopSizer->Add(wxPrioritySizer, 1, wxALIGN_CENTER_HORIZONTAL | wxSHAPED | wxALIGN_CENTER_VERTICAL, 5);

    wxBoxSizer *bSizer7;
    bSizer7 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText4 = new wxStaticText(this, wxID_ANY, wxT("Date"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText4->Wrap(-1);
    bSizer7->Add(m_staticText4, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_datePicker2 = new wxDatePickerCtrl(this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize,
                                         wxDP_DEFAULT);
    bSizer7->Add(m_datePicker2, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


    wxTopSizer->Add(bSizer7, 1, wxEXPAND, 5);


    wxMainSizer->Add(wxTopSizer, 0, wxEXPAND | wxSHAPED | wxALIGN_CENTER_HORIZONTAL, 5);

    wxBoxSizer *wxDescriptionSizer;
    wxDescriptionSizer = new wxBoxSizer(wxVERTICAL);

    m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("Description"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText2->Wrap(-1);
    wxDescriptionSizer->Add(m_staticText2, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

    wxDescriptionTxt = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(5000, 200), wxTE_MULTILINE);
    wxDescriptionSizer->Add(wxDescriptionTxt, 1, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


    wxMainSizer->Add(wxDescriptionSizer, 1, wxALL | wxEXPAND, 5);

    wxBoxSizer *wxButtonSizer;
    wxButtonSizer = new wxBoxSizer(wxHORIZONTAL);

    wxSaveButton = new wxButton(this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0);
    wxButtonSizer->Add(wxSaveButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    wxCancelButton = new wxButton(this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
    wxButtonSizer->Add(wxCancelButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);
    wxCancelButton->Bind(wxEVT_BUTTON, &wxEditTaskView::OnButtonClickCancelOperation, this);


    wxMainSizer->Add(wxButtonSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5);


    this->SetSizer(wxMainSizer);
    this->Layout();

    this->Centre(wxBOTH);

    //event salvataggio task in base se è da modificare oppure nuovo
    if (editMode) {
        //Scrivere i dati nelle caselle e linkare il pulsante save al metodo saveEditTask
        wxNameTxt->SetValue(task->getName());
        switch (task->getPriority()) {
            case Priority::High :
                wxPriorityCmbox->SetSelection(2);
                break;

            case Priority::Medium :
                wxPriorityCmbox->SetSelection(1);
                break;

            case Priority::Low :
                wxPriorityCmbox->SetSelection(0);
                break;
        }
        wxDescriptionTxt->SetValue(task->getDescription());
        m_datePicker2->SetValue(task->getDate());
        wxSaveButton->Bind(wxEVT_BUTTON, &wxEditTaskView::OnButtonClickSaveEditTask, this);

    } else {
        //Lasciare vuote le caselle e linkare i pulsante save a saveNewTask
        if (isDayViewLast) {
            m_staticText4->Hide();
            m_datePicker2->Hide();
        } else
            date = new wxDateTime(wxDateTime::Now().GetDateOnly());

        m_datePicker2->SetValue(*date);
        wxSaveButton->Bind(wxEVT_BUTTON, &wxEditTaskView::OnButtonClickSaveNewTask, this);
    }

    this->SetSizer(wxMainSizer);
    this->Layout();

    attach();
}

wxEditTaskView::~wxEditTaskView() {
    detach();
}

void wxEditTaskView::update() {

}

void wxEditTaskView::attach() {
    model->subscribe(this);
}

void wxEditTaskView::detach() {
    model->unsubscribe(this);
}

void wxEditTaskView::OnButtonClickSaveEditTask(wxEvent &event) {
    //Call al controller per salvare un task editato
    auto task = GetTask();
    controller->SaveEditTask(this, task, *(this->task), isDayViewLast);
}

void wxEditTaskView::OnButtonClickSaveNewTask(wxEvent &event) {
//Call al controller per salvare un nuovo task
    auto task = GetTask();
    controller->SaveNewTask(this, task, isDayViewLast);
}

Task wxEditTaskView::GetTask() {
    auto name = wxNameTxt->GetValue();
    auto priority = wxPriorityCmbox->GetCurrentSelection();
    auto description = wxDescriptionTxt->GetValue();
    auto date = m_datePicker2->GetValue();
    return Task(name.ToStdString(), description.ToStdString(), date, (Priority) (priority));
}

void wxEditTaskView::OnButtonClickCancelOperation(wxEvent &event) {
    controller->CancelOperation(this, editMode, isDayViewLast);
}
