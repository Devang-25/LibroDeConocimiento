#ifndef SRC_CODERBYTE_CHALLENGES_CHALLENGESGETTER_HPP
#define SRC_CODERBYTE_CHALLENGES_CHALLENGESGETTER_HPP

#include <map>
#include <memory>
#include <vector>

namespace src::coderbyte::challenges
{

class IChallenge;

std::vector<std::shared_ptr<IChallenge>> getAllChallenges();

std::map<std::string, unsigned> getChallengesNameAndIdMap(
    const std::vector<std::shared_ptr<IChallenge>>& challenges);

} // namespace src::coderbyte::challenges

#endif // SRC_CODERBYTE_CHALLENGES_CHALLENGESGETTER_HPP
