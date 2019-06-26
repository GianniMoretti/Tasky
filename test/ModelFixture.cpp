//
// Created by giannimoretti on 20/06/19.
//


#include "gtest/gtest.h"
#include "../Models/Model.h"

class ModelSuite : public ::testing::Test {
protected:
    void SetUp() override {
        wxDateTime dateTime = wxDateTime().Now().GetDateOnly();

        Task t("ciao", "gianni", Low, true);
        m.addTask(dateTime, t);
        t = Task("hello", "try", High, true);
        m.addTask(dateTime, t);
        t = Task("hello", "try", High);
        m.addTask(dateTime, t);
    };

    Model m;
};

TEST_F(ModelSuite, testAddTask) {
    Task t("ciao", "gianni", Low);
    m.addTask(wxDateTime().Now().GetDateOnly(), t);
    ASSERT_EQ(m.getTaskMap().size(), 4);
}

TEST_F(ModelSuite, testRemoveTask) {
    Task t("ciao", "gianni", Low, true);
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    m.removeTask(dateTime, t);
    ASSERT_EQ(m.getTaskMap().size(), 2);
}

TEST_F(ModelSuite, testCountTasksCompleted) {
    wxDateTime dateTime = wxDateTime().Now().GetDateOnly();
    ASSERT_EQ(m.numberCompletedTasks(dateTime), 2);
}