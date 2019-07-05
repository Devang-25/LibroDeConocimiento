#ifndef SRC_CHALLENGES_PROJECTEULER_MULTIPLESOF3AND5_HPP
#define SRC_CHALLENGES_PROJECTEULER_MULTIPLESOF3AND5_HPP

#include <Challenges/IChallenge.hpp>

namespace src::challenges::euler
{

class MultiplesOf3And5 : public IChallenge
{
public:
    MultiplesOf3And5();

    virtual std::string name() const override;

    virtual common::Result run(std::istream& inputStream = std::cin) override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;

    common::Result result_;
};

} // namespace src::challenges::euler

#endif // SRC_CHALLENGES_PROJECTEULER_MULTIPLESOF3AND5_HPP
