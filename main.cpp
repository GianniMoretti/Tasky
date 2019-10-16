#include <iostream>
#include <memory>
#include <exception>
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP

#include <wx/wx.h>

#include "Exceptions/ImpossibleToCreateFileExeption.h"
#include "Views/MainView.h"
#include "Models/Model.h"
#include "FileManagement/XMLFileRepository.h"
#include "Views/MainFrame.h"

#endif

using namespace std;

class Tasky : public wxApp {
public:
    bool OnInit() override;
};

//potrebbe dare eccezzione da catturare
wxIMPLEMENT_APP(Tasky);

bool Tasky::OnInit() {

    //TODO: trovare il percorso in automatico
    //TODO: utilizzare degli unique pointer
    std::string filepath = "/home/giannimoretti/Scrivania/prova.xml";
    XMLFileRepository *fileRepository;
    //unique_ptr<XMLFileRepository> fileRepository;

    try {
        fileRepository = make_shared<XMLFileRepository>(XMLFileRepository(filepath));
    }
    catch (ImpossibleToCreateFileException &e) {
        wxMessageBox(e.what());
        return true;
    }

    shared_ptr<Model> model = make_shared<Model>(Model(fileRepository.get()));

    model->setTaskMap(fileRepository->loadTaskFromFile());

    MainFrame *mainFrame = new MainFrame(model.get(), nullptr, "Tasky", wxID_ANY, wxPoint(0, 0), wxSize(-1, -1));

    return true;
}

