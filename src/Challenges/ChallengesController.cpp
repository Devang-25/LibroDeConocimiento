#include <Challenges/ChallengesController.hpp>

#include <algorithm>

#include <Challenges/ChallengesGetter.hpp>
#include <Challenges/IChallenge.hpp>
#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges
{
namespace
{

common::Logger logger("ChallengesController");

bool doesStringContainOnlyDigits(const std::string& str)
{
    return !str.empty() &&
            std::all_of(str.begin(), str.end(), ::isdigit);
}

} // namespace

ChallengesController::ChallengesController()
{
}

void ChallengesController::execute()
{
    auto challenges = getAllChallenges();
    const auto challengesNameAndIdMap = getChallengesNameAndIdMap(challenges);
    bool keepRunning = true;

    while (keepRunning)
    {
        displayUserInputOptions();
        auto input = common::getUserInputString();
        processUserInput(input, challenges, challengesNameAndIdMap, keepRunning);
    }
}

void ChallengesController::displayUserInputOptions() const
{
    logger.print();
    logger.print("What challenge do you want to run?");
    logger.print(" - To see list of available challenges, enter <listall>");
    logger.print(" - If you already know the name or ID of the challenge, enter either the <ChallengeID> or the <ChallengeName>");
    logger.print(" - To exit, enter <exit>");
}

void ChallengesController::processUserInput(
    const std::string& input,
    const std::vector<std::shared_ptr<IChallenge>>& challenges,
    const std::map<std::string, unsigned>& challengesNameAndIdMap,
    bool& keepRunning) const
{
    auto category = parseUserInputCategory(input);
    switch (category)
    {
        case UserInputCategory::Exit :
        {
            keepRunning = false;
            break;
        }

        case UserInputCategory::ListAll :
        {
            for (unsigned ctr = 0; ctr < challenges.size(); ctr++)
            {
                logger.print("ID:", ctr, "\tName:", challenges[ctr]->name());
            }
            break;
        }

        case UserInputCategory::ChallengeId :
        {
            unsigned id = static_cast<unsigned>(std::stoul(input));
            if (id < challenges.size()) challenges[id]->run();
            else                        logger.print("Invalid ChallengeID, out of range = ", id);
            break;
        }

        case UserInputCategory::ChallengeName :
        {
            if (challengesNameAndIdMap.count(input) != 0)
            {
                unsigned id = challengesNameAndIdMap.at(input);
                challenges[id]->run();
            }
            else
            {
                logger.print("Invalid ChallengeName, not existing = ", input);
            }
            break;
        }

        default: logger.print("Unrecognized user input. Try again.");
    }
}

UserInputCategory ChallengesController::parseUserInputCategory(const std::string& userInput) const
{
    if (userInput == "exit")                         return UserInputCategory::Exit;
    else if (userInput == "listall")                 return UserInputCategory::ListAll;
    else if (doesStringContainOnlyDigits(userInput)) return UserInputCategory::ChallengeId;
    else                                             return UserInputCategory::ChallengeName;
}

} // namespace src::challenges
