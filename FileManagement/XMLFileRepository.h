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
#include <iostream>
#include <fstream>
#include "../pugi/pugixml.hpp"


class XMLFileRepository : public IFIleRepository {
public:
    explicit XMLFileRepository(const std::string &fp);

    std::multimap<wxDateTime, Task> loadTaskFromFile() override;

    bool addTask(const Task &t) override;

    bool deleteTask(const Task &t) override;

    bool updateTask(const Task &oldTask, const Task &newTask) override;

    ~XMLFileRepository() override = default;

private:
    bool fileExist(const std::string &fp);
    Priority Str2Pri(std::string s);
    bool createXMLFile();
    const std::string filePath;
};


#endif //TASKY_XMLFILEREPOSITORY_H
