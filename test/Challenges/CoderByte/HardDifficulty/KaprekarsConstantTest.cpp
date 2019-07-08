#include <iostream>

#include <gtest/gtest.h>

#include <Challenges/CoderByte/HardDifficulty/KaprekarsConstant.hpp>

using namespace src::challenges::coderbyte::hard;

struct KaprekarsConstantTest : public ::testing::Test
{
    KaprekarsConstantTest(){}
    virtual ~KaprekarsConstantTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    KaprekarsConstant impl_;
};

TEST_F(KaprekarsConstantTest, CalculateNumberOfTimesCorrectly)
{
    std::string input("3524");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<int>(), 3);
}

TEST_F(KaprekarsConstantTest, TargetValueAsInput)
{
    std::string input("6174");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<int>(), 1);
}

TEST_F(KaprekarsConstantTest, InputOfNot4Digits)
{
    std::string input("29");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<int>(), 3);
}


TEST_F(KaprekarsConstantTest, InputOf1Digit)
{
    std::string input("5");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<int>(), 6);
}
