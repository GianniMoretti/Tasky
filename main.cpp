#include <iostream>

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#include "Views/MainView.h"
#include "Models/Model.h"
#include "FileManagement/XMLFileRepository.h"

#endif

class Tasky : public wxApp {
public:
    bool OnInit() override;
};

//potrebbe dare eccezzione da catturare
wxIMPLEMENT_APP(Tasky);

bool Tasky::OnInit() {
    //TODO: controllo del percorso e se non esiste crearlo
    std::string filepath = "";


    Model model;

    //TODO: aggiungere try per le eccezioni all'interno di loaddatafromfile
    XMLFileRepository fileRepository(filepath, &model);
    model.setTaskMap(fileRepository.loadDataFromFile());

    MainView *mainView = new MainView("Tasky", wxPoint(50, 50), wxSize(500, 500));
    mainView->Show(true);
    return true;
}

