//
// Created by giannimoretti on 20/06/19.
//

#include "XMLFileRepository.h"

XMLFileRepository::XMLFileRepository(const std::string &fp, Model *model) : filePath(fp), sub(model) {
    //TODO: Aggiungere tutti i try e cath del caso
    loadDataFromFile();
    this->attach();
}

XMLFileRepository::~XMLFileRepository() {
    this->detach();
}

void XMLFileRepository::saveChanges() {
    //TODO: implement
}

const std::multimap<wxDateTime, Task> &XMLFileRepository::getData() {
    return Tasks;
}

void XMLFileRepository::update() {
    this->Tasks = sub->getTaskMap();
    saveChanges();
}

void XMLFileRepository::attach() {
    sub->subscribe(this);
}

void XMLFileRepository::detach() {
    sub->unsubscribe(this);
}

void XMLFileRepository::loadDataFromFile() {
    //TODO: Metodo che carica dati da file XML
}


