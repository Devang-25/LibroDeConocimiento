#ifndef SRC_HELP_HELPCONTROLLER_HPP
#define SRC_HELP_HELPCONTROLLER_HPP

#include "IController.hpp"

namespace src::help
{

class HelpController : public IController
{
public:
    HelpController();

    virtual void execute() override;
};

} // namespace src::help

#endif // SRC_HELP_HELPCONTROLLER_HPP
