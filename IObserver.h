//
// Created by giannimoretti on 17/06/19.
//

#ifndef TASKY_IOBSERVER_H
#define TASKY_IOBSERVER_H


class IObserver {
public:
    virtual ~IObserver() {};

    virtual void update() = 0;

    virtual void attach() = 0;

    virtual void detach() = 0;
};


#endif //TASKY_IOBSERVER_H
