#include <iostream>

#include <gtest/gtest.h>

#include <Challenges/CoderByte/HardDifficulty/ChessboardTraveling.hpp>

using namespace src::challenges::coderbyte::hard;

struct ChessboardTravelingTest : public ::testing::Test
{
    ChessboardTravelingTest(){}
    virtual ~ChessboardTravelingTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    ChessboardTraveling impl_;
};

TEST_F(ChessboardTravelingTest, BasicConfiguration)
{
    std::string input("(1 1)(3 3)");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<int>(), 6);
}

TEST_F(ChessboardTravelingTest, FullConfiguration)
{
    std::string input("(1 1)(8 8)");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<int>(), 3432);
}

TEST_F(ChessboardTravelingTest, BasicConfigurationWithIncompleteSymbols)
{
    std::string input("113  3)");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<int>(), 6);
}

TEST_F(ChessboardTravelingTest, BasicConfigurationWithIncompleteNumberInput)
{
    std::string input("113");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<int>(), 0);
}


TEST_F(ChessboardTravelingTest, SourceIsNearDestination)
{
    std::string input("(2 2)(4 3)");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<unsigned>(), 3);
}

TEST_F(ChessboardTravelingTest, SourceHasManyPathsToDestination)
{
    std::string input("(2 3)(6 6)");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<unsigned>(), 35);
}

TEST_F(ChessboardTravelingTest, SameCoordinateNumbers)
{
    std::string input("(4 6)(4 6)");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<unsigned>(), 0);
}

TEST_F(ChessboardTravelingTest, DestinationIsToTheLeft)
{
    std::string input("(3 5)(5 4)");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<unsigned>(), 0);
}

TEST_F(ChessboardTravelingTest, DestinationIsToLower)
{
    std::string input("(3 5)(2 7)");
    std::istringstream iss(input);

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<unsigned>(), 0);
}
