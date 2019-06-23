#ifndef ROOT_UTILITIES_LOGGER_HPP
#define ROOT_UTILITIES_LOGGER_HPP

#include <iostream>
#include <sstream>

namespace root::utilities
{
namespace detail
{

template<typename... Args>
typename std::enable_if<sizeof...(Args) == 0>::type
concatenateMessages(std::ostream& os) {}

template <typename T, typename... Args>
std::ostream& concatenateMessages(
    std::ostream& os,
    T&& message,
    Args&&... args)
{
    os << message;
    concatenateMessages(os, std::forward<Args>(args)...);
    return os;
}

} // namespace detail

class Logger
{
public:
    Logger() :
        fileName_("UnknownFile")
    {
    }

    explicit Logger(const char* fileName) :
        fileName_(fileName)
    {
    }

    void print()
    {
        std::cout << "\n[" << fileName_ << "] ";
    }

    template <typename T, typename... Args>
    void print(T&& message, Args&&... args)
    {
        std::stringstream ss;
        ss << "\n[" << fileName_ << "] ";
        detail::concatenateMessages(ss, message, std::forward<Args>(args)...);
        std::cout << ss.str();
    }

private:
    const char* fileName_;
};

} // namespace root::utilities

#endif // ROOT_UTILITIES_LOGGER_HPP
