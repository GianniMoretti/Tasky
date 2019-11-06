//
// Created by giannimoretti on 22/07/19.
//

#include "gtest/gtest.h"
#include "../Models/Model.h"
#include "../FileManagement/XMLFileRepository.h"

class XMLFileRepositorySuite : public ::testing::Test {
protected:
    void SetUp() override {
        wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
        fileRepository = new XMLFileRepository("/home/giannimoretti/Scrivania/prova.xml");

        m = new Model(fileRepository);

        /*Task t("pippo", "pluto", dateTime, Priority::Low, true);
        m->addTask(t);
        t = Task("hello", "world", dateTime, Priority::High, true);
        m->addTask(t);
        t = Task("foo", "bar", dateTime, Priority::High);
        m->addTask(t);*/

    };


    Model *m;
    XMLFileRepository *fileRepository;
};


TEST_F(XMLFileRepositorySuite, testAddTask) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    Task t("pippo", "pluto", dateTime, Priority::Low, true);
    bool ok = fileRepository->addTask(t);
    ASSERT_EQ(ok, true);
}

TEST_F(XMLFileRepositorySuite, testRemoveTask) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    Task t("pippo", "pluto", dateTime, Priority::Low, true);
    bool ok = fileRepository->deleteTask(t);
    ASSERT_EQ(ok, true);
}

TEST_F(XMLFileRepositorySuite, failTestRemoveTask) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    Task t("ciao", "pluto", dateTime, Priority::Low, true);
    bool ok = fileRepository->deleteTask(t);
    ASSERT_EQ(ok, false);
}

TEST_F(XMLFileRepositorySuite, testLoadDataFromFile) {
    m->setTaskMap(fileRepository->loadTaskFromFile());
    ASSERT_EQ(m->getTaskMap().size(), 38);
}

TEST_F(XMLFileRepositorySuite, testUpdateTask) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    Task t("pippo", "pluto", dateTime, Priority::High, true);
    Task t1("Gianni", "Moretti", dateTime, Priority::Medium, false);
    bool ok = fileRepository->updateTask(t, t1);
    ASSERT_EQ(ok, true);
}

TEST_F(XMLFileRepositorySuite, failTestUpdateTask) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    Task t("ciao", "pluto", dateTime, Priority::High, true);
    Task t1("Gianni", "Moretti", dateTime, Priority::Medium, false);
    bool ok = fileRepository->updateTask(t, t1);
    ASSERT_EQ(ok, false);
}