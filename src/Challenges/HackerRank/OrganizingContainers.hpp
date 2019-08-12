#ifndef SRC_CHALLENGES_HACKERRANK_ORGANIZINGCONTAINERS_HPP
#define SRC_CHALLENGES_HACKERRANK_ORGANIZINGCONTAINERS_HPP

#include <Challenges/IChallenge.hpp>

namespace src::challenges::hacker
{

class OrganizingContainers : public IChallenge
{
public:
    OrganizingContainers();

    virtual std::string name() const override;

    virtual common::Result run(std::istream& inputStream = std::cin) override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;

    common::Result result_;
};

} // namespace src::challenges::hacker

#endif // SRC_CHALLENGES_HACKERRANK_ORGANIZINGCONTAINERS_HPP
