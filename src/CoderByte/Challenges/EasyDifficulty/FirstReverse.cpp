#include <CoderByte/Challenges/EasyDifficulty/FirstReverse.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::coderbyte::challenges::easy
{
namespace
{

common::Logger logger("FirstReverse");

std::string firstReverse(const std::string& str)
{
    // code goes here
    std::string result;
    for (int ctr = str.size() - 1; ctr >= 0; ctr--)
    {
        result += str.at(ctr);
    }
    return result;
}

} // namespace

const std::string FirstReverse::CHALLENGE_NAME_ = "FirstReverse";

FirstReverse::FirstReverse()
{
}

std::string FirstReverse::name() const
{
    return CHALLENGE_NAME_;
}

common::Result FirstReverse::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputString(inputStream);
    auto result = firstReverse(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void FirstReverse::displayProblem() const
{
    logger.print("Have the function FirstReverse(str) take the str parameter being passed and return the string in reversed order.");
    logger.print("For example: if the input string is \"Hello World and Coders\" then your program should return the string \"sredoC dna dlroW olleH\".");
}

} // namespace src::coderbyte::challenges::easy
