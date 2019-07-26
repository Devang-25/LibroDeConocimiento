#include <Challenges/HackerRank/MagicSquare.hpp>

#include <bits/stdc++.h> // I got it from HackerRank, pretty cool :D

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::hacker
{
namespace
{

common::Logger logger("MagicSquare");

class ICombinationsGetters
{
public:
    virtual ~ICombinationsGetters(){}
    virtual std::vector<std::vector<int>> operator()() const = 0;

protected:
    // Upon research, the magic square  numbers are constant. If you would ask, are there other number
    // combinations possible that is different than this set of const numbers? Seems none. Take note
    // though that you can rotate this const numbers and still arrive with a magic square.
    const std::vector<std::vector<int>> COMBINATIONS
    {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8},
    };
};

class GetDefault : public ICombinationsGetters
{
public:
    GetDefault()
    {
    }

    std::vector<std::vector<int>> operator()() const
    {
        return COMBINATIONS;
    }
};

class GetReverseOfDefault : public ICombinationsGetters
{
public:
    GetReverseOfDefault()
    {
    }

    std::vector<std::vector<int>> operator()() const
    {
        auto combinationsCopy = COMBINATIONS;
        for (auto& vec : combinationsCopy)
        {
            std::reverse(vec.begin(), vec.end());
        }
        return combinationsCopy;
    }
};

class GetVerticalOfDefault : public ICombinationsGetters
{
public:
    GetVerticalOfDefault()
    {
    }

    std::vector<std::vector<int>> operator()() const
    {
        auto combinationsCopy = COMBINATIONS;
        for (unsigned ctr = 0u; ctr < COMBINATIONS.size(); ++ctr)
        {
            for (unsigned ctr2 = 0u; ctr2 < COMBINATIONS.at(ctr).size(); ++ctr2)
            {
                combinationsCopy[ctr][ctr2] = COMBINATIONS.at(ctr2).at(ctr);
            }
        }
        return combinationsCopy;
    }
};

class GetReverseOfVerticalOfDefault : public ICombinationsGetters
{
public:
    GetReverseOfVerticalOfDefault()
    {
    }

    std::vector<std::vector<int>> operator()() const
    {
        auto combinationsCopy = GetVerticalOfDefault()();
        for (auto& vec : combinationsCopy)
        {
            std::reverse(vec.begin(), vec.end());
        }
        return combinationsCopy;
    }
};

std::vector<std::vector<std::vector<int>>> getPossibleCombinations()
{
    return
        {
            GetDefault()(),
            GetReverseOfDefault()(),
            GetVerticalOfDefault()(),
            GetReverseOfVerticalOfDefault()(),
        };
}

int getDifference(
    const std::vector<int>& vec1,
    const std::vector<int>& vec2)
{
    int totalDiff = 0;
    for (unsigned ctr = 0u; ctr < vec1.size() && ctr < vec2.size(); ++ctr)
    {
        int diff = vec1[ctr] - vec2[ctr];
        if (diff < 0) diff = diff * -1;
        totalDiff += diff;
    }
    return totalDiff;
}

int getDifferenceOfTransformation(
    const std::vector<std::vector<int>>& original,
    const std::vector<std::vector<int>>& target)
{
    const int TOP = 0;
    const int MIDDLE = 1;
    const int BOTTOM = 2;

    int midMidDiff = getDifference(original.at(MIDDLE), target.at(MIDDLE));

    int topTopAndBotBotDiff = getDifference(original.at(TOP), target.at(TOP)) +
                                getDifference(original.at(BOTTOM), target.at(BOTTOM));
    int topBotAndBotTopDiff = getDifference(original.at(TOP), target.at(BOTTOM)) +
                                getDifference(original.at(BOTTOM), target.at(TOP));

    return topTopAndBotBotDiff > topBotAndBotTopDiff ?
            midMidDiff + topBotAndBotTopDiff :
            midMidDiff + topTopAndBotBotDiff;
}

template <class T>
void printContainerOfContainers(const T& t)
{
    logger.print("Printing container...");
    for (const auto& container : t)
    {
        logger.printNoFormatting("\n");
        for (const auto& item : container)
        {
            logger.printNoFormatting(item, " ");
        }
    }
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(const std::vector<std::vector<int>>& s)
{
    int currentDiff = 0;
    int minDiff  = std::numeric_limits<int>::max();

    for (const auto& combination : getPossibleCombinations())
    {
        currentDiff = getDifferenceOfTransformation(s, combination);
        if (currentDiff < minDiff)
        {
            minDiff = currentDiff;
            logger.print ("Found new min: ", minDiff);
            printContainerOfContainers(combination);
        }
    }

    return minDiff;
}

std::vector<std::vector<int>> parseInput(const std::string& input)
{
    std::vector<std::vector<int>> parsed;

    parsed.resize(3);
    for (auto& vec : parsed)
    {
        vec.resize(3);
    }

    unsigned x = 0;
    unsigned y = 0;
    for (const auto& ch : input)
    {
        if (ch < '0' || ch > '9') continue;
        parsed[x][y++] = ch - '0';

        if (y == 3)
        {
            ++x;
            y = 0;
        }
    }

    logger.print("Parsed input");
    printContainerOfContainers(parsed);
    return parsed;
}

int magicSquare(const std::string& input)
{
    auto parsed = parseInput(input);
    return formingMagicSquare(parsed);
}

} // namespace

const std::string MagicSquare::CHALLENGE_NAME_ = "MagicSquare";

MagicSquare::MagicSquare()
{
}

std::string MagicSquare::name() const
{
    return CHALLENGE_NAME_;
}

common::Result MagicSquare::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputString(inputStream);
    auto result = magicSquare(input);
    logger.print("Result: ", result);

    result_.set(result);
    return result_;
}

void MagicSquare::displayProblem() const
{
    logger.print("We define a magic square to be an [n x n] matrix of distinct positive integers from 1 to n^2 where the sum of any row, column, or diagonal of length n is always equal to the same number: the magic constant.");
    logger.print("You will be given a [3 x 3] matrix s of integers in the inclusive range [1, 9]. We can convert any digit a to any other digit b in the range [1, 9] at cost of |a-b|.");
    logger.print("Given s, convert it into a magic square at minimal cost. Print this cost on a new line.");
    logger.print("Note: The resulting magic square must contain distinct integers in the inclusive range [1, 9].");
    logger.print("For example, we start with the following matrix :");
    logger.print("    5 3 4");
    logger.print("    1 5 8");
    logger.print("    6 4 2");
    logger.print("We can convert it to the following magic square:");
    logger.print("    8 3 4");
    logger.print("    1 5 9");
    logger.print("    6 7 2");
    logger.print("This took three replacements at a cost of |5-8| + |8-9| + |4-7| = 7");
    logger.print("Sample Test Cases");
    logger.print("Input: 5 3 4 1 5 8 6 4 2");
    logger.print("Output: 7");
    logger.print("Input: 4 9 2 3 5 7 8 1 5");
    logger.print("Output: 1");
    logger.print("Input: 4 8 2 4 5 7 6 1 6");
    logger.print("Output: 4");
    logger.print("Input: 2 7 6 8 5 1 4 4 6");
    logger.print("Output: 4");
}

} // namespace src::challenges::hacker
