#ifndef SRC_CHALLENGES_HACKERRANK_NONDIVISIBLESUBSET_HPP
#define SRC_CHALLENGES_HACKERRANK_NONDIVISIBLESUBSET_HPP

#include <Challenges/IChallenge.hpp>

namespace src::challenges::hacker
{

class NonDivisibleSubset : public IChallenge
{
public:
    NonDivisibleSubset();

    virtual std::string name() const override;

    virtual common::Result run(std::istream& inputStream = std::cin) override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;

    common::Result result_;
};

} // namespace src::challenges::hacker

#endif // SRC_CHALLENGES_HACKERRANK_NONDIVISIBLESUBSET_HPP
