#include "CoderByte/Challenges/ChallengesGetter.hpp"

#include "CoderByte/Challenges/EasyDifficulty/FirstReverse.hpp"
#include "CoderByte/Challenges/EasyDifficulty/FirstFactorial.hpp"
#include "CoderByte/Challenges/IChallenge.hpp"

namespace src::coderbyte::challenges
{

std::vector<std::shared_ptr<IChallenge>> getAllChallenges()
{
    return
        {
            std::make_shared<easy::FirstReverse>(),
            std::make_shared<easy::FirstFactorial>(),
        };
}

std::map<std::string, unsigned> getChallengesNameAndIdMap(
    const std::vector<std::shared_ptr<IChallenge>>& challenges)
{
    std::map<std::string, unsigned> nameAndId;

    unsigned id = 0;
    for(const auto& challenge : challenges)
    {
        nameAndId[challenge->name()] = id;
        id++;
    }

    return nameAndId;
}

} // namespace src::coderbyte::challenges
