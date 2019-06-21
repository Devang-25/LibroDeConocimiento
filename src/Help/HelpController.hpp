#ifndef ROOT_HELP_HELPCONTROLLER_HPP
#define ROOT_HELP_HELPCONTROLLER_HPP

#include "IController.hpp"

namespace root
{
namespace help
{

class HelpController : public IController
{
public:
    HelpController();
    virtual void execute() override;
};

} // namespace help
} // namespace root

#endif // ROOT_HELP_HELPCONTROLLER_HPP
