#ifndef SRC_CODERBYTE_CHALLENGES_EASYDIFFICULTY_SIMPLESYMBOLS_HPP
#define SRC_CODERBYTE_CHALLENGES_EASYDIFFICULTY_SIMPLESYMBOLS_HPP

#include <CoderByte/Challenges/IChallenge.hpp>

namespace src::coderbyte::challenges::easy
{

class SimpleSymbols : public IChallenge
{
public:
    SimpleSymbols();

    virtual std::string name() const override;

    virtual common::Result run() override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;

    common::Result result_;
};

} // namespace src::coderbyte::challenges::easy

#endif // SRC_CODERBYTE_CHALLENGES_EASYDIFFICULTY_SIMPLESYMBOLS_HPP
