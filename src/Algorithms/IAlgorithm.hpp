#ifndef SRC_ALGORITHMS_IALGORITHM_HPP
#define SRC_ALGORITHMS_IALGORITHM_HPP

#include <string>

#include <Common/ResultHandler.hpp>

namespace src::algo
{

class IAlgorithm
{
public:
    virtual ~IAlgorithm(){}
    virtual std::string name() const = 0;
    virtual common::Result run(std::istream& inputStream = std::cin) = 0;
    virtual void displayGuide() const = 0;
};

} // namespace src::algo

#endif // SRC_ALGORITHMS_IALGORITHM_HPP
