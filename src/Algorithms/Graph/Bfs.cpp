#include <Algorithms/Graph/Bfs.hpp>

#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>

#include <boost/algorithm/string.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::algo::graph
{
namespace
{

common::Logger logger("Bfs");

struct Node
{
    std::string id;
    bool isVisited;
    std::set<Node*> connectedNodes;
    std::vector<Node*> pathToThisNode;
};

using IdAndNodeMap = std::map<std::string, Node*>;

struct UserInput
{
    IdAndNodeMap idAndNodeMap;
    std::string source;
    std::string destination;
};

void connectNodes(Node* lhs, Node* rhs)
{
    lhs->connectedNodes.insert(rhs);
    rhs->connectedNodes.insert(lhs);
}

void printIdAndNodeMap(const IdAndNodeMap& idAndNodeMap)
{
    logger.print("Printing IdAndNodeMap structure...");
    for (const auto& pair : idAndNodeMap)
    {
        logger.printNoFormatting("\n", pair.first, "\t");
        for (const auto& conn : pair.second->connectedNodes)
        {
            logger.printNoFormatting(conn->id, " ");
        }
    }
}

std::string transformToString(const std::vector<Node*>& nodes)
{
    std::string str = "";
    for (const auto& node : nodes)
    {
        str += "->" + node->id;
    }
    return str;
}

void clearNodePaths(IdAndNodeMap& idAndNodeMap)
{
    for (auto& pair : idAndNodeMap)
    {
        pair.second->pathToThisNode.clear();
    }
}

void deleteNodes(IdAndNodeMap& idAndNodeMap)
{
    for (auto& pair : idAndNodeMap)
    {
        delete pair.second;
    }
}

UserInput parseInput(const std::string& input)
{
    std::vector<std::string> connectedInputs;
    boost::split(connectedInputs, input, boost::is_any_of(" "));

    UserInput userInput = {{}, {}, {}};
    for (unsigned ctr = 0u; ctr < connectedInputs.size(); ctr++)
    {
        std::vector<std::string> connected;
        boost::split(connected, connectedInputs[ctr], boost::is_any_of("-"));

        if (connected.size() != 2) continue;

        if (!userInput.idAndNodeMap[connected[0]])
        {
            userInput.idAndNodeMap[connected[0]] = new Node({connected[0], false, {}, {}});
        }
        if (!userInput.idAndNodeMap[connected[1]])
        {
            userInput.idAndNodeMap[connected[1]] = new Node({connected[1], false, {}, {}});
        }

        if ((ctr + 1) == connectedInputs.size())
        {
            userInput.source = connected[0];
            userInput.destination = connected[1];
        }
        else
        {
            connectNodes(userInput.idAndNodeMap[connected[0]], userInput.idAndNodeMap[connected[1]]);
        }
    }

    printIdAndNodeMap(userInput.idAndNodeMap);
    return userInput;
}

std::vector<Node*> getShortestPath(UserInput userInput)
{
    clearNodePaths(userInput.idAndNodeMap);

    std::queue<Node*> nodes;
    nodes.push(userInput.idAndNodeMap.at(userInput.source));

    while (!nodes.empty())
    {
        auto currentNode = nodes.front();
        nodes.pop();

        if (currentNode->isVisited) continue;

        currentNode->isVisited = true;
        currentNode->pathToThisNode.push_back(currentNode);

        for (auto& connectedNode : currentNode->connectedNodes)
        {
            if (connectedNode->isVisited || !connectedNode->pathToThisNode.empty())
            {
                // connectedNode does not need to be processed anymore if it is either:
                // 1. Already pushed to stack and processing is done, thus it is already checked
                // 2. Another node connected to this connectedNode has already reached this connectedNode and already placed its own path, thus currentNode is already behind the node that was first to put its path to this connectedNode
                continue;
            }

            for (const auto& currentNodePath : currentNode->pathToThisNode)
            {
                // In line with my comment above for checking of connectedNode, this operation here marks that the currentNode is the first one to reach this particular connectedNode and thus worthy to bear its path which is assumed to be the shortest
                connectedNode->pathToThisNode.push_back(currentNodePath);
            }

            if (connectedNode->id == userInput.destination)
            {
                connectedNode->pathToThisNode.push_back(connectedNode);
                return connectedNode->pathToThisNode;
            }

            nodes.push(connectedNode);
        }
    }

    return {};
}

std::string bfs(const std::string& input)
{
    auto userInput = parseInput(input);
    auto nodesPath = getShortestPath(userInput);
    auto result = transformToString(nodesPath);
    deleteNodes(userInput.idAndNodeMap);
    return result;
}

} // namespace

const std::string Bfs::ALGORITHM_NAME_ = "Bfs";

Bfs::Bfs()
{
}

std::string Bfs::name() const
{
    return ALGORITHM_NAME_;
}

common::Result Bfs::run(std::istream& inputStream)
{
    displayGuide();
    auto input = common::getUserInputString(inputStream);
    auto result = bfs(input);
    logger.print("Result: ", result);

    result_.set(result);
    return result_;
}

void Bfs::displayGuide() const
{
    logger.print("Enter connected nodes via dash (-) separated from other connected nodes by spaces.");
    logger.print("The last part of the input would be the nodes to be searched for the shortest path.");
    logger.print("For example, if we have the following node connection for vertices A, B, C, D, E, and F and we want to find shortest path from point E to D:");
    logger.print("    A-------------B-------------F");
    logger.print("    |             |");
    logger.print("    |      E      |");
    logger.print("    | _____|      |");
    logger.print("    |/            |");
    logger.print("    C-------------D");
    logger.print("Input must be:");
    logger.print("    A-B A-C B-A B-D B-F C-A C-E C-D D-B D-C F-B E-D");
    logger.print("Note:");
    logger.print("    Repeating connections such as B-A (which is already same to A-B) does not necessarily need to be entered, with or without the duplicate doesn't matter, just here for clarity.");
    logger.print("    The last nodes E-D would be treated as the nodes to be searched for the shortest path.");
    // auto idAndNodeMap = parseInput("A-B B-D B-C B-G B-A C-B D-B D-E E-D E-F F-E F-G F-L G-B G-H G-F H-G H-I I-H I-J J-I J-K J-L K-J");
}

} // namespace src::algo::graph
