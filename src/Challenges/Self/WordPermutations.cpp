#include <Challenges/Self/WordPermutations.hpp>

#include <algorithm>
#include <set>
#include <string>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::self
{
namespace
{

common::Logger logger("WordPermutations");

void wordPermutate(
    const std::string& stringToPermutate,
    const unsigned sampleSize,
    const std::string& currentlyFormedString,
    std::set<std::string>& permutations)
{
    for (unsigned ctr = 0; ctr < stringToPermutate.size(); ctr++)
    {
        std::string newlyFormedString = currentlyFormedString + stringToPermutate[ctr];
        if (newlyFormedString.size() == sampleSize)
        {
            permutations.insert(newlyFormedString);
            continue;
        }

        std::string stringToPermutateCopy = stringToPermutate;
        stringToPermutateCopy.erase(stringToPermutateCopy.begin() + ctr);

        wordPermutate(stringToPermutateCopy, sampleSize, newlyFormedString, permutations);
    }
}

std::pair<std::string, unsigned> wordPermutations(
    const std::string& stringToPermutate,
    const unsigned sampleSize)
{
    std::set<std::string> permutations;
    wordPermutate(stringToPermutate, sampleSize, "", permutations);

    std::string permutationsString = "";
    for (const auto& item : permutations)
    {
        permutationsString += " " + item;
    }
    return {permutationsString, permutations.size()};
}

} // namespace

const std::string WordPermutations::CHALLENGE_NAME_ = "WordPermutations";

WordPermutations::WordPermutations()
{
}

std::string WordPermutations::name() const
{
    return CHALLENGE_NAME_;
}

common::Result WordPermutations::run(std::istream& inputStream)
{
    displayProblem();

    logger.print("Enter string to permutate:");
    auto stringToPermutate = common::getUserInputString(inputStream);
    logger.print("Enter sample size:");
    auto sampleSize = common::getUserInputIntegralOrFloating<unsigned>(inputStream);

    auto [permutations, count] = wordPermutations(stringToPermutate, sampleSize);
    logger.print("Result:");
    logger.print("    Count: ", count);
    logger.print("    Permutations: ", permutations);

    result_.set(permutations);
    return result_;
}

void WordPermutations::displayProblem() const
{
    logger.print("Jumble a string to all possible permutations.");
}

} // namespace src::challenges::self
