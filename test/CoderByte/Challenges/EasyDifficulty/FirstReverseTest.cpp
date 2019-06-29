#include <iostream>

#include <gtest/gtest.h>

#include <CoderByte/Challenges/EasyDifficulty/FirstReverse.hpp>

using namespace src::coderbyte::challenges::easy;

struct FirstReverseTest : public ::testing::Test
{
    FirstReverseTest(){}
    virtual ~FirstReverseTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    FirstReverse impl_;
};

TEST_F(FirstReverseTest, NameIsCorrect)
{
    EXPECT_EQ(impl_.name(), "FirstReverse");
}
