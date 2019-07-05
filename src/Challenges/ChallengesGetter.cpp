#include <Challenges/ChallengesGetter.hpp>

#include <Challenges/CoderByte/EasyDifficulty/FirstFactorial.hpp>
#include <Challenges/CoderByte/EasyDifficulty/FirstReverse.hpp>
#include <Challenges/CoderByte/EasyDifficulty/LetterCapitalize.hpp>
#include <Challenges/CoderByte/EasyDifficulty/LetterChanges.hpp>
#include <Challenges/CoderByte/EasyDifficulty/LongestWord.hpp>
#include <Challenges/CoderByte/EasyDifficulty/SimpleAdding.hpp>
#include <Challenges/CoderByte/EasyDifficulty/SimpleSymbols.hpp>
#include <Challenges/ProjectEuler/MultiplesOf3And5.hpp>
#include <Challenges/IChallenge.hpp>

namespace src::challenges
{

std::vector<std::shared_ptr<IChallenge>> getAllChallenges()
{
    return
        {
            std::make_shared<coderbyte::easy::FirstReverse>(),
            std::make_shared<coderbyte::easy::FirstFactorial>(),
            std::make_shared<coderbyte::easy::LongestWord>(),
            std::make_shared<coderbyte::easy::LetterChanges>(),
            std::make_shared<coderbyte::easy::SimpleAdding>(),
            std::make_shared<coderbyte::easy::LetterCapitalize>(),
            std::make_shared<coderbyte::easy::SimpleSymbols>(),

            std::make_shared<euler::MultiplesOf3And5>(),
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

} // namespace src::challenges
