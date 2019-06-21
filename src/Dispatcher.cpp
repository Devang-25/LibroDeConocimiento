#include "Dispatcher.hpp"

#include <iostream>
#include <memory>
#include <string>

#include "Help/HelpController.hpp"
#include "IController.hpp"

namespace root
{

void Dispatcher::dispatch(const char* message)
{
    std::string messageStr = message;
    std::unique_ptr<IController> controller;

    // using if-else because switch statement can only be used for integral values, not for values
    // of user-defined type (even with overloaded == > < operators)
    if (messageStr == "--help")
    {
        std::cout << "\nProcessing ongoing for " << message;
        controller = std::make_unique<help::HelpController>();
    }
    else if (messageStr == "--coderbyte")
    {
        std::cout << "\nProcessing ongoing for " << message;
    }
    else
    {
        std::cout << "\nUnsupported message. Cannot recognize " << message;
        std::cout << "\nTry with --help to display usage, sample command: ./bin/a.out --help";
    }

    if (controller)
    {
        controller->execute();
    }
}

} // namespace root
