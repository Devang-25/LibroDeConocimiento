#ifndef SRC_CHALLENGES_CODERBYTE_HARDIFFICULTY_MAXIMALSQUARE_HPP
#define SRC_CHALLENGES_CODERBYTE_HARDIFFICULTY_MAXIMALSQUARE_HPP

#include <Challenges/IChallenge.hpp>

namespace src::challenges::coderbyte::hard
{

class MaximalSquare : public IChallenge
{
public:
    MaximalSquare();

    virtual std::string name() const override;

    virtual common::Result run(std::istream& inputStream = std::cin) override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;

    common::Result result_;
};

} // namespace src::challenges::coderbyte::hard

#endif // SRC_CHALLENGES_CODERBYTE_HARDIFFICULTY_MAXIMALSQUARE_HPP
