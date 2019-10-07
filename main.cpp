#include <iostream>

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#include "Views/MainView.h"
#include "Models/Model.h"
#include "FileManagement/XMLFileRepository.h"
#include "Views/MainFrame.h"

#endif

class Tasky : public wxApp {
public:
    bool OnInit() override;
};

//potrebbe dare eccezzione da catturare
wxIMPLEMENT_APP(Tasky);

bool Tasky::OnInit() {
    //TODO: controllo del percorso e se non esiste crearlo

    std::string filepath = "/home/lucian/Scrivania/prova.xml";

    //TODO: aggiungere try per le eccezioni all'interno di loaddatafromfile
    XMLFileRepository fileRepository(filepath);

    Model *model = new Model(&fileRepository);

    model->setTaskMap(fileRepository.loadTaskFromFile());

    MainFrame *mainFrame=new MainFrame(model, nullptr,"Tasky",wxID_ANY,wxPoint(0, 0), wxSize(1200, 700));

    return true;
}

