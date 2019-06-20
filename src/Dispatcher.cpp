#include "Dispatcher.hpp"

#include <iostream>
#include <string>

namespace root
{

void Dispatcher::dispatch(const char* message)
{
    std::string messageStr = message;

    // using if-else because switch statement can only be used for integral values, not for values
    // of user-defined type (even with overloaded == > < operators)
    if (messageStr == "--help")
    {
        std::cout << "\nEntered " << message;
    }
    else if (messageStr == "--coderbyte")
    {
        std::cout << "\nEntered " << message;
    }
    else
    {
        std::cout << "\nUnsupported message. Cannot recognize " << message;
    }
}

} // namespace root
