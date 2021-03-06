#include <Dispatcher.hpp>
#include <Common/Logger.hpp>

namespace
{

src::common::Logger logger("main");

} // namespace

int main(int argc, char** argv)
{
    for (int ctr = 0 ; ctr < argc; ctr++)
    {
        if (ctr == 0 && argc > 1) continue;

        logger.print("Input to main is ", *(argv+ctr), " or ", argv[ctr]);

        src::Dispatcher().dispatch(argv[ctr]);
    }

    logger.print("End of execution\n");
    return 0;
}
