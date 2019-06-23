#include "Help/HelpController.hpp"

#include "Utilities/Logger.hpp"

namespace src::help
{
namespace
{

utilities::Logger logger("HelpController");

} // namespace

HelpController::HelpController()
{
}

void HelpController::execute()
{
    logger.print();
    logger.print("This project is being developed to study and try different concepts in C++ software development.");
    logger.print("This project not only contains C++ source files but also the tools normally used alongside with it such as the Makefile, among others.");
    logger.print();
    logger.print("Topics maintained here can be accessed by postfixing the following commands upon running ./bin/a.out");
    logger.print("sample command: ./bin/a.out --help");
    logger.print();
    logger.print("\t--help");
    logger.print("\t\tDisplay the information about this project.");
    logger.print("\t\tGuides you with the available commands to move through what the project can offer.");
    logger.print();
    logger.print("\t--coderbyte");
    logger.print("\t\tAccess the challenges in CoderByte.");
    logger.print("\t\tExecute and test the solutions written to the different challenges.");
}

} // namespace src::help
