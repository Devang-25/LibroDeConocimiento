#include <RecursiveAlgorithm.hpp>

#include <string>
#include <unordered_set>
#include <utility>

#include <Grid.hpp>

namespace algo
{
namespace
{

std::pair<int, int> getColumnTopAndBotNeighbors(
    const int row,
    const int col)
{
    return row % 2 ?
            std::make_pair(col - 1, col) :
            std::make_pair(col, col + 1);
}

std::pair<int, int> getColumnSideNeighbors(
    const int col)
{
    return std::make_pair(col - 1, col + 1);
}

} // namespace

size_t PairHash::operator()(const std::pair<int, int>& intPair) const
{
    return std::hash<int>()(intPair.first) ^ std::hash<int>()(intPair.second);
}

RecursiveAlgorithm::RecursiveAlgorithm(
    const std::string& targetString) :
        targetString_(targetString),
        totalCount_(0)
{
}

const std::string RecursiveAlgorithm::NAME = "RecursiveAlgorithm";

unsigned RecursiveAlgorithm::operator()()
{
    totalCount_ = 0;
    for (int row = 0; row < static_cast<int>(grid::HEXAGONAL_GRID.size()); ++row)
    {
        for (int col = 0; col < static_cast<int>(grid::HEXAGONAL_GRID[row].size()); ++col)
        {
            // countFromPoint(row, col, 0, {}); // some compilers reject this!
            countFromPoint(row, col, 0, std::unordered_set<std::pair<int, int>, PairHash>());
        }
    }
    return totalCount_;
}

void RecursiveAlgorithm::countFromPoint(
    const int row,
    const int col,
    const unsigned currentIndex,
    std::unordered_set<std::pair<int, int>, PairHash> processedRowColPairs)
{
    if (!grid::isWithinGridBounds(row, col) ||
        processedRowColPairs.count({row, col}) ||
        grid::HEXAGONAL_GRID[row][col] != targetString_[currentIndex])
    {
        return;
    }
    else if (currentIndex == targetString_.size() - 1)
    {
        ++totalCount_;
        return;
    }

    processedRowColPairs.insert({row, col});
    auto colTopBotNeighbor = getColumnTopAndBotNeighbors(row, col);
    auto colSideNeighbor = getColumnSideNeighbors(col);

    // recursively traverse top neighbors
    countFromPoint(row - 1, colTopBotNeighbor.first, currentIndex + 1, processedRowColPairs);
    countFromPoint(row - 1, colTopBotNeighbor.second, currentIndex + 1, processedRowColPairs);

    // recursively traverse side neighbors
    countFromPoint(row, colSideNeighbor.first, currentIndex + 1, processedRowColPairs);
    countFromPoint(row, colSideNeighbor.second, currentIndex + 1, processedRowColPairs);

    // recursively traverse bot neighbors
    countFromPoint(row + 1, colTopBotNeighbor.first, currentIndex + 1, processedRowColPairs);
    countFromPoint(row + 1, colTopBotNeighbor.second, currentIndex + 1, processedRowColPairs);
}

} // namespace algo
