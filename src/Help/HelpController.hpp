#ifndef ROOT_HELP_HELPCONTROLLER_HPP
#define ROOT_HELP_HELPCONTROLLER_HPP

#include "IController.hpp"

namespace root::help
{

class HelpController : public IController
{
public:
    HelpController();
    virtual void execute() override;
};

} // namespace root::help

#endif // ROOT_HELP_HELPCONTROLLER_HPP
