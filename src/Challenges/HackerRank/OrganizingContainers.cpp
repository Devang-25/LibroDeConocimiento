#include <Challenges/HackerRank/OrganizingContainers.hpp>

#include <bits/stdc++.h>

#include <boost/algorithm/string.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>
#include <Common/File/FileHandler.hpp>

namespace src::challenges::hacker
{
namespace
{

common::Logger logger("OrganizingContainers");

std::string organizingContainers(const std::vector<std::vector<int>>& container)
{
    std::unordered_map<int, int> ballAndCountMap;
    std::vector<int> containerTotalBallsCount;
    containerTotalBallsCount.reserve(container.size());

    for (const auto& balls : container)
    {
        int currentCount = 0;
        for (unsigned ctr = 0u; ctr < balls.size(); ++ctr)
        {
            int ballCount = balls.at(ctr);
            ballAndCountMap[ctr] += ballCount;
            currentCount += ballCount;
        }
        containerTotalBallsCount.push_back(currentCount);
    }
    for (const auto& totalCount : containerTotalBallsCount)
    {
        auto it = std::find_if(ballAndCountMap.begin(), ballAndCountMap.end(),
                                [&totalCount](const std::pair<int, int>& ballCount)
                                {
                                    return ballCount.second == totalCount;
                                });
        if (it == ballAndCountMap.end())
        {
            return "Impossible";
        }
        ballAndCountMap.erase(it);
    }
    return "Possible";
}

} // namespace

const std::string OrganizingContainers::CHALLENGE_NAME_ = "OrganizingContainers";

OrganizingContainers::OrganizingContainers()
{
}

std::string OrganizingContainers::name() const
{
    return CHALLENGE_NAME_;
}

common::Result OrganizingContainers::run(std::istream& inputStream)
{
    displayProblem();

    auto matrix = common::file::getMatrixFromStreams(inputStream, inputStream);
    auto result = organizingContainers(matrix);
    logger.print("Result: ", result);

    result_.set(result);
    return result_;
}

void OrganizingContainers::displayProblem() const
{
    logger.print("David has several containers, each with a number of balls in it.");
    logger.print("He has just enough containers to sort each type of ball he has into its own container.");
    logger.print("David wants to sort the balls using his sort method.");
    logger.print("As an example, David has n = 2 containers and 2 different types of balls, both of which are numbered from 0 to n - 1 = 1.");
    logger.print("The distribution of ball types per container are described by an n x n matrix of integers, M[container][type].");
    logger.print("For example, consider the following diagram for M = [[1,4],[2,3]]:");
    logger.print();
    logger.print("Matrix M:");
    logger.print("               Types");
    logger.print("                0  1");
    logger.print("               -----");
    logger.print("Containers  0 | 1  4");
    logger.print("            1 | 2  3");
    logger.print();
    logger.print("Container 0     Container 1");
    logger.print("Ball_0          Ball_0");
    logger.print("Ball_1          Ball_0");
    logger.print("Ball_1          Ball_1");
    logger.print("Ball_1          Ball_1");
    logger.print("Ball_1          Ball_1");
    logger.print();
    logger.print("In a single operation, David can swap two balls located in different containers.");
    logger.print("The diagram below depicts a single swap operation (swap BALL_1 from Container 0 with BALL_0 from Container 1):");
    logger.print();
    logger.print("Matrix M:");
    logger.print("               Types");
    logger.print("                0  1");
    logger.print("               -----");
    logger.print("Containers  0 | 2  3");
    logger.print("            1 | 1  4");
    logger.print();
    logger.print("David wants to perform some number of swap operations such that:");
    logger.print("1. Each container contains only balls of the same type.");
    logger.print("2. No two balls of the same type are located in different containers.");
    logger.print();
    logger.print("You must perform q queries where each query is in the form of a matrix, M.");
    logger.print("For each query, print Possible on a new line if David can satisfy the conditions above for the given matrix. Otherwise, print Impossible.");
    logger.print();
    logger.print("Input Format");
    logger.print("The first line contains an integer q, the number of queries.");
    logger.print("Each of the next q sets of lines is as follows:");
    logger.print("1. The first line contains an integer n, the number of containers (rows) and ball types (columns).");
    logger.print("2. Each of the next n lines contains n space-separated integers describing row M[i].");
    logger.print();
    logger.print("Sample Input 0");
    logger.print("2");
    logger.print("2");
    logger.print("1 1");
    logger.print("1 1");
    logger.print("2");
    logger.print("0 2");
    logger.print("1 1");
    logger.print("");
    logger.print("Sample Output 0");
    logger.print("Possible");
    logger.print("Impossible");
    logger.print();
    logger.print("Sample Input 1");
    logger.print("2");
    logger.print("3");
    logger.print("1 3 1");
    logger.print("2 1 2");
    logger.print("3 3 3");
    logger.print("3");
    logger.print("0 2 1");
    logger.print("1 1 1");
    logger.print("2 0 0");
    logger.print();
    logger.print("Sample Output 1");
    logger.print("Impossible");
    logger.print("Possible");
}

    // std::cout << "\n" << organizingContainers(//8, 0, 5, 4,
    //     {
    //         {0,1,2,0,2},
    //         {1,0,2,0,0},
    //         {2,1,0,1,0},
    //         {0,1,0,0,0},
    //         {2,0,0,0,1},
    //     });

    // std::cout << "\n" << organizingContainers(
    //     {
    //         {0,1,2,0,1},
    //         {1,0,2,0,0},
    //         {2,1,0,1,0},
    //         {0,1,0,0,0},
    //         {2,0,0,0,2},
    //     });

    // std::cout << "\n" << organizingContainers(
    //     {
    //         {0, 2, 1},
    //         {1, 1, 1},
    //         {2, 0, 0},
    //     });

    // std::cout << "\n" << organizingContainers(
    //     {
    //         {1, 3, 1},
    //         {2, 1, 2},
    //         {3, 3, 3},
    //     });

} // namespace src::challenges::hacker
