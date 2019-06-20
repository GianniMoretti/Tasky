//
// Created by giannimoretti on 20/06/19.
//


#include "gtest/gtest.h"
#include "../Models/Model.h"

class ModelSuite : public ::testing::Test {
protected:
    virtual void setUp() {

    };

    Model m;
};

TEST_F(ModelSuite, testaddTask) {
    Task t("ciao", "gianni", Low);
    m.addTask(wxDateTime().Now(), t);

    ASSERT_EQ(m.getTaskMap().size(), 1);
}