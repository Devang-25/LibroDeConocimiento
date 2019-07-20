#ifndef SRC_ALGORITHMS_ALGORITHMSGETTER_HPP
#define SRC_ALGORITHMS_ALGORITHMSGETTER_HPP

#include <map>
#include <memory>
#include <vector>

namespace src::algo
{

class IAlgorithm;

std::vector<std::shared_ptr<IAlgorithm>> getAllAlgorithms();

std::map<std::string, unsigned> getAlgorithmsNameAndIdMap(
    const std::vector<std::shared_ptr<IAlgorithm>>& algorithms);

} // namespace src::algo

#endif // SRC_ALGORITHMS_ALGORITHMSGETTER_HPP
