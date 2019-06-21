#include "Help/HelpController.hpp"

#include <iostream>

namespace root
{
namespace help
{

HelpController::HelpController()
{
}

void HelpController::execute()
{
    std::cout
        << "\nThis project is being developed to study and try different concepts in C++ software development."
        << "\nThis project not only contains C++ source files but also the tools normally used alongside with it such as the Makefile, among others."
        << "\n"
        << "\nTopics maintained here can be accessed by postfixing the following commands upon running ./bin/a.out"
        << "\nex. ./bin/a.out --help"
        << "\n\t--help"
        << "\n\t\tDisplay the information about this project."
        << "\n\t\tGuides you with the available commands to move through what the project can offer.";
}

} // namespace help
} // namespace root
