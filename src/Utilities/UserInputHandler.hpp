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

// To be used for user inputs such as int, unsigned, long, short, char, bool and float, double
// Need not to be explicitly written as inline, just for clarity here
template<typename IntegralOrFloatingType>
inline IntegralOrFloatingType getUserInputIntegralOrFloating()
{
    logger.print("Input:");
    IntegralOrFloatingType input;
    std::cin >> input;
    std::cin.ignore();
    return input;
}

} // namespace src::utilities

#endif // SRC_UTILITIES_USERINPUTHANDLER_HPP
