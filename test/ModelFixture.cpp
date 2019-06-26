//
// Created by giannimoretti on 20/06/19.
//


#include "gtest/gtest.h"
#include "../Models/Model.h"

class ModelSuite : public ::testing::Test {
protected:
    void SetUp() override {
        Task t("ciao", "gianni", Low, true);
        m.addTask(wxDateTime().Now(), t);
        t = Task("hello", "try", High, true);
        m.addTask(wxDateTime().Now(), t);
        t = Task("hello", "try", High);
        m.addTask(wxDateTime().Now(), t);
    };

    Model m;
};

TEST_F(ModelSuite, testaddTask) {
    Task t("ciao", "gianni", Low);
    m.addTask(wxDateTime().Now(), t);

    ASSERT_EQ(m.getTaskMap().size(), 4);
}

TEST_F(ModelSuite, testCountTasksCompleted) {
    wxDateTime dateTime = wxDateTime().Now();
    ASSERT_EQ(m.numberTasksCompleted(dateTime), 2);
}