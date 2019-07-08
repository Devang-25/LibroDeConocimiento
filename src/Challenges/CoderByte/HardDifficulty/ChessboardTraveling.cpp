#include <Challenges/CoderByte/HardDifficulty/ChessboardTraveling.hpp>

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <string>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::coderbyte::hard
{
namespace
{

using RowColPair = std::pair<int, int>;

common::Logger logger("ChessboardTraveling");

struct Coordinates
{
    int x;
    int y;
    int a;
    int b;
};

struct Node
{
    int row;
    int col;

    std::vector<Node*> connected;
};

std::string getNumbers(const std::string& stringInput)
{
    std::string numbers = "";
    for (unsigned ctr = 0; ctr < stringInput.size(); ctr++)
    {
        if (stringInput.at(ctr) >= '0' &&
            stringInput.at(ctr) <= '9')
        {
            numbers = numbers + stringInput.at(ctr);
        }
    }
    return numbers;
}

Coordinates getCoordinates(const std::string& stringInput)
{
    std::string numbers = getNumbers(stringInput);

    if (numbers.size() != 4) return {};

    Coordinates coordinates
    {
        numbers.at(0) - '0',
        numbers.at(1) - '0',
        numbers.at(2) - '0',
        numbers.at(3) - '0',
    };
    return coordinates;
}

void createNewNodes(
    const Coordinates& coordinates,
    std::map<RowColPair, Node*>& nodesMap)
{
    for (int row = coordinates.x; row <= coordinates.a; row++)
    {
        for (int col = coordinates.y; col <= coordinates.b; col++)
        {
            nodesMap[{row, col}] = new Node({row, col, {}});
        }
    }
}

void setHorizontalNodeConnections(
    const Coordinates& coordinates,
    std::map<RowColPair, Node*>& nodesMap)
{
    for (int row = coordinates.x; row <= coordinates.a; row++)
    {
        for (int col = coordinates.y; col < coordinates.b; col++)
        {
            auto& currentNode = nodesMap[{row, col}];
            auto& nextNode = nodesMap[{row, col+1}];

            currentNode->connected.push_back(nextNode);
        }
    }
}

void setVerticalNodeConnections(
    const Coordinates& coordinates,
    std::map<RowColPair, Node*>& nodesMap)
{
    for (int col = coordinates.y; col <= coordinates.b; col++)
    {
        for (int row = coordinates.x; row < coordinates.a; row++)
        {
            auto& currentNode = nodesMap[{row, col}];
            auto& nextNode = nodesMap[{row+1, col}];

            currentNode->connected.push_back(nextNode);
        }
    }
}

std::vector<Node*> setupNodes(const Coordinates& coordinates)
{
    std::map<RowColPair, Node*> nodesMap;

    createNewNodes(coordinates, nodesMap);
    setHorizontalNodeConnections(coordinates, nodesMap);
    setVerticalNodeConnections(coordinates, nodesMap);

    std::vector<Node*> nodes;
    std::transform(nodesMap.begin(), nodesMap.end(), std::back_inserter(nodes),
                    [](const std::pair<RowColPair, Node*>& pair)
                    {
                        return pair.second;
                    });
    return nodes;
}

void printConnectedNodes(
    const Node* node,
    const std::string& tab)
{
    for (const auto& connectedNode : node->connected)
    {
        logger.print(tab, connectedNode->row, " ", connectedNode->col);
        printConnectedNodes(connectedNode, tab + "\t");
    }
}

void printNodeStructure(const std::vector<Node*>& nodes)
{
    for (const auto& node : nodes)
    {
        logger.print("Node : ", node->row, " ", node->col);
        printConnectedNodes(node, "\t\t");
    }
}

void countPathsReachingTargetNode(
    const Node* source,
    const Node* destination,
    unsigned& pathsCount)
{
    for (const auto& connectedNode : source->connected)
    {
        if (connectedNode == destination)
        {
            pathsCount++;
        }
        else
        {
            countPathsReachingTargetNode(connectedNode, destination, pathsCount);
        }
    }
}

unsigned countPathsReachingTargetCoordinates(
    const std::vector<Node*>& nodes,
    const Coordinates& coordinates)
{
    auto source = std::find_if(nodes.begin(), nodes.end(),
                                [&coordinates](const Node* node)
                                {
                                    return node->row == coordinates.x &&
                                            node->col == coordinates.y;
                                });
    auto destination = std::find_if(nodes.begin(), nodes.end(),
                                [&coordinates](const Node* node)
                                {
                                    return node->row == coordinates.a &&
                                            node->col == coordinates.b;
                                });
    if (source == nodes.end() || destination == nodes.end()) return 0;
    printNodeStructure({*source});

    unsigned pathsCount = 0;
    countPathsReachingTargetNode(*source, *destination, pathsCount);
    return pathsCount;
}

template<typename T>
void cleanPointersVector(std::vector<T*>& ptrVec)
{
    for (auto& ptr : ptrVec)
    {
        delete ptr;
    }
}

unsigned chessboardTraveling(const std::string& stringInput)
{
    Coordinates coordinates = getCoordinates(stringInput);
    std::vector<Node*> nodes = setupNodes(coordinates);

    unsigned totalCount = countPathsReachingTargetCoordinates(nodes, coordinates);
    cleanPointersVector(nodes);

    return totalCount;
}

} // namespace

const std::string ChessboardTraveling::CHALLENGE_NAME_ = "ChessboardTraveling";

ChessboardTraveling::ChessboardTraveling()
{
}

std::string ChessboardTraveling::name() const
{
    return CHALLENGE_NAME_;
}

common::Result ChessboardTraveling::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputString(inputStream);
    auto result = chessboardTraveling(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void ChessboardTraveling::displayProblem() const
{
    logger.print("Have the function ChessboardTraveling(str) read str which will be a string consisting of the location of a space on a standard 8x8 chess board with no pieces on the board along with another space on the chess board.");
    logger.print("The structure of str will be the following:");
    logger.print("\"(x y)(a b)\" where (x y) represents the position you are currently on with x and y ranging from 1 to 8 and (a b) represents some other space on the chess board with a and b also ranging from 1 to 8 where a > x and b > y.");
    logger.print("Your program should determine how many ways there are of traveling from (x y) on the board to (a b) moving only up and to the right.");
    logger.print("For example: if str is (1 1)(2 2) then your program should output 2 because there are only two possible ways to travel from space (1 1) on a chessboard to space (2 2) while making only moves up and to the right.");
    logger.print("Sample Test Cases");
    logger.print("Input:\"(1 1)(3 3)\"");
    logger.print("Output:6");
    logger.print("Input:\"(2 2)(4 3)\"");
    logger.print("Output:3");
}

} // namespace src::challenges::coderbyte::hard
