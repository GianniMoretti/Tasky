//
// Created by giannimoretti on 20/06/19.
//

#ifndef TASKY_IFILEREPOSITORY_H
#define TASKY_IFILEREPOSITORY_H

#include <map>
#include <wx/datetime.h>

#include "Task.h"

class IFIleRepository {
public:
    virtual ~IFIleRepository() {};

    virtual void saveChanges() = 0;

    virtual const std::multimap<wxDateTime, Task> &getData() = 0;
};


#endif //TASKY_IFILEREPOSITORY_H
