#ifndef SRC_MATRIXDATA_HPP
#define SRC_MATRIXDATA_HPP

#include <map>

namespace src::data
{

using SquareSize = unsigned;

struct Coordinate
{
    unsigned row;
    unsigned col;
};

using SubMatrices = std::multimap<SquareSize, Coordinate>;

} // namespace src::data

#endif // SRC_MATRIXDATA_HPP
