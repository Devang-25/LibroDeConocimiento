#ifndef SRC_CHALLENGES_CODERBYTE_EASYDIFFICULTY_CORRECTPATH_HPP
#define SRC_CHALLENGES_CODERBYTE_EASYDIFFICULTY_CORRECTPATH_HPP

#include <Challenges/IChallenge.hpp>

namespace src::challenges::coderbyte::easy
{

class CorrectPath : public IChallenge
{
public:
    CorrectPath();

    virtual std::string name() const override;

    virtual common::Result run(std::istream& inputStream = std::cin) override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;

    common::Result result_;
};

} // namespace src::challenges::coderbyte::easy

#endif // SRC_CHALLENGES_CODERBYTE_EASYDIFFICULTY_CORRECTPATH_HPP
