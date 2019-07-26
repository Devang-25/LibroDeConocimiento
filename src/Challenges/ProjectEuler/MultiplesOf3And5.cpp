#include <Challenges/ProjectEuler/MultiplesOf3And5.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::euler
{
namespace
{

common::Logger logger("MultiplesOf3And5");

unsigned multiplesOf3And5_version1(unsigned number)
{
    unsigned result = 0u;

    for (unsigned multiplesOfThree = 3; multiplesOfThree < number; multiplesOfThree = multiplesOfThree + 3)
    {
        result = result + multiplesOfThree;
    }

    for (unsigned multiplesOfFive = 5; multiplesOfFive < number; multiplesOfFive = multiplesOfFive + 5)
    {
        if (multiplesOfFive % 3 != 0)
        {
            result = result + multiplesOfFive;
        }
    }

    return result;
}

unsigned multiplesOf3And5_version2(unsigned number)
{
    unsigned result = 0u;
    unsigned multiplesOfThree = 3u;
    unsigned multiplesOfFive = 5u;

    while (multiplesOfFive < number)
    {
        result += multiplesOfThree;
        if (multiplesOfFive % 3)
        {
            result += multiplesOfFive;
        }

        multiplesOfThree += 3u;
        multiplesOfFive += 5u;
    }

    while (multiplesOfThree < number)
    {
        result += multiplesOfThree;
        multiplesOfThree += 3u;
    }

    return result;
}

long multiplesOf3And5_version3(long number)
{
    --number;

    long countOfThreeMultiples = number / 3;
    long lastMultipleOfThree = countOfThreeMultiples * 3;
    long countOfFiveMultiples = number / 5;
    long lastMultipleOfFive = countOfFiveMultiples * 5;
    long countOfFifteenMultiples = number / 15;
    long lastMultipleOfFifteen = countOfFifteenMultiples * 15;

    // Summation formula = n(a1 + an) / 2
    long result =
            (
                (countOfThreeMultiples * (3 + lastMultipleOfThree)) +
                (countOfFiveMultiples * (5 + lastMultipleOfFive)) -
                (countOfFifteenMultiples * (15 + lastMultipleOfFifteen))
            ) / 2;

    return result;
}

long multiplesOf3And5(long number)
{
    long result;

    result = static_cast<long>(multiplesOf3And5_version1(number));
    logger.print("multiplesOf3And5_version1: ", result);

    result = static_cast<long>(multiplesOf3And5_version2(number));
    logger.print("multiplesOf3And5_version2: ", result);

    result = multiplesOf3And5_version3(number);
    logger.print("multiplesOf3And5_version3: ", result);

    return result;
}

} // namespace

const std::string MultiplesOf3And5::CHALLENGE_NAME_ = "MultiplesOf3And5";

MultiplesOf3And5::MultiplesOf3And5()
{
}

std::string MultiplesOf3And5::name() const
{
    return CHALLENGE_NAME_;
}

common::Result MultiplesOf3And5::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputIntegralOrFloating<long>(inputStream);
    auto result = multiplesOf3And5(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void MultiplesOf3And5::displayProblem() const
{
    logger.print("If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.");
    logger.print("Find the sum of all the multiples of 3 or 5 below 1000.");
}

} // namespace src::challenges::euler
