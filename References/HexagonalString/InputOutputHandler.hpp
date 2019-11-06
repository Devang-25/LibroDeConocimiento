#ifndef INPUTOUTPUTHANDLER_HPP
#define INPUTOUTPUTHANDLER_HPP

#include <iostream>
#include <string>

namespace inout
{

inline std::string getUserInputString(std::istream& inputStream = std::cin)
{
    std::cout << "\nInput:";
    std::string input;
    std::getline(inputStream, input);
    return input;
}

inline void printStringInstancesCount(
    const std::string& targetString,
    const std::string& algorithmName,
    const unsigned totalCount)
{
    std::cout << "\n[" << algorithmName << "] The hexagonal grid contains " << totalCount
            << " instance(s) of the word \"" << targetString << "\"";
}

inline void print(const std::string& str = "")
{
    std::cout << "\n" << str;
}

} // namespace inout

#endif // INPUTOUTPUTHANDLER_HPP
