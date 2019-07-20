#ifndef SRC_ALGORITHMS_ALGORITHMSCONTROLLER_HPP
#define SRC_ALGORITHMS_ALGORITHMSCONTROLLER_HPP

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <IController.hpp>

namespace src::algo
{

class IAlgorithm;

enum class UserInputCategory
{
    Exit,
    ListAll,
    AlgorithmId,
    AlgorithmName,
};

class AlgorithmsController : public IController
{
public:
    AlgorithmsController();

    virtual void execute() override;

private:
    void displayUserInputOptions() const;

    void processUserInput(
        const std::string& input,
        const std::vector<std::shared_ptr<IAlgorithm>>& algorithms,
        const std::map<std::string, unsigned>& algorithmsNameAndIdMap,
        bool& keepRunning) const;

    UserInputCategory parseUserInputCategory(const std::string& userInput) const;
};

} // namespace src::algo

#endif // SRC_ALGORITHMS_ALGORITHMSCONTROLLER_HPP
