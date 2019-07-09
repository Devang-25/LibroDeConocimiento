#include <iostream>

#include <gtest/gtest.h>

#include <Challenges/CoderByte/EasyDifficulty/LongestWord.hpp>

using namespace src::challenges::coderbyte::easy;

struct LongestWordTest : public ::testing::Test
{
    LongestWordTest(){}
    virtual ~LongestWordTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    LongestWord impl_;
};

TEST_F(LongestWordTest, NameIsCorrect)
{
    EXPECT_EQ(impl_.name(), "LongestWord");
}

TEST_F(LongestWordTest, OneWord)
{
    std::string input("nielponciano");
    std::string answer("nielponciano");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(LongestWordTest, TwoWords)
{
    std::string input("niel ponciano");
    std::string answer("ponciano");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(LongestWordTest, ThreeWords)
{
    std::string input(" earth is beautiful");
    std::string answer("beautiful");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(LongestWordTest, WordsWithMoreThanOneSpace)
{
    std::string input(" always give  Your 100    percent");
    std::string answer("percent");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(LongestWordTest, WordsWithMoreThanOneSpaceAndLeadingCharacters)
{
    std::string input(" it  maybe .stormy now, but it can't RAIN   ... forever!");
    std::string answer("forever");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(LongestWordTest, DontRecognizeDashAsOneWord)
{
    std::string input("Refuse the Straw and other SINGLE-USE PLASTICS!");
    std::string answer("PLASTICS");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(LongestWordTest, GetFirstLongestIfThereAreEqual)
{
    std::string input("If you notice, thisreallylongwordone is equal to the length of thisreallylongwordtwo but thisreallylongwordone is first");
    std::string answer("thisreallylongwordone");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}

TEST_F(LongestWordTest, DontRecognizeNumbers)
{
    std::string input("111 22 polar 33 4 5555 666 777777 bear 8888 9 ");
    std::string answer("polar");

    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<std::string>(), answer);
}
