#include "MatrixOutputter.hpp"

#include <iostream>
#include <vector>

namespace src::output
{

void streamMatrixAndSubMatrices(
    const std::vector<std::vector<int>>& matrix,
    const src::data::SubMatrices& subMatrices,
    std::ostream& oss)
{
    streamMatrix(matrix, oss);
    streamSubMatrices(matrix, subMatrices, oss);
}

void streamSubMatrices(
    const std::vector<std::vector<int>>& matrix,
    const src::data::SubMatrices& subMatrices,
    std::ostream& oss)
{
    oss << "\nSubMatrices";
    for (const auto& [squareSize, coordinate] : subMatrices)
    {
        unsigned targetRowCoordinate = coordinate.row + squareSize - 1;
        unsigned targetColumnCoordinate = coordinate.col + squareSize - 1;
        for (unsigned currentRow = coordinate.row; currentRow <= targetRowCoordinate; ++currentRow)
        {
            oss << "\n";
            for (unsigned currentCol = coordinate.col; currentCol <= targetColumnCoordinate; ++currentCol)
            {
                oss << " " << matrix[currentRow][currentCol];
            }
        }
        oss << "\n";
    }
}

} // namespace src::output
