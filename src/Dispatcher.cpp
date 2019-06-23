#include "Dispatcher.hpp"

#include <string>

#include "Help/HelpController.hpp"
#include "IController.hpp"
#include "Utilities/Logger.hpp"

namespace root
{
namespace
{

utilities::Logger logger("Dispatcher");

} // namespace

Dispatcher::Dispatcher()
{
}

void Dispatcher::dispatch(const char* message)
{
    auto controller = createControllerForMessage(message);

    if (controller)
    {
        controller->execute();
    }
    else
    {
        logger.print("Unsupported message ", message);
        logger.print("Try with --help to display usage, sample command: ./bin/a.out --help");
    }
}

std::unique_ptr<IController> Dispatcher::createControllerForMessage(const char* message)
{
    std::string messageStr = message;

    if (messageStr == "--help")           return std::make_unique<help::HelpController>();
    else if (messageStr == "--coderbyte") return nullptr;

    return nullptr;
}

} // namespace root
