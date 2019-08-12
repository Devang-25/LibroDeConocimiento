#include <Common/RandomGenerator.hpp>

#include <random>

namespace src::common
{
namespace
{

unsigned generateRandomPositiveNumber(const int limit)
{
    const int INCLUDE_LIMIT = 1;

    std::random_device dev;
    return dev() % (limit + INCLUDE_LIMIT);
}

} // namespace

bool randomDecision(const int chance)
{
    const int MIN_PERCENTAGE = 0;
    const int MAX_PERCENTAGE = 100;

    if (chance <= MIN_PERCENTAGE) return false;
    if (chance >= MAX_PERCENTAGE) return true;

    int indicator = generateRandomPositiveNumber(MAX_PERCENTAGE);
    return indicator <= chance;
}

double randomNumber(
    const int limit,
    const int negativePercentChance)
{
    const int MULTIPLIER = 2; // For generation of floating numbers
    const int NEGATIVE_NUM = -1; // For generation of negative numbers

    double result = generateRandomPositiveNumber(limit * MULTIPLIER);
    result /= MULTIPLIER; // Non-double variables directly operating with double variables would also be promoted to double

    return randomDecision(negativePercentChance) ?
            result *= NEGATIVE_NUM :
            result;
}

} // namespace src::common
