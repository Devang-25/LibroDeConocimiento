#ifndef SRC_DISPATCHER_HPP
#define SRC_DISPATCHER_HPP

#include <memory>

namespace src
{

class IController;

class Dispatcher
{
public:
    Dispatcher();

    void dispatch(const char* message);

private:
    std::unique_ptr<IController> createController(const char* message);
};

} // namespace src

#endif // SRC_DISPATCHER_HPP
