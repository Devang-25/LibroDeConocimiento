#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "\nArguments supplied:";
    for (int ctr = 0 ; ctr < argc; ctr++)
    {
        std::cout << "\n\t" << *(argv+ctr)
                    << " or " << argv[ctr];
    }

    std::cout << std::endl;
    return 0;
}
