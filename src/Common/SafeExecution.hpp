#ifndef SRC_COMMON_SAFEEXECUTION_HPP
#define SRC_COMMON_SAFEEXECUTION_HPP

#include <functional>

#include <Common/Logger.hpp>

namespace src::common
{
namespace
{

common::Logger safeExecutionLogger("SafeExecution");

} // namespace

template <typename Func = std::function<void()>>
class SafeExecution
{
public:
    SafeExecution() :
        func_([](){return;})
    {
    }

    SafeExecution(Func func) :
        func_(func)
    {
    }

    virtual ~SafeExecution()
    {
    }

    void operator()()
    {
        execute(func_);
    }

    void execute()
    {
        execute(func_);
    }

    template <typename NewFunc>
    void execute(NewFunc func)
    {
        try
        {
            func();
        }
        catch (const std::invalid_argument e)
        {
            safeExecutionLogger.print("Caught invalid_argument exception with feedback: ", e.what());
        }
        catch (const char* e)
        {
            safeExecutionLogger.print("Caught char* exception with feedback: ", e);
        }
        catch (const std::string e)
        {
            safeExecutionLogger.print("Caught string exception with feedback: ", e);
        }
        catch (...)
        {
            safeExecutionLogger.print("Caught generic exception");
        }
    }

private:
    Func func_;
};

} // namespace src::common

#endif // SRC_COMMON_SAFEEXECUTION_HPP
