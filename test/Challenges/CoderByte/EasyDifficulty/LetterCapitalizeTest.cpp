#include <iostream>

#include <gtest/gtest.h>

#include <Challenges/CoderByte/EasyDifficulty/LetterCapitalize.hpp>

using namespace src::challenges::coderbyte::easy;

struct LetterCapitalizeTest : public ::testing::Test
{
    LetterCapitalizeTest(){}
    virtual ~LetterCapitalizeTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    LetterCapitalize impl_;
};

TEST_F(LetterCapitalizeTest, NameIsCorrect)
{
    EXPECT_EQ(impl_.name(), "LetterCapitalize");
}

TEST_F(LetterCapitalizeTest, CapitalizeWithoutSpace)
{
    std::string input("nielponciano");
    std::string answer("Nielponciano");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(LetterCapitalizeTest, CapitalizeWithSpaces)
{
    std::string input("niel ponciano");
    std::string answer("Niel Ponciano");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(LetterCapitalizeTest, CapitalizeWithLeadingSpace)
{
    std::string input(" earth is beautiful");
    std::string answer(" Earth Is Beautiful");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(LetterCapitalizeTest, CapitalizeWithMoreThanOneSpace)
{
    std::string input(" always give  Your 100    percent");
    std::string answer(" Always Give  Your 100    Percent");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}


TEST_F(LetterCapitalizeTest, CapitalizeWithMoreThanOneSpaceAndLeadingCharacters)
{
    std::string input(" it  maybe .stormy now, but it can't RAIN   ... forever!");
    std::string answer(" It  Maybe .stormy Now, But It Can't RAIN   ... Forever!");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(LetterCapitalizeTest, HandleAlreadyCapitalLetters)
{
    std::string input("Refuse the Straw and other SINGLE-USE PLASTICS!");
    std::string answer("Refuse The Straw And Other SINGLE-USE PLASTICS!");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}
