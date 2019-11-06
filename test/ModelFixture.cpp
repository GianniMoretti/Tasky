//
// Created by giannimoretti on 20/06/19.
//


#include "gtest/gtest.h"
#include "../Models/Model.h"
#include "../FileManagement/XMLFileRepository.h"

class ModelSuite : public ::testing::Test {
protected:
    void SetUp() override {
        wxDateTime dateTime = wxDateTime().Now().GetDateOnly();

        fileRepository = new XMLFileRepository("/home/giannimoretti/Scrivania/prova.xml");
        m = new Model(fileRepository);

        //Task t("pippo", "pluto", dateTime, Priority::Low, true);
        //m->addTask(t);
        //t = Task("hello", "pippo", dateTime, Priority::High, true);
        //m->addTask(t);
        //t = Task("foo", "bar", dateTime, Priority::High);
        //m->addTask(t);

    };
    XMLFileRepository *fileRepository;
    Model *m;
};

//TODO: testing delle cose quando vanno male (es ricerca lista vuota)
TEST_F(ModelSuite, testAddTask) {
    Task t("ciao", "gianni", wxDateTime().Now().GetDateOnly(), Priority::Low);
    m->addTask(t);
    ASSERT_EQ(m->getTaskMap().size(), 4);
}

TEST_F(ModelSuite, testRemoveTask) {
    Task t("pippo", "pluto", wxDateTime().Now().GetDateOnly(), Priority::Low, true);
    m->removeTask(t);
    ASSERT_EQ(m->getTaskMap().size(), 2);
}

TEST_F(ModelSuite, failTestRemoveTask) {
    Task t("ciao", "pluto", wxDateTime().Now().GetDateOnly(), Priority::Low, true);
    bool ok = m->removeTask(t);
    ASSERT_EQ(ok, false);
}

TEST_F(ModelSuite, testCountTasksCompleted) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    ASSERT_EQ(m->numberOfCompletedTasks(dateTime), 2);
}

TEST_F(ModelSuite, testCountTasksCompletedNotask) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    ASSERT_EQ(m->numberOfCompletedTasks(dateTime), 0);
}

TEST_F(ModelSuite, testCountTasks) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    ASSERT_EQ(m->numberOfTasks(dateTime), 3);
}

TEST_F(ModelSuite, testCountTasksNoTask) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    ASSERT_EQ(m->numberOfTasks(dateTime), 0);
}

TEST_F(ModelSuite, testResearchChecked) {
    std::list<Task *> list = m->researchTasks("pippo", true);
    ASSERT_EQ(list.size(), 0);
}


TEST_F(ModelSuite, testResearchUnChecked) {
    std::list<Task *> list = m->researchTasks("pippo", false);
    ASSERT_EQ(list.size(), 2);
}

TEST_F(ModelSuite, testGetTasks) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    auto ref = m->GetTasks(dateTime);
    int count = 0;
    for (auto itr = ref.first; itr != ref.second; itr++)
        count++;
    ASSERT_EQ(count, 3);
}

TEST_F(ModelSuite, testGetTasksNoTask) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    auto ref = m->GetTasks(dateTime);
    int count = 0;
    for (auto itr = ref.first; itr != ref.second; itr++)
        count++;
    ASSERT_EQ(count, 0);
}

TEST_F(ModelSuite, testGkeys) {
    ASSERT_EQ(m->GetKeysOnce().size(), 1);
}