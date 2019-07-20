//
// Created by giannimoretti on 20/06/19.
//

#include "XMLFileRepository.h"

XMLFileRepository::XMLFileRepository(const std::string &fp, Model *model) : filePath(fp), sub(model) {
    this->attach();
}

XMLFileRepository::~XMLFileRepository() {
    this->detach();
}

bool XMLFileRepository::saveChanges(std::multimap<wxDateTime, Task> &Tasks) {
    //TODO: salva tasks nel file.
    //se il file non esiste va creato.
    //apertura dello stream
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filePath.c_str(), pugi::parse_default | pugi::parse_declaration);

    if (result) {
        pugi::xml_node root = doc.document_element();

        for (auto itr = Tasks.begin(); itr != Tasks.end(); itr++) {
            pugi::xml_node nodeChild = root.append_child("Task");
            nodeChild.append_attribute("Name") = itr->second.getName().c_str();
            nodeChild.append_attribute("Description") = itr->second.getDescription().c_str();
            //nodeChild.append_attribute("Priority") = itr->second.getPriority(); metodo per la conversione
            //nodeChild.append_attribute("Date") = itr->second.getDate(); come si converte
            //nodeChild.append_attribute("IsChecked") = itr->second.isChecked();
        }

        return doc.save_file(filePath.c_str(), PUGIXML_TEXT("  "));
    } else {
        //TODO: lanciare eccezione?
        return false;
    }
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

bool XMLFileRepository::createXMLFile() {
    pugi::xml_document doc;

    auto declarationNode = doc.append_child(pugi::node_declaration);
    declarationNode.append_attribute("version") = "1.0";
    declarationNode.append_attribute("encoding") = "ISO-8859-1";
    declarationNode.append_attribute("standalone") = "yes";

    auto root = doc.append_child("Tasks");

    return doc.save_file(filePath.c_str(), PUGIXML_TEXT("  "));
}


