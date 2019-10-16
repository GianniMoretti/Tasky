//
// Created by giannimoretti on 16/10/19.
//

#ifndef TASKY_IMPOSSIBLETOCREATEFILEEXEPTION_H
#define TASKY_IMPOSSIBLETOCREATEFILEEXEPTION_H

#include <exception>
#include <string>

using namespace std;

class ImpossibleToCreateFileException : public exception {
public:
    explicit ImpossibleToCreateFileException(const string &msg = "Impossible to create the save file") : exception() {
        m = msg;
    };

    virtual const char *what() const throw() {
        return m.c_str();
    }

private:
    string m;
};

#endif //TASKY_IMPOSSIBLETOCREATEFILEEXEPTION_H
