#ifndef SRC_COMMON_THREADSPAWNER_HPP
#define SRC_COMMON_THREADSPAWNER_HPP

#include <thread>

#include <Common/Logger.hpp>
#include <Common/SafeExecution.hpp>

namespace src::common
{
namespace
{

common::Logger threadSpawnerLogger("ThreadSpawner");

} // namespace

template <typename Func>
class ThreadSpawner
{
public:
    ThreadSpawner(Func func) :
        targetThread_(SafeExecution(func))
    {
    }

    ~ThreadSpawner()
    {
        join();
    }

    void join()
    {
        if (targetThread_.joinable())
        {
            targetThread_.join();
        }
    }

private:
    std::thread targetThread_;
};

} // namespace src::common

#endif // SRC_COMMON_THREADSPAWNER_HPP
