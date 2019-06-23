#ifndef SRC_CODERBYTE_CHALLENGES_ICHALLENGE_HPP
#define SRC_CODERBYTE_CHALLENGES_ICHALLENGE_HPP

#include <string>

namespace src::coderbyte::challenges
{

class IChallenge
{
public:
    virtual ~IChallenge(){}
    virtual std::string name() const = 0;
    virtual void run() = 0;
    virtual void displayProblem() const = 0;
};

} // namespace src::coderbyte::challenges

#endif // SRC_CODERBYTE_CHALLENGES_ICHALLENGE_HPP
