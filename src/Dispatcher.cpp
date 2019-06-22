#include "Dispatcher.hpp"

#include <iostream>
#include <string>

#include "Help/HelpController.hpp"
#include "IController.hpp"

namespace root
{

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
        std::cout << "\nUnsupported message. Cannot recognize " << message;
        std::cout << "\nTry with --help to display usage, sample command: ./bin/a.out --help";
    }
}

std::unique_ptr<IController> Dispatcher::createControllerForMessage(const char* message)
{
    std::string messageStr = message;

    // using if-else because switch statement can only be used for integral values, not for values
    // of user-defined type (even with overloaded == > < operators)
    if (messageStr == "--help")           return std::make_unique<help::HelpController>();
    else if (messageStr == "--coderbyte") return nullptr;

    return nullptr;

}

} // namespace root
