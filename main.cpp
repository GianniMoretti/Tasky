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

    //TODO: utilizzare degli smart pointer non mi riesce
    std::string filepath = "../data.xml";
    XMLFileRepository *fileRepository;
    //shared_ptr<XMLFileRepository> fileRepository;

    try {
        //fileRepository = make_shared<XMLFileRepository>(XMLFileRepository(filepath));
        fileRepository = new XMLFileRepository(filepath);
    }
    catch (ImpossibleToCreateFileException &e) {
        wxMessageBox(e.what());
        return true;
    }

    Model *model = new Model(fileRepository);

    model->setTaskMap(fileRepository->loadTaskFromFile());

    MainFrame *mainFrame = new MainFrame(model, nullptr, "Tasky", wxID_ANY, wxPoint(0, 0), wxSize(-1, -1));

    return true;
}

