#ifndef SRC_MATRIXOUTPUTTER_HPP
#define SRC_MATRIXOUTPUTTER_HPP

#include <iostream>
#include <vector>

#include "MatrixData.hpp"

namespace src::output
{

void streamMatrixAndSubMatrices(
    const std::vector<std::vector<int>>& matrix,
    const src::data::SubMatrices& subMatrices,
    std::ostream& oss = std::cout);

template <typename T>
void streamMatrix(
    const T& t,
    std::ostream& oss = std::cout)
{
    oss << "\nMatrix";
    for (const auto& n : t)
    {
        oss << "\n";
        for (const auto& m : n)
        {
            oss << " " << m;
        }
    }
    oss << "\n";
}

void streamSubMatrices(
    const std::vector<std::vector<int>>& matrix,
    const src::data::SubMatrices& subMatrices,
    std::ostream& oss = std::cout);

} // namespace src::output

#endif // SRC_MATRIXOUTPUTTER_HPP
