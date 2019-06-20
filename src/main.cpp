#include <iostream>

#include "Dispatcher.hpp"

int main(int argc, char** argv)
{
    std::cout << "\nArguments supplied:";
    for (int ctr = 1 ; ctr < argc; ctr++)
    {
        std::cout << "\n\t" << *(argv+ctr) << " or " << argv[ctr];

        root::Dispatcher::dispatch(argv[ctr]);
    }

    std::cout << std::endl;
    return 0;
}
