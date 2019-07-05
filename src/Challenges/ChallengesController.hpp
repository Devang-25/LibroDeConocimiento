#ifndef SRC_CHALLENGES_CHALLENGESCONTROLLER_HPP
#define SRC_CHALLENGES_CHALLENGESCONTROLLER_HPP

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <IController.hpp>

namespace src::challenges
{

class IChallenge;

enum class UserInputCategory
{
    Exit,
    ListAll,
    ChallengeId,
    ChallengeName,
};

class ChallengesController : public IController
{
public:
    ChallengesController();

    virtual void execute() override;

private:
    void displayUserInputOptions() const;

    void processUserInput(
        const std::string& input,
        const std::vector<std::shared_ptr<IChallenge>>& challenges,
        const std::map<std::string, unsigned>& challengesNameAndIdMap,
        bool& keepRunning) const;

    UserInputCategory parseUserInputCategory(const std::string& userInput) const;
};

} // namespace src::challenges

#endif // SRC_CHALLENGES_CHALLENGESCONTROLLER_HPP
