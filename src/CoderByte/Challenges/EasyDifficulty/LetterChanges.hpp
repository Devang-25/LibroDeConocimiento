#ifndef SRC_CODERBYTE_CHALLENGES_EASYDIFFICULTY_LETTERCHANGES_HPP
#define SRC_CODERBYTE_CHALLENGES_EASYDIFFICULTY_LETTERCHANGES_HPP

#include <CoderByte/Challenges/IChallenge.hpp>

namespace src::coderbyte::challenges::easy
{

class LetterChanges : public IChallenge
{
public:
    LetterChanges();

    virtual std::string name() const override;

    virtual common::Result run() override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;

    common::Result result_;
};

} // namespace src::coderbyte::challenges::easy

#endif // SRC_CODERBYTE_CHALLENGES_EASYDIFFICULTY_LETTERCHANGES_HPP
