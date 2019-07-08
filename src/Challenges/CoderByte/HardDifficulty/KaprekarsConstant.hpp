#ifndef SRC_CHALLENGES_CODERBYTE_HARDIFFICULTY_KAPREKARSCONSTANT_HPP
#define SRC_CHALLENGES_CODERBYTE_HARDIFFICULTY_KAPREKARSCONSTANT_HPP

#include <Challenges/IChallenge.hpp>

namespace src::challenges::coderbyte::hard
{

class KaprekarsConstant : public IChallenge
{
public:
    KaprekarsConstant();

    virtual std::string name() const override;

    virtual common::Result run(std::istream& inputStream = std::cin) override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;

    common::Result result_;
};

} // namespace src::challenges::coderbyte::hard

#endif // SRC_CHALLENGES_CODERBYTE_HARDIFFICULTY_KAPREKARSCONSTANT_HPP
