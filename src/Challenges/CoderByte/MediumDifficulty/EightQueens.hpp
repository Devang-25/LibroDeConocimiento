#ifndef SRC_CHALLENGES_CODERBYTE_MEDIUMDIFFICULTY_EIGHTQUEENS_HPP
#define SRC_CHALLENGES_CODERBYTE_MEDIUMDIFFICULTY_EIGHTQUEENS_HPP

#include <Challenges/IChallenge.hpp>

namespace src::challenges::coderbyte::medium
{

class EightQueens : public IChallenge
{
public:
    EightQueens();

    virtual std::string name() const override;

    virtual common::Result run(std::istream& inputStream = std::cin) override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;

    common::Result result_;
};

} // namespace src::challenges::coderbyte::medium

#endif // SRC_CHALLENGES_CODERBYTE_MEDIUMDIFFICULTY_EIGHTQUEENS_HPP
