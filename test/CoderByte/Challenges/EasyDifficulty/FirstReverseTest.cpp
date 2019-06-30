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

TEST_F(FirstReverseTest, ReverseOneWordText)
{
    std::string input("PenGUins");
    std::string answer("sniUGneP");

    std::istringstream iss(input); // or std::stringstream

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(FirstReverseTest, ReverseTwoWords)
{
    std::string input("Global WARMING");
    std::string answer("GNIMRAW labolG");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(FirstReverseTest, ReverseSentence)
{
    std::string input("A GOAL without a PLAN is just a WISH");
    std::string answer("HSIW a tsuj si NALP a tuohtiw LAOG A");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(FirstReverseTest, ReverseNumbersAndSymbols)
{
    std::string input("11-22 ... 3*4/5+6-7, = #@");
    std::string answer("@# = ,7-6+5/4*3 ... 22-11");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(FirstReverseTest, ReverseCombinationOfLettersNumbersSymbols)
{
    std::string input(" 1234... 5. It is the [*SENSE OF PURPOSE*] that matters!! ^_^ ");
    std::string answer(" ^_^ !!srettam taht ]*ESOPRUP FO ESNES*[ eht si tI .5 ...4321 ");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}
