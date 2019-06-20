//
// Created by giannimoretti on 20/06/19.
//

#include "XMLFileRepository.h"

XMLFileRepository::XMLFileRepository(const std::string &fp, Model *model) : filePath(fp), sub(model) {
    //TODO: Aggiungere tutti i try e catch  del caso
    this->attach();
}

XMLFileRepository::~XMLFileRepository() {
    this->detach();
}

void XMLFileRepository::saveChanges(std::multimap<wxDateTime, Task> &Tasks) {
    //TODO: salva tasks nel file.
}


void XMLFileRepository::update() {
    std::multimap<wxDateTime, Task> Tasks = sub->getTaskMap();
    saveChanges(Tasks);
}

void XMLFileRepository::attach() {
    sub->subscribe(this);
}

void XMLFileRepository::detach() {
    sub->unsubscribe(this);
}

std::multimap<wxDateTime, Task> XMLFileRepository::loadDataFromFile() {
    //TODO: Metodo che carica dati da file XML
    return std::multimap<wxDateTime, Task>();
}


