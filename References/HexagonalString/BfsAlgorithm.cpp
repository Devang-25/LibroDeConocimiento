#include <BfsAlgorithm.hpp>

#include <iostream>
#include <deque>
#include <string>
#include <unordered_set>
#include <vector>

#include <Grid.hpp>

namespace algo
{

BfsAlgorithm::BfsAlgorithm(
    const std::string& targetString) :
        targetString_(targetString),
        totalCount_(0)
{
    prepareGraph();
}

BfsAlgorithm::~BfsAlgorithm()
{
    for (unsigned row = 0; row < graph_.size(); ++row)
    {
        for (unsigned col = 0; col < graph_[row].size(); ++col)
        {
            delete graph_[row][col];
        }
    }
}

const std::string BfsAlgorithm::NAME = "BfsAlgorithm";

void BfsAlgorithm::prepareGraph()
{
    createNodes();
    connectNodes();
}

void BfsAlgorithm::createNodes()
{
    graph_.reserve(grid::HEXAGONAL_GRID.size());
    for (unsigned row = 0; row < grid::HEXAGONAL_GRID.size(); ++row)
    {
        graph_.push_back({});
        graph_.back().reserve(grid::HEXAGONAL_GRID[row].size());
        for (unsigned col = 0; col < grid::HEXAGONAL_GRID[row].size(); ++col)
        {
            graph_.back().push_back(new Node{grid::HEXAGONAL_GRID[row][col], {}, {}});
        }
    }
}

void BfsAlgorithm::connectNodes()
{
    for (int row = 0; row < static_cast<int>(graph_.size()); ++row)
    {
        for (int col = 0; col < static_cast<int>(graph_[row].size()); ++col)
        {
            // connect current node to left side neighbor
            if (col - 1 >= 0) graph_[row][col]->connectedNodes.push_back(graph_[row][col-1]);

            // connect current node to right side neighbor
            if (col + 1 < static_cast<int>(graph_[row].size())) graph_[row][col]->connectedNodes.push_back(graph_[row][col+1]);

            // connect current node to top neighbors
            if (row - 1 >= 0)
            {
                if (row % 2)
                {
                    if (col - 1 >= 0) graph_[row][col]->connectedNodes.push_back(graph_[row-1][col-1]);
                }
                else
                {
                    if (col + 1 < static_cast<int>(graph_[row-1].size())) graph_[row][col]->connectedNodes.push_back(graph_[row-1][col+1]);
                }
                if (col < static_cast<int>(graph_[row-1].size())) graph_[row][col]->connectedNodes.push_back(graph_[row-1][col]);
            }

            // connect current node to bot neighbors
            if (row + 1 < static_cast<int>(graph_.size()))
            {
                if (row % 2)
                {
                    if (col - 1 >= 0) graph_[row][col]->connectedNodes.push_back(graph_[row+1][col-1]);
                }
                else
                {
                    if (col + 1 < static_cast<int>(graph_[row+1].size())) graph_[row][col]->connectedNodes.push_back(graph_[row+1][col+1]);
                }
                if (col < static_cast<int>(graph_[row+1].size())) graph_[row][col]->connectedNodes.push_back(graph_[row+1][col]);
            }
        }
    }
}

unsigned BfsAlgorithm::operator()()
{
    totalCount_ = 0;
    if (targetString_.empty()) return 0;

    for (int row = 0; row < static_cast<int>(graph_.size()); ++row)
    {
        for (int col = 0; col < static_cast<int>(graph_[row].size()); ++col)
        {
            countFromPoint(row, col);
        }
    }
    return totalCount_;
}

void BfsAlgorithm::countFromPoint(
    const int row,
    const int col)
{
    if (graph_[row][col]->data != targetString_[0])
    {
        return;
    }
    if (targetString_.size() == 1)
    {
        ++totalCount_;
        return;
    }

    std::deque<Node*> nodes{graph_[row][col]};

    // nodes.front()->visitedNodePaths.push_back({}); // some compilers reject this!
    nodes.front()->visitedNodePaths.push_back(std::unordered_set<Node*>());
    while (!nodes.empty())
    {
        auto currentNode = nodes.front();
        nodes.pop_front();
        unsigned currentIndex = currentNode->visitedNodePaths[0].size() + 1;
        for (auto& connected : currentNode->connectedNodes)
        {
            if (connected->data != targetString_[currentIndex]) continue;
            if (currentIndex == targetString_.size() - 1)
            {
                for (const auto& path : currentNode->visitedNodePaths)
                {
                    if (path.count(connected)) continue;
                    ++totalCount_;
                }
                continue;
            }

            bool isInitiallyEmpty = connected->visitedNodePaths.empty();
            bool isThereAValidPath = false; // without this, try input "AHYAR"
            for (const auto& path : currentNode->visitedNodePaths)
            {
                if (path.count(connected)) continue;

                isThereAValidPath = true;
                connected->visitedNodePaths.push_back(path);
                connected->visitedNodePaths.back().insert(currentNode);
            }
            if (isInitiallyEmpty && isThereAValidPath) nodes.push_back(connected);
        }
        currentNode->visitedNodePaths.clear();
    }
}

} // namespace algo
