#include "MagicSquareFinder.hpp"

#include <map>
#include <unordered_map>
#include <unordered_set>

namespace src::magicsquare
{
namespace
{

void addCurrentColumnToSumOfAllRows(
    const std::vector<std::vector<int>>& matrix,
    const unsigned currentCol,
    std::unordered_map<unsigned, int>& rowAndSum,
    std::unordered_set<int>& allSums)
{
    for (auto& [row, sum] : rowAndSum)
    {
        sum += matrix[row][currentCol];
        allSums.insert(sum);
    }
}
void addCurrentRowToSumOfAllColumns(
    const std::vector<std::vector<int>>& matrix,
    const unsigned currentRow,
    std::unordered_map<unsigned, int>& colAndSum,
    std::unordered_set<int>& allSums)
{
    for (auto& [col, sum] : colAndSum)
    {
        sum += matrix[currentRow][col];
        allSums.insert(sum);
    }
}

void addCurrentDiagonalToSumOfDiagonal(
    const std::vector<std::vector<int>>& matrix,
    const unsigned currentRow,
    const unsigned currentCol,
    int& diagonalToRightSum,
    std::unordered_set<int>& allSums)
{
    diagonalToRightSum += matrix[currentRow][currentCol];
    allSums.insert(diagonalToRightSum);
}

void addNewEntryForCurrentColumn(
    const std::vector<std::vector<int>>& matrix,
    const unsigned currentCol,
    const unsigned startingRow,
    const unsigned endingRow,
    std::unordered_map<unsigned, int>& colAndSum,
    std::unordered_set<int>& allSums)
{
    colAndSum[currentCol] = 0;
    for (unsigned row = startingRow; row <= endingRow; ++row)
    {
        colAndSum[currentCol] += matrix[row][currentCol];
    }
    allSums.insert(colAndSum[currentCol]);
}

void addNewEntryForCurrentRow(
    const std::vector<std::vector<int>>& matrix,
    const unsigned currentRow,
    const unsigned startingColumn,
    const unsigned endingColumn,
    std::unordered_map<unsigned, int>& rowAndSum,
    std::unordered_set<int>& allSums)
{
    rowAndSum[currentRow] = 0;
    for (unsigned col = startingColumn; col <= endingColumn; ++col)
    {
        rowAndSum[currentRow] += matrix[currentRow][col];
    }
    allSums.insert(rowAndSum[currentRow]);
}

void addNewEntryForDiagonalToLeft(
    const std::vector<std::vector<int>>& matrix,
    const unsigned startingRow,
    const unsigned endingRow,
    const unsigned startingColumn,
    const unsigned endingColumn,
    std::unordered_set<int>& allSums)
{
    int diagonalToLeftSum = 0;
    for (unsigned row = startingRow, col = startingColumn;
            row <= endingRow && col >= endingColumn;
            ++row, --col)
    {
        diagonalToLeftSum += matrix[row][col];
    }
    allSums.insert(diagonalToLeftSum);
}

} // namespace

src::data::SubMatrices getAllMagicSquaresSubMatrices(const std::vector<std::vector<int>>& matrix)
{
    unsigned rows = matrix.size();
    unsigned cols = matrix.empty() ?
                        0u :
                        matrix.front().size();

    src::data::SubMatrices foundSubMatrices;
    for (unsigned rowIndex = 0u; rowIndex < rows; ++rowIndex)
    {
        for (unsigned colIndex = 0u; colIndex < cols; ++colIndex)
        {
            // Find all possible submatrices that can be formed with the current corrdinate
            // {rowIndex, colIndex} as the starting point using Dynamic Programming.

            // The diagonalToLeftSum will not be tracked because there is no point of storing it as
            // it's elements will change after every iteration of row and column below
            std::unordered_map<unsigned, int> colAndSum{{colIndex, matrix[rowIndex][colIndex]}};
            std::unordered_map<unsigned, int> rowAndSum{{rowIndex, matrix[rowIndex][colIndex]}};
            int diagonalToRightSum = matrix[rowIndex][colIndex];

            for (unsigned currentCol = colIndex + 1, currentRow = rowIndex + 1;
                    currentCol < cols && currentRow < rows;
                    ++currentCol, ++currentRow)
            {
                std::unordered_set<int> allSums;

                // Add currently iterating row and column to all previously added rows and columns in map
                addCurrentColumnToSumOfAllRows(matrix, currentCol, rowAndSum, allSums);
                addCurrentRowToSumOfAllColumns(matrix, currentRow, colAndSum, allSums);
                addCurrentDiagonalToSumOfDiagonal(matrix, currentRow, currentCol, diagonalToRightSum, allSums);

                // Add currently iterating row and column as a new entry to the map
                addNewEntryForCurrentColumn(matrix, currentCol, rowIndex, currentRow, colAndSum, allSums);
                addNewEntryForCurrentRow(matrix, currentRow, colIndex, currentCol, rowAndSum, allSums);

                if (allSums.size() != 1) continue;

                // This can technically be put above along with its "siblings" but considering that
                // this getting of sum of diagonal to the left is a little more expensive and that
                // the calculated value is only applicable to the current coordinate and is not anymore
                // applicable to the remaining iterations unlike the calculations made by its siblings,
                // thus it is unnecessary to calculate this everytime when we can simply do a boolean
                // check if the siblings calculations above are the same before calculating this diagonal.
                addNewEntryForDiagonalToLeft(matrix, rowIndex, currentRow, currentCol, colIndex, allSums);
                if (allSums.size() != 1) continue;

                foundSubMatrices.emplace(currentCol - colIndex + 1, src::data::Coordinate{rowIndex, colIndex});
            }
        }
    } 
    return foundSubMatrices;
}

} // namespace src::magicsquare
