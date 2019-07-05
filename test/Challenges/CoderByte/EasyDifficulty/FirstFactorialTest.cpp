#include <iostream>

#include <gtest/gtest.h>

#include <Challenges/CoderByte/EasyDifficulty/FirstFactorial.hpp>

using namespace src::challenges::coderbyte::easy;

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

TEST_F(FirstFactorialTest, FactorialOfSmallNumber)
{
    std::string input("4");
    long answer = 4*3*2*1;

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<long>(), answer);
}

TEST_F(FirstFactorialTest, FactorialOfBigNumber)
{
    std::string input("10");
    long answer = 10*9*8*7*6*5*4*3*2*1;

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<long>(), answer);
}

TEST_F(FirstFactorialTest, FactorialOfOne)
{
    std::string input("1");
    long answer = 1;

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<long>(), answer);
}

TEST_F(FirstFactorialTest, FactorialOfZero)
{
    std::string input("0");
    long answer = 1;

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<long>(), answer);
}

TEST_F(FirstFactorialTest, FactorialOfNegativeNumber)
{
    std::string input("-3");
    long answer = 1;

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<long>(), answer);
}
