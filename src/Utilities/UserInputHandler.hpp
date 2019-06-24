#ifndef SRC_UTILITIES_USERINPUTHANDLER_HPP
#define SRC_UTILITIES_USERINPUTHANDLER_HPP

#include <type_traits>

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
    if (!std::is_integral<IntegralOrFloatingType>::value && !std::is_floating_point<IntegralOrFloatingType>::value)
    {
        logger.print("Error, usage of method ", __FUNCTION__, " for non-integral/floating type!");
        return IntegralOrFloatingType{};
    }

    logger.print("Input:");
    IntegralOrFloatingType input;
    std::cin >> input;
    std::cin.ignore();
    return input;
}

} // namespace src::utilities

#endif // SRC_UTILITIES_USERINPUTHANDLER_HPP
