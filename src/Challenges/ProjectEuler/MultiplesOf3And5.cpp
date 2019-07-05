#include <Challenges/ProjectEuler/MultiplesOf3And5.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::euler
{
namespace
{

common::Logger logger("MultiplesOf3And5");

// Yes, the name should have been MultiplesOf3Or5 instead, but to be consistent with ProjectEuler,
// thus the name :)
unsigned multiplesOf3And5(unsigned number)
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
    auto input = common::getUserInputIntegralOrFloating<unsigned>(inputStream);
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
