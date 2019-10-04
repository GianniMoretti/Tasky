//
// Created by giannimoretti on 20/06/19.
//

#include "XMLFileRepository.h"

XMLFileRepository::XMLFileRepository(const std::string &fp) : filePath(fp) {
    if (!fileExist(fp))
        createXMLFile();
}

std::multimap<wxDateTime, Task> XMLFileRepository::loadTaskFromFile() {
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

bool XMLFileRepository::deleteTask(const Task &t) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filePath.c_str(), pugi::parse_default | pugi::parse_declaration);

    if (result) {
        pugi::xpath_variable_set vars;
        vars.add("N", pugi::xpath_type_string);
        vars.add("D", pugi::xpath_type_string);
        vars.add("P", pugi::xpath_type_string);
        vars.add("C", pugi::xpath_type_boolean);
        vars.add("Dat", pugi::xpath_type_string);

        vars.set("N", t.getName().c_str());
        vars.set("D", t.getDescription().c_str());
        vars.set("P", t.getPriorityString().c_str());
        vars.set("C", t.isChecked());
        vars.set("Dat", t.getDate().FormatDate().c_str().AsChar());

        pugi::xpath_node tSelected = doc.select_nodes(
                "/Tasks/Task[@Name = string($N) and @Description = string($D) and @Priority = string($P) and @IsChecked = string($C) and @Date = string($Dat)]",
                &vars).first();

        if (tSelected == nullptr)
            return false;

        pugi::xml_node root = doc.document_element();

        bool ok = root.remove_child(tSelected.node());
        if (!ok)
            return false;

        return doc.save_file(filePath.c_str(), PUGIXML_TEXT("  "));
    } else {
        return false;
    }
}

bool XMLFileRepository::updateTask(const Task &oldTask, const Task &newTask) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filePath.c_str(), pugi::parse_default | pugi::parse_declaration);

    if (result) {
        pugi::xpath_variable_set vars;
        vars.add("N", pugi::xpath_type_string);
        vars.add("D", pugi::xpath_type_string);
        vars.add("P", pugi::xpath_type_string);
        vars.add("C", pugi::xpath_type_boolean);
        vars.add("Dat", pugi::xpath_type_string);

        vars.set("N", oldTask.getName().c_str());
        vars.set("D", oldTask.getDescription().c_str());
        vars.set("P", oldTask.getPriorityString().c_str());
        vars.set("C", oldTask.isChecked());
        vars.set("Dat", oldTask.getDate().FormatDate().c_str().AsChar());

        pugi::xpath_node tSelected = doc.select_nodes(
                "/Tasks/Task[@Name = string($N) and @Description = string($D) and @Priority = string($P) and @IsChecked = string($C) and @Date = string($Dat)]",
                &vars).first();

        if (tSelected == nullptr)
            return false;

        tSelected.node().attribute("Name") = newTask.getName().c_str();
        tSelected.node().attribute("Description") = newTask.getDescription().c_str();
        tSelected.node().attribute("Priority") = newTask.getPriorityString().c_str();
        tSelected.node().attribute("IsChecked") = newTask.isChecked();
        tSelected.node().attribute("Date") = newTask.getDate().FormatDate().c_str().AsChar();

        return doc.save_file(filePath.c_str(), PUGIXML_TEXT("  "));

    } else {
        return false;
    }
}

bool XMLFileRepository::addTask(const Task &t) {
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(filePath.c_str(), pugi::parse_default | pugi::parse_declaration);

    if (result) {
        pugi::xml_node root = doc.document_element();

        pugi::xml_node nodeChild = root.append_child("Task");
        nodeChild.append_attribute("Name") = t.getName().c_str();
        nodeChild.append_attribute("Description") = t.getDescription().c_str();
        nodeChild.append_attribute("Priority") = t.getPriorityString().c_str();
        nodeChild.append_attribute("IsChecked") = t.isChecked();
        nodeChild.append_attribute("Date") = t.getDate().FormatDate().c_str().AsChar();

        return doc.save_file(filePath.c_str(), PUGIXML_TEXT("  "));
    } else {
        return false;
    }
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








