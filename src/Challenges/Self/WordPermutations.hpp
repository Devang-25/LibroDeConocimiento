#ifndef SRC_CHALLENGES_SELF_WORDPERMUTATIONS_HPP
#define SRC_CHALLENGES_SELF_WORDPERMUTATIONS_HPP

#include <Challenges/IChallenge.hpp>

namespace src::challenges::self
{

class WordPermutations : public IChallenge
{
public:
    WordPermutations();

    virtual std::string name() const override;

    virtual common::Result run(std::istream& inputStream = std::cin) override;

    virtual void displayProblem() const override;

private:
    static const std::string CHALLENGE_NAME_;

    common::Result result_;
};

} // namespace src::challenges::self

#endif // SRC_CHALLENGES_SELF_WORDPERMUTATIONS_HPP
