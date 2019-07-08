#include <Challenges/ProjectEuler/SmallestMultiple.hpp>

#include <map>
#include <math.h>
#include <set>
#include <vector>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::euler
{
namespace
{

common::Logger logger("SmallestMultiple");

bool isPrime(long number)
{
    long limit = number - 1;

    for (long ctr = 2; ctr <= limit; ctr++)
    {
        if (number % ctr == 0) return false;
        limit = number / ctr;
    }
    return true;
}

long largestPrimeFactor(long number)
{
    if (isPrime(number)) return number;

    long limit = number - 1;
    long largestPrime = 0;

    for (long multiplicand = 2; multiplicand <= limit; multiplicand++)
    {
        long multiplier = number / multiplicand;
        if (number % multiplicand == 0)
        {
            if (isPrime(multiplier) && multiplier > multiplicand)
            {
                return multiplier;
            }
            else if (isPrime(multiplicand))
            {
                largestPrime = multiplicand;
            }
        }
        limit = multiplier;
    }

    return largestPrime;
}

void getPrimeNumberFactorsAndCount(
    long number,
    std::map<long, long>& factorsAndCount)
{
    auto factor = largestPrimeFactor(number);
    factorsAndCount[factor]++;

    number = number / factor;
    if (number != 1)
    {
        getPrimeNumberFactorsAndCount(number, factorsAndCount);
    }

    return;
}

std::map<long, long> getPrimeNumberFactorsAndMaximumCount(const std::set<long>& numbers)
{
    std::map<long, long> primeNumbersAndMaximumCount;
    for (const auto& number : numbers)
    {
        std::map<long, long> factorsAndCount;
        getPrimeNumberFactorsAndCount(number, factorsAndCount);
        for (const auto& pair : factorsAndCount)
        {
            auto& currentMaxCount = primeNumbersAndMaximumCount[pair.first];
            if (pair.second > currentMaxCount)
            {
                currentMaxCount = pair.second;
            }
        }
    }
    return primeNumbersAndMaximumCount;
}

long smallestMultiple(const long number)
{
    std::set<long> numbers;
    for (long ctr = 1; ctr <= number; ctr++)
    {
        numbers.insert(ctr);
    }

    long result = 1;
    const auto primeNumbersAndMaximumCount = getPrimeNumberFactorsAndMaximumCount(numbers);

    for (const auto& pair : primeNumbersAndMaximumCount)
    {
        result = result * (pow(pair.first, pair.second));
    }
    return result;
}

} // namespace

const std::string SmallestMultiple::CHALLENGE_NAME_ = "SmallestMultiple";

SmallestMultiple::SmallestMultiple()
{
}

std::string SmallestMultiple::name() const
{
    return CHALLENGE_NAME_;
}

common::Result SmallestMultiple::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputIntegralOrFloating<long>(inputStream);
    auto result = smallestMultiple(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void SmallestMultiple::displayProblem() const
{
    logger.print("2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.");
    logger.print("What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?");
}

} // namespace src::challenges::euler
