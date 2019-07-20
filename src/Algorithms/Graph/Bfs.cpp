#include <Algorithms/Graph/Bfs.hpp>

namespace src::algo::graph
{
namespace
{

common::Logger logger("Bfs");

} // namespace

const std::string Bfs::ALGORITHM_NAME_ = "Bfs";

Bfs::Bfs()
{
}

std::string Bfs::name() const
{
    return ALGORITHM_NAME_;
}

common::Result Bfs::run(std::istream&)// inputStream)
{
    return result_;
}

} // namespace src::algo::graph

/* Refactor this! Change to std::queue, do early return if node is already visited, etc.
#include <iostream>
#include <map>
#include <set>
#include <deque>
#include <vector>

#include <boost/algorithm/string.hpp>

struct Node
{
    std::string id;
    bool isVisited;
    std::set<Node*> connectedNodes;
    std::vector<Node*> pathToThisNode;
};

typedef std::map<std::string, Node*> IdAndNodeMap;

IdAndNodeMap parseInput(const std::string& input)
{
    IdAndNodeMap idAndNodeMap;
    std::vector<std::string> connectedInputs;
    boost::split(connectedInputs, input, boost::is_any_of(" "));
    for (const auto& connectedInput : connectedInputs)
    {
        std::vector<std::string> connected;
        boost::split(connected, connectedInput, boost::is_any_of("-"));
        if (connected.size() != 2) continue;

        if (!idAndNodeMap[connected[0]])
        {
            idAndNodeMap[connected[0]] = new Node({connected[0], false, {}, {}});
        }
        if (!idAndNodeMap[connected[1]])
        {
            idAndNodeMap[connected[1]] = new Node({connected[1], false, {}, {}});
        }

        auto& lhs = idAndNodeMap[connected[0]];
        auto& rhs = idAndNodeMap[connected[1]];

        lhs->connectedNodes.insert(rhs);
        rhs->connectedNodes.insert(lhs);
    }

    for (const auto& a : idAndNodeMap)
    {
        std::cout << "\n" << a.first << "\t";
        for (const auto& b : a.second->connectedNodes)
            std::cout << " " << b->id;
    }
    return idAndNodeMap;
}

std::vector<Node*> getShortestPath(
    IdAndNodeMap idAndNodeMap,
    const std::string& source,
    const std::string& destination)
{
    std::deque<Node*> nodes;
    nodes.push_back(idAndNodeMap[source]);
    while (!nodes.empty())
    {
        auto currentNode = nodes.front();
        nodes.pop_front();
            std::cout << "\nDEBUG currentNode->id " << currentNode->id << " " << currentNode->isVisited;
        if (currentNode->isVisited) continue;
        currentNode->isVisited = true;
        currentNode->pathToThisNode.push_back(currentNode);
        for (const auto& connectedNode : currentNode->connectedNodes)
        {
            std::cout << "\nDEBUG \tbefore id " << connectedNode->id << " " << connectedNode->isVisited;
            for (auto a : connectedNode->pathToThisNode)
                std::cout << "\nDEBUG \t\tbefore connectedNode id " << a->id << " " << a->isVisited;
            if (connectedNode->isVisited) continue;

            if (connectedNode->pathToThisNode.empty())
                for (const auto& nodeInPath : currentNode->pathToThisNode)
                {
                    connectedNode->pathToThisNode.push_back(nodeInPath);
                }
            // connectedNode->pathToThisNode.push_back(connectedNode);
            if (connectedNode->id == destination)
            {
                connectedNode->pathToThisNode.push_back(connectedNode);
                return connectedNode->pathToThisNode;
            }
            nodes.push_back(connectedNode);
            std::cout << "\nDEBUG \tafter id " << connectedNode->id << " " << connectedNode->isVisited;
            for (auto a : connectedNode->pathToThisNode)
                std::cout << "\nDEBUG \t\tafter connectedNode id " << a->id << " " << a->isVisited;
        }
    }
    return {};
}

int main(int argc, char** argv)
{
    if (argc < 3) return 0;
    // auto idAndNodeMap = parseInput("A-C A-D C-A C-B C-D C-E B-C B-F D-A D-C D-G E-C F-B G-D");
    auto idAndNodeMap = parseInput("A-B B-D B-C B-G B-A C-B D-B D-E E-D E-F F-E F-G F-L G-B G-H G-F H-G H-I I-H I-J J-I J-K J-L K-J");
    auto result = getShortestPath(idAndNodeMap, argv[1], argv[2]);
    std::cout << "\n\nResult: ";
    for (const auto& a : result)
    {
        std::cout << a->id << " ";
    }
    std::cout << "\n";
    return 0;
}
*/
