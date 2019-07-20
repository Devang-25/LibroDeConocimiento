#include <Dispatcher.hpp>

#include <string>

#include <Algorithms/AlgorithmsController.hpp>
#include <Challenges/ChallengesController.hpp>
#include <Help/HelpController.hpp>
#include <IController.hpp>
#include <Common/Logger.hpp>

namespace src
{
namespace
{

common::Logger logger("Dispatcher");

} // namespace

Dispatcher::Dispatcher()
{
}

void Dispatcher::dispatch(const char* message)
{
    auto controller = createController(message);

    if (controller)
    {
        controller->execute();
    }
    else
    {
        logger.print("Unsupported message ", message);
        logger.print("Try with --help to display usage, sample command: ./libro_src --help");
    }
}

std::unique_ptr<IController> Dispatcher::createController(const char* message)
{
    std::string messageStr = message;

    if (messageStr == "--help")            return std::make_unique<help::HelpController>();
    else if (messageStr == "--algorithms") return std::make_unique<algo::AlgorithmsController>();
    else if (messageStr == "--challenges") return std::make_unique<challenges::ChallengesController>();

    return nullptr;
}

} // namespace src
