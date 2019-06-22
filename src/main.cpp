#include <iostream>

#include "Dispatcher.hpp"

int main(int argc, char** argv)
{
    for (int ctr = 0 ; ctr < argc; ctr++)
    {
        if (ctr == 0 && argc > 1) continue;

        std::cout << "Input to main is " << *(argv+ctr) << " or " << argv[ctr];

        root::Dispatcher().dispatch(argv[ctr]);
    }

    std::cout << std::endl;
    return 0;
}
