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

class XMLFileRepository : public IFIleRepository {
public:
    explicit XMLFileRepository(const std::string &fp, Model *model);

    ~XMLFileRepository() override;

    void saveChanges(std::multimap<wxDateTime, Task> &Tasks) override;

    std::multimap<wxDateTime, Task> loadDataFromFile() override;

    void update() override;


private:
    void attach() override;
    void detach() override;
    const std::string filePath;
    Model *sub;

};


#endif //TASKY_XMLFILEREPOSITORY_H
