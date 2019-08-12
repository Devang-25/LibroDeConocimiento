#ifndef SRC_COMMON_SAFEEXECUTION_HPP
#define SRC_COMMON_SAFEEXECUTION_HPP

#include <Common/Logger.hpp>

namespace src::common
{
namespace
{

common::Logger safeExecutionLogger("SafeExecution");

} // namespace

class SafeExecution
{
public:
    SafeExecution()
    {
    }

    virtual ~SafeExecution()
    {
    }

    template <typename Func>
    void execute(Func func)
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
};

} // namespace src::common

#endif // SRC_COMMON_SAFEEXECUTION_HPP
