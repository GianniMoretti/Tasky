//
// Created by giannimoretti on 20/06/19.
//


#include "gtest/gtest.h"
#include "../Models/Model.h"

class ModelSuite : public ::testing::Test {
protected:
    void SetUp() override {
        wxDateTime dateTime = wxDateTime().Now().GetDateOnly();

        Task t("pippo", "pluto", dateTime, Priority::Low, true);
        m.addTask(t);
        t = Task("hello", "pippo", dateTime, Priority::High, true);
        m.addTask(t);
        t = Task("foo", "bar", dateTime, Priority::High);
        m.addTask(t);
    };

    Model m;
};

//TODO: testing delle cose quando vanno male (es ricerca lista vuota)
TEST_F(ModelSuite, testAddTask) {
    Task t("ciao", "gianni", wxDateTime().Now().GetDateOnly(), Priority::Low);
    m.addTask(t);
    ASSERT_EQ(m.getTaskMap().size(), 4);
}

TEST_F(ModelSuite, testRemoveTask) {
    Task t("pippo", "pluto", wxDateTime().Now().GetDateOnly(), Priority::Low, true);
    m.removeTask(t);
    ASSERT_EQ(m.getTaskMap().size(), 2);
}

TEST_F(ModelSuite, testCountTasksCompleted) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    ASSERT_EQ(m.numberOfCompletedTasks(dateTime), 2);
}

TEST_F(ModelSuite, testCountTasks) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    ASSERT_EQ(m.numberOfTasks(dateTime), 3);
}

TEST_F(ModelSuite, testResearchChecked) {
    std::list<Task *> list = m.researchTasks("1", true);
    ASSERT_EQ(list.size(), 0);
}

TEST_F(ModelSuite, testResearchUnChecked) {
    std::list<Task *> list = m.researchTasks("pippo", false);
    ASSERT_EQ(list.size(), 2);
}

TEST_F(ModelSuite, testGetTasks) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    auto itr = m.GetTasks(dateTime);
    int count = 0;
    for (itr; itr != m.getTaskMap().end(); itr++)
        count++;
    ASSERT_EQ(count, 3);
}

TEST_F(ModelSuite, testGkeys) {
    ASSERT_EQ(m.GetKeysOnce().size(), 1);
}