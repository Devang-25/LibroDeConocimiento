#ifndef SRC_CHALLENGES_CODERBYTE_EASYDIFFICULTY_FIRSTREVERSE_HPP
#define SRC_CHALLENGES_CODERBYTE_EASYDIFFICULTY_FIRSTREVERSE_HPP

#include <Challenges/IChallenge.hpp>

namespace src::challenges::coderbyte::easy
{

class FirstReverse : public IChallenge
{
public:
    FirstReverse();

    virtual std::string name() const override;

    virtual common::Result run(std::istream& inputStream = std::cin) override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;

    common::Result result_;
};

} // namespace src::challenges::coderbyte::easy

#endif // SRC_CHALLENGES_CODERBYTE_EASYDIFFICULTY_FIRSTREVERSE_HPP
