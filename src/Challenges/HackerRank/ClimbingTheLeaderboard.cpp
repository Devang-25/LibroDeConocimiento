#include <Challenges/HackerRank/ClimbingTheLeaderboard.hpp>

#include <bits/stdc++.h>

#include <boost/algorithm/string.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::hacker
{
namespace
{

common::Logger logger("ClimbingTheLeaderboard");

enum class Scorer
{
    Alice,
    Others,
    AliceAndOthers,
};

using Score = int;
using ScoreAndScorerPair = std::pair<Score, Scorer>;

void removeOutdatedAliceScores(
    const int currentdAliceIndex,
    std::list<std::pair<Score, Scorer>>& scoreAndScorerList)
{
    int itIndex = 0;
    for (auto it = scoreAndScorerList.begin(); it != scoreAndScorerList.end(); ++it, ++itIndex)
    {
        if (itIndex == currentdAliceIndex) continue;

        if (it->second == Scorer::AliceAndOthers) it->second = Scorer::Others;
        else if (it->second == Scorer::Alice)     it = --(scoreAndScorerList.erase(it));
    }
}

std::vector<int> climbingLeaderboard(
    const std::vector<int>& scores,
    const std::vector<int>& alice)
{
    std::vector<int> aliceRankings;

    std::set<int> scoresSet{scores.begin(), scores.end()};
    std::list<ScoreAndScorerPair> scoreAndScorerList;
    for (int ctr = scoresSet.size() - 1; ctr >= 0; --ctr)
    {
        int score = *(std::next(scoresSet.begin(), ctr));
        scoreAndScorerList.insert(scoreAndScorerList.end(), {score, Scorer::Others});
    }

    for (const auto& aliceScore : alice)
    {
        int currentAliceRank = 1;
        bool isAliceRankingFound = false;

        int itIndex = 0;
        for (auto it = scoreAndScorerList.begin(); it != scoreAndScorerList.end() && !isAliceRankingFound; ++it, ++itIndex)
        {
            auto& [score, scorer] = *it;
            if (aliceScore > score)
            {
                aliceRankings.push_back(currentAliceRank);
                scoreAndScorerList.insert(it, {aliceScore, Scorer::Alice});

                removeOutdatedAliceScores(itIndex, scoreAndScorerList);
                isAliceRankingFound = true;
            }
            else if (aliceScore == score)
            {
                aliceRankings.push_back(currentAliceRank);
                if (scorer == Scorer::Others) scorer = Scorer::AliceAndOthers;

                removeOutdatedAliceScores(itIndex, scoreAndScorerList);
                isAliceRankingFound = true;
            }

            if (scorer != Scorer::Alice) ++currentAliceRank;
        }
        if (!isAliceRankingFound)
        {
            aliceRankings.push_back(currentAliceRank);
            scoreAndScorerList.insert(scoreAndScorerList.end(), {aliceScore, Scorer::Alice});

            removeOutdatedAliceScores(itIndex, scoreAndScorerList);
        }
    }

    return aliceRankings;
}

std::vector<int> parseInput(const std::string& input)
{
    std::vector<std::string> inputs;
    boost::split(inputs, input, boost::is_any_of(" "));

    std::vector<int> intInputs;
    intInputs.reserve(inputs.size());
    for (const auto& in : inputs)
    {
        intInputs.push_back(std::stoi(in));
    }

    return intInputs;
}

template <typename T>
std::string transformContainerToString(const T& container)
{
    std::string result = "";
    for (const auto& item : container)
    {
        result += " " + std::to_string(item);
    }
    return result;
}

std::string climbingLeaderboard(
    const std::string& scoresString,
    const std::string& aliceScoresString)
{
    auto result = climbingLeaderboard(parseInput(scoresString), parseInput(aliceScoresString));
    return transformContainerToString(result);
}

} // namespace

const std::string ClimbingTheLeaderboard::CHALLENGE_NAME_ = "ClimbingTheLeaderboard";

ClimbingTheLeaderboard::ClimbingTheLeaderboard()
{
}

std::string ClimbingTheLeaderboard::name() const
{
    return CHALLENGE_NAME_;
}

common::Result ClimbingTheLeaderboard::run(std::istream& inputStream)
{
    displayProblem();

    logger.print("Enter all scores in descending order:");
    auto scoresString = common::getUserInputString(inputStream);

    logger.print("Enter scores of Alice:");
    auto aliceScoresString = common::getUserInputString(inputStream);

    auto result = climbingLeaderboard(scoresString, aliceScoresString);
    logger.print("Result: ", result);

    result_.set(result);
    return result_;
}

void ClimbingTheLeaderboard::displayProblem() const
{
    logger.print("Alice is playing an arcade game and wants to climb to the top of the leaderboard and wants to track her ranking.");
    logger.print(" The game uses Dense Ranking, so its leaderboard works like this:");
    logger.print("- The player with the highest score is ranked number 1 on the leaderboard.");
    logger.print("- Players who have equal scores receive the same ranking number, and the next player(s) receive the immediately following ranking number.");
    logger.print("For example, the four players on the leaderboard have high scores of 100, 90, 90, and 80.");
    logger.print("Those players will have ranks 1, 2, 2, and 3, respectively.");
    logger.print("If Alice's scores are 70, 80 and 105, her rankings after each game are 4th, 3rd and 1st.");
    logger.print("Sample input:");
    logger.print("    All scores:  100 90 90 80");
    logger.print("    Alice score: 70 80 105");
    logger.print("Output");
    logger.print("    4 3 1");
}

} // namespace src::challenges::hacker
