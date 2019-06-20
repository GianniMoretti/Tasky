//
// Created by giannimoretti on 20/06/19.
//

#ifndef TASKY_XMLFILEREPOSITORY_H
#define TASKY_XMLFILEREPOSITORY_H


#include "IFIleRepository.h"
#include "../IObserver.h"
#include "../Models/Model.h"

#include <string>
#include <map>

class XMLFileRepository : public IFIleRepository, public IObserver {
public:
    explicit XMLFileRepository(const std::string &fp, Model *model);

    //TODO: Di quale fa l'ovveride?
    ~XMLFileRepository() override;

    void saveChanges() override;

    std::multimap<wxDateTime, Task> getData() override;

    void update() override;

    void attach() override;

    void detach() override;

private:
    const std::string filePath;
    Model *sub;
    std::multimap<wxDateTime, Task> Tasks;

    void loadDataFromFile();
};


#endif //TASKY_XMLFILEREPOSITORY_H
