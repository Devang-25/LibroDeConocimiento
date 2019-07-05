#include <Challenges/CoderByte/EasyDifficulty/SimpleAdding.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::coderbyte::easy
{
namespace
{

common::Logger logger("SimpleAdding");

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

common::Result SimpleAdding::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputIntegralOrFloating<int>(inputStream);
    auto result = simpleAdding(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void SimpleAdding::displayProblem() const
{
    logger.print("Have the function SimpleAdding(num) add up all the numbers from 1 to num.");
    logger.print("For example: if the input is 4 then your program should return 10 because 1 + 2 + 3 + 4 = 10.");
    logger.print("For the test cases, the parameter num will be any number from 1 to 1000.");
}

} // namespace src::challenges::coderbyte::easy
