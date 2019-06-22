#ifndef ROOT_DISPATCHER_HPP
#define ROOT_DISPATCHER_HPP

#include <memory>

namespace root
{

class IController;

class Dispatcher
{
public:
    Dispatcher();

    void dispatch(const char* message);
    std::unique_ptr<IController> createControllerForMessage(const char* message);
};

} // namespace root

#endif // ROOT_DISPATCHER_HPP
