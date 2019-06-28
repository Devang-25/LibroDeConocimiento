#include <CoderByte/Challenges/EasyDifficulty/SimpleAdding.hpp>

#include <Utilities/Logger.hpp>
#include <Utilities/UserInputHandler.hpp>

namespace src::coderbyte::challenges::easy
{
namespace
{

utilities::Logger logger("SimpleAdding");

int simpleAdding(int num)
{
    // code goes here
    int sum = 0;
    for (; num >= 1; num--)
    {
        sum += num;
    }
    return sum;
}

} // namespace

const std::string SimpleAdding::CHALLENGE_NAME_ = "SimpleAdding";

SimpleAdding::SimpleAdding()
{
}

std::string SimpleAdding::name() const
{
    return CHALLENGE_NAME_;
}

void SimpleAdding::run()
{
    displayProblem();
    auto input = utilities::getUserInputIntegralOrFloating<int>();
    auto result = simpleAdding(input);
    logger.print(result);
}

void SimpleAdding::displayProblem() const
{
    logger.print("Have the function SimpleAdding(num) add up all the numbers from 1 to num.");
    logger.print("For example: if the input is 4 then your program should return 10 because 1 + 2 + 3 + 4 = 10.");
    logger.print("For the test cases, the parameter num will be any number from 1 to 1000.");
}

} // namespace src::coderbyte::challenges::easy
