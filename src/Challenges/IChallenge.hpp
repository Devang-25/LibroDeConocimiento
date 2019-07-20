#ifndef SRC_CHALLENGES_ICHALLENGE_HPP
#define SRC_CHALLENGES_ICHALLENGE_HPP

#include <string>

#include <Common/ResultHandler.hpp>

namespace src::challenges
{

class IChallenge
{
public:
    virtual ~IChallenge(){}
    virtual std::string name() const = 0;
    virtual common::Result run(std::istream& inputStream = std::cin) = 0;
    virtual void displayProblem() const = 0;
};

} // namespace src::challenges

#endif // SRC_CHALLENGES_ICHALLENGE_HPP
