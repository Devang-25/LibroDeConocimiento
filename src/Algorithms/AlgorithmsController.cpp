#include <Algorithms/AlgorithmsController.hpp>

#include <algorithm>

#include <Algorithms/AlgorithmsGetter.hpp>
#include <Algorithms/IAlgorithm.hpp>
#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::algo
{
namespace
{

common::Logger logger("AlgorithmsController");

bool doesStringContainOnlyDigits(const std::string& str)
{
    return !str.empty() &&
            std::all_of(str.begin(), str.end(), ::isdigit);
}

} // namespace

AlgorithmsController::AlgorithmsController()
{
}

void AlgorithmsController::execute()
{
    auto algorithms = getAllAlgorithms();
    const auto algorithmsNameAndIdMap = getAlgorithmsNameAndIdMap(algorithms);
    bool keepRunning = true;

    while (keepRunning)
    {
        displayUserInputOptions();
        auto input = common::getUserInputString();
        processUserInput(input, algorithms, algorithmsNameAndIdMap, keepRunning);
    }
}

void AlgorithmsController::displayUserInputOptions() const
{
    logger.print();
    logger.print("What algorithm do you want to run?");
    logger.print(" - To see list of available algorithms, enter <listall>");
    logger.print(" - If you already know the name or ID of the algorithm, enter either the <AlgorithmID> or the <AlgorithmName>");
    logger.print(" - To exit, enter <exit>");
}

void AlgorithmsController::processUserInput(
    const std::string& input,
    const std::vector<std::shared_ptr<IAlgorithm>>& algorithms,
    const std::map<std::string, unsigned>& algorithmsNameAndIdMap,
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
            for (unsigned ctr = 0; ctr < algorithms.size(); ctr++)
            {
                logger.print("ID:", ctr, "\tName:", algorithms[ctr]->name());
            }
            break;
        }

        case UserInputCategory::AlgorithmId :
        {
            unsigned id = static_cast<unsigned>(std::stoul(input));
            if (id < algorithms.size()) algorithms[id]->run();
            else                        logger.print("Invalid AlgorithmID, out of range = ", id);
            break;
        }

        case UserInputCategory::AlgorithmName :
        {
            if (algorithmsNameAndIdMap.count(input) != 0)
            {
                unsigned id = algorithmsNameAndIdMap.at(input);
                algorithms[id]->run();
            }
            else
            {
                logger.print("Invalid AlgorithmName, not existing = ", input);
            }
            break;
        }

        default: logger.print("Unrecognized user input. Try again.");
    }
}

UserInputCategory AlgorithmsController::parseUserInputCategory(const std::string& userInput) const
{
    if (userInput == "exit")                         return UserInputCategory::Exit;
    else if (userInput == "listall")                 return UserInputCategory::ListAll;
    else if (doesStringContainOnlyDigits(userInput)) return UserInputCategory::AlgorithmId;
    else                                             return UserInputCategory::AlgorithmName;
}

} // namespace src::algo
