//
// Created by giannimoretti on 22/07/19.
//

#include "gtest/gtest.h"
#include "../Models/Model.h"
#include "../FileManagement/XMLFileRepository.h"

class XMLFileRepositoryFixture : public ::testing::Test {
protected:
    void SetUp() override {
        wxDateTime dateTime = wxDateTime().Now().GetDateOnly();

        Task t("pippo", "pluto", dateTime, Priority::Low, true);
        m.addTask(t);
        t = Task("hello", "world", dateTime, Priority::High, true);
        m.addTask(t);
        t = Task("foo", "bar", dateTime, Priority::High);
        m.addTask(t);

        fileRepository = new XMLFileRepository("", &m);
    };

    Model m;
    XMLFileRepository *fileRepository;
};