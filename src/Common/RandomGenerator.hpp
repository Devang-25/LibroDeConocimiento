#ifndef SRC_COMMON_RANDOMGENERATOR_HPP
#define SRC_COMMON_RANDOMGENERATOR_HPP

namespace src::common
{

bool randomDecision(const int chance = 50);

double randomNumber(
    const int limit,
    const int negativePercentChance = 0);

} // namespace src::common

#endif // SRC_COMMON_RANDOMGENERATOR_HPP
