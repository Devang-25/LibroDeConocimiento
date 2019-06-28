#ifndef SRC_COMMON_LOGGER_HPP
#define SRC_COMMON_LOGGER_HPP

#include <iostream>
#include <sstream>

namespace src::common
{
namespace detail
{

template <typename... Args>
typename std::enable_if<sizeof...(Args) == 0>::type concatenateMessages(std::ostream& os)
{
}

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

    template <typename T, typename... Args>
    void print(T&& message, Args&&... args)
    {
        std::stringstream ss;
        ss << "\n[" << fileName_ << "] ";
        detail::concatenateMessages(ss, message, std::forward<Args>(args)...);
        std::cout << ss.str();
    }

    void print()
    {
        print("");
    }

private:
    const char* fileName_;
};

} // namespace src::common

#endif // SRC_COMMON_LOGGER_HPP
