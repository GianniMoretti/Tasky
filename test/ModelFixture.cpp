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
        t = Task("hello", "world", dateTime, Priority::High, true);
        m.addTask(t);
        t = Task("foo", "bar", dateTime, Priority::High);
        m.addTask(t);
    };

    Model m;
};

//TODO: anche le cose che vanno storte
TEST_F(ModelSuite, testAddTask) {
    Task t("ciao", "gianni", wxDateTime().Now().GetDateOnly(), Priority::Low);
    m.addTask(t);
    ASSERT_EQ(m.getTaskMap().size(), 4);
}

TEST_F(ModelSuite, testRemoveTask) {
    Task t("pippo", "pluto", wxDateTime().Now().GetDateOnly(), Priority::Low, true);
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
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