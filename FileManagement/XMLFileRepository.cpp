//
// Created by giannimoretti on 20/06/19.
//

#include "XMLFileRepository.h"

XMLFileRepository::XMLFileRepository(const std::string &fp, Model *model) : filePath(fp), sub(model) {
    if (!fileExist(fp))
        createXMLFile();

    this->attach();
}

XMLFileRepository::~XMLFileRepository() {
    this->detach();
}

bool XMLFileRepository::saveChanges(const std::multimap<wxDateTime, Task> &Tasks) {
    //TODO: Devi cancellare prima di riscrivere
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filePath.c_str(), pugi::parse_default | pugi::parse_declaration);

    if (result) {
        pugi::xml_node root = doc.document_element();

        for (auto itr = Tasks.begin(); itr != Tasks.end(); itr++) {
            pugi::xml_node nodeChild = root.append_child("Task");
            nodeChild.append_attribute("Name") = itr->second.getName().c_str();
            nodeChild.append_attribute("Description") = itr->second.getDescription().c_str();
            nodeChild.append_attribute("Priority") = itr->second.getPriorityString().c_str();
            nodeChild.append_attribute("IsChecked") = itr->second.isChecked();
            nodeChild.append_attribute("Date") = itr->second.getDate().FormatDate().c_str().AsChar();
        }

        return doc.save_file(filePath.c_str(), PUGIXML_TEXT("  "));
    } else {
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
    //TODO: Mancano tutti i controlli
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filePath.c_str(), pugi::parse_default | pugi::parse_declaration);
    std::multimap<wxDateTime, Task> Tasks;
    if (result) {
        pugi::xml_node root = doc.document_element();
        for (pugi::xml_node tool = root.child("Task"); tool; tool = tool.next_sibling("Task")) {
            std::string n = tool.attribute("Name").as_string();
            std::string d = tool.attribute("Description").as_string();
            Priority p = Str2Pri(tool.attribute("Priority").as_string());
            bool c = tool.attribute("IsChecked").as_bool();
            wxDateTime da;
            da.ParseDate(tool.attribute("Date").as_string());

            Task t(n, d, da, p, c);
            Tasks.insert(std::make_pair(t.getDate(), t));
        }
    }
    return Tasks;
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

bool XMLFileRepository::fileExist(const std::string &fp) {
    std::fstream fin;

    fin.open(fp, std::ios::in);
    if (fin.is_open()) {
        fin.close();
        return true;
    }

    return false;
}

Priority XMLFileRepository::Str2Pri(const std::string s) {
    Priority p;

    if (s == "High")
        p = Priority::High;
    else if (s == "Medium")
        p = Priority::Medium;
    else
        p = Priority::Low;

    return p;
}





