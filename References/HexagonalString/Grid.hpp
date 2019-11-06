#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

namespace grid
{

static const std::vector<std::vector<char>> HEXAGONAL_GRID
    {
        {  'H', 'A', 'R', 'X', 'Y'},
        {'H', 'E', 'P', 'R', 'Z', 'P'},
        {  'X', 'A', 'G', 'Y', 'R'},
        {'I', 'H', 'O', 'E', 'A', 'H'},
        {  'H', 'N', 'H', 'X', 'G'},
        {'A', 'Y', 'R', 'P', 'H', 'O'},
        {  'H', 'A', 'J', 'Q', 'N'},
    };

inline bool isWithinGridBounds(
    const int row,
    const int col)
{
    return row >= 0 &&
            row < static_cast<int>(HEXAGONAL_GRID.size()) &&
            col >= 0 &&
            col < static_cast<int>(HEXAGONAL_GRID[row].size());
}

} // namespace grid

#endif // GRID_HPP
