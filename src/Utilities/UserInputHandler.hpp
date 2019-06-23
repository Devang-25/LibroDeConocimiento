#ifndef SRC_UTILITIES_USERINPUTHANDLER_HPP
#define SRC_UTILITIES_USERINPUTHANDLER_HPP

#include "Utilities/Logger.hpp"

namespace src::utilities
{
namespace
{

Logger logger("UserInputHandler");

} // namespace

inline std::string getUserInputString()
{
    logger.print("Input:");
    std::string input;
    std::getline(std::cin, input);
    return input;
}

} // namespace src::utilities

#endif // SRC_UTILITIES_USERINPUTHANDLER_HPP
