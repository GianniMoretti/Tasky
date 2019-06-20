//
// Created by giannimoretti on 17/06/19.
//

#ifndef TASKY_IMODEL_H
#define TASKY_IMODEL_H


#include "../IObserver.h"

class IModel {
public:
    virtual ~IModel() {};

    virtual void notify() const = 0;

    virtual void subscribe(IObserver *obs) = 0;

    virtual void unsubscribe(IObserver *obs) = 0;
};


#endif //TASKY_IMODEL_H
