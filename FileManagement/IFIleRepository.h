//
// Created by giannimoretti on 20/06/19.
//

#ifndef TASKY_IFILEREPOSITORY_H
#define TASKY_IFILEREPOSITORY_H

#include <map>
#include <wx/datetime.h>

#include "../Models/Task.h"
#include "../IObserver.h"

class IFIleRepository : public IObserver {
public:
    virtual ~IFIleRepository() {};

    virtual bool saveChanges(std::multimap<wxDateTime, Task> &Tasks) = 0;

    virtual std::multimap<wxDateTime, Task> loadDataFromFile() = 0;
};


#endif //TASKY_IFILEREPOSITORY_H
