#include <iostream>

#include <gtest/gtest.h>

#include <CoderByte/Challenges/EasyDifficulty/FirstFactorial.hpp>

using namespace src::coderbyte::challenges::easy;

struct FirstFactorialTest : public ::testing::Test
{
    FirstFactorialTest(){}
    virtual ~FirstFactorialTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    FirstFactorial impl_;
};

TEST_F(FirstFactorialTest, NameIsCorrect)
{
    EXPECT_EQ(impl_.name(), "FirstFactorial");
}
