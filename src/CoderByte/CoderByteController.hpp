#ifndef SRC_CODERBYTE_CODERBYTECONTROLLER_HPP
#define SRC_CODERBYTE_CODERBYTECONTROLLER_HPP

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <IController.hpp>

namespace src::coderbyte
{
namespace challenges
{

class IChallenge;

} // namespace challenges

enum class UserInputCategory
{
    Exit,
    ListAll,
    ChallengeId,
    ChallengeName,
};

class CoderByteController : public IController
{
public:
    CoderByteController();

    virtual void execute() override;

private:
    void displayUserInputOptions() const;

    void processUserInput(
        const std::string& input,
        const std::vector<std::shared_ptr<challenges::IChallenge>>& challenges,
        const std::map<std::string, unsigned>& challengesNameAndIdMap,
        bool& keepRunning) const;

    UserInputCategory parseUserInputCategory(const std::string& userInput) const;
};

} // namespace src::coderbyte

#endif // SRC_CODERBYTE_CODERBYTECONTROLLER_HPP
