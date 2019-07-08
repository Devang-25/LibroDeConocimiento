#include <iostream>

#include <gtest/gtest.h>

#include <Challenges/ProjectEuler/LargestPrimeFactor.hpp>

using namespace src::challenges::euler;

struct LargestPrimeFactorTest : public ::testing::Test
{
    LargestPrimeFactorTest(){}
    virtual ~LargestPrimeFactorTest(){}

    virtual void SetUp(){}
    virtual void TearDown(){}

    LargestPrimeFactor impl_;
};

TEST_F(LargestPrimeFactorTest, PrimeNumber)
{
    long primeNumber = 19;

    std::stringstream iss;
    iss << primeNumber;

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<long>(), primeNumber);
}

TEST_F(LargestPrimeFactorTest, CompositeNumber)
{
    long compositeNumber = 16; // 2 * 2 * 4

    std::stringstream iss;
    iss << compositeNumber;

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<long>(), 2);
}

TEST_F(LargestPrimeFactorTest, MultiplyPrimeWithPrimeNumbers)
{
    long largestPrimeNumber = 29;
    long answer = largestPrimeNumber * 5 * 7 * 13;

    std::stringstream iss;
    iss << answer;

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<long>(), largestPrimeNumber);
}

TEST_F(LargestPrimeFactorTest, MultiplyPrimeWithCompositeNumbers)
{
    long largestPrimeNumber = 1999;
    long answer = largestPrimeNumber * 4 * 10 * 22;

    std::stringstream iss;
    iss << answer;

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<long>(), largestPrimeNumber);
}


TEST_F(LargestPrimeFactorTest, MultiplyPrimeWithMixOfPrimeAndCompositeNumbers)
{
    long largestPrimeNumber = 1033;
    long primeNumber = 521;
    long largestCompositeNumber = 1034;
    long compositeNumber = 522;
    long answer = largestPrimeNumber * primeNumber * largestCompositeNumber * compositeNumber;

    std::stringstream iss;
    iss << answer;

    auto result = impl_.run(iss);
    EXPECT_EQ(result.get<long>(), largestPrimeNumber);
}
