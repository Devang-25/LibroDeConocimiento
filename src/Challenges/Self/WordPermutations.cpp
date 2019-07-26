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

bool my_next_permutation(std::string& stringToPermutateSorted)
{
    for (int ctr = stringToPermutateSorted.size() - 1; ctr > 0; --ctr)
    {
        if (stringToPermutateSorted[ctr] > stringToPermutateSorted[ctr-1])
        {
            std::sort((stringToPermutateSorted.begin() + ctr), stringToPermutateSorted.end());
            for (unsigned ctr2 = ctr; ctr2 < stringToPermutateSorted.size(); ++ctr2)
            {
                if (stringToPermutateSorted[ctr2] > stringToPermutateSorted[ctr-1])
                {
                    std::swap(stringToPermutateSorted[ctr2], stringToPermutateSorted[ctr-1]);
                    std::sort((stringToPermutateSorted.begin() + ctr), (stringToPermutateSorted.begin() + ctr2));
                    return true;
                }
            }
        }
    }
    return false;
}

void wordPermutateNotUsingStl(
    std::string stringToPermutateSorted,
    std::set<std::string>& permutations)
{
    do
    {
        permutations.insert(stringToPermutateSorted);
    }
    while (my_next_permutation(stringToPermutateSorted));
}

void wordPermutateUsingStl(
    std::string stringToPermutateSorted,
    std::set<std::string>& permutations)
{
    do
    {
        permutations.insert(stringToPermutateSorted);
    }
    while (std::next_permutation(stringToPermutateSorted.begin(), stringToPermutateSorted.end()));
}

template <typename T>
std::string transformContainerToString(const T& container)
{
    std::string result = "";
    for (const auto& item : container)
    {
        result += " " + item;
    }
    return result;
}

std::pair<std::string, unsigned> wordPermutations(
    const std::string& stringToPermutate,
    const unsigned sampleSize)
{
    std::string permutationsString = "";
    std::set<std::string> permutations;

    // Algorithm 1: Using STL library
    std::string stringToPermutateSorted = stringToPermutate;
    std::sort(stringToPermutateSorted.begin(), stringToPermutateSorted.end());
    wordPermutateUsingStl(stringToPermutateSorted, permutations);
    permutationsString = transformContainerToString(permutations);
    logger.print("Algorithm 1 result - NOTE: This DOES NOT CONSIDER the sample size) : ");
    logger.print("    Count: ", permutations.size());
    logger.print("    Permutations: ", permutationsString);

    // Algorithm 2: Using my version of the STL library
    permutationsString.clear();
    permutations.clear();
    std::string stringToPermutateSorted2 = stringToPermutate;
    std::sort(stringToPermutateSorted2.begin(), stringToPermutateSorted2.end());
    wordPermutateNotUsingStl(stringToPermutateSorted2, permutations);
    permutationsString = transformContainerToString(permutations);
    logger.print("Algorithm 2 result - NOTE: This DOES NOT CONSIDER the sample size) : ");
    logger.print("    Count: ", permutations.size());
    logger.print("    Permutations: ", permutationsString);

    // Algorithm 3: Using my own function
    permutationsString.clear();
    permutations.clear();
    wordPermutate(stringToPermutate, sampleSize, "", permutations);
    permutationsString = transformContainerToString(permutations);
    logger.print("Algorithm 3 result - NOTE: This DOES CONSIDER the sample size) : ");
    logger.print("    Count: ", permutations.size());
    logger.print("    Permutations: ", permutationsString);

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
