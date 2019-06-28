#ifndef SRC_CODERBYTE_CHALLENGES_EASYDIFFICULTY_LETTERCAPITALIZE_HPP
#define SRC_CODERBYTE_CHALLENGES_EASYDIFFICULTY_LETTERCAPITALIZE_HPP

#include <CoderByte/Challenges/IChallenge.hpp>

namespace src::coderbyte::challenges::easy
{

class LetterCapitalize : public IChallenge
{
public:
    LetterCapitalize();

    virtual std::string name() const override;

    virtual void run() override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;
};

} // namespace src::coderbyte::challenges::easy

#endif // SRC_CODERBYTE_CHALLENGES_EASYDIFFICULTY_LETTERCAPITALIZE_HPP
