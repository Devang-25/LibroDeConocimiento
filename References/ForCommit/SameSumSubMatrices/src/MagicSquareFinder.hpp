#ifndef SRC_MAGICSQUAREFINDER_HPP
#define SRC_MAGICSQUAREFINDER_HPP

#include <map>
#include <vector>

#include "MatrixData.hpp"

namespace src::magicsquare
{

src::data::SubMatrices getAllMagicSquaresSubMatrices(const std::vector<std::vector<int>>& matrix);

} // namespace src::magicsquare

#endif // SRC_MAGICSQUAREFINDER_HPP
