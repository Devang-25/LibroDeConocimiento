#include <string>

#include <BfsAlgorithm.hpp>
#include <InputOutputHandler.hpp>
#include <RecursiveAlgorithm.hpp>

/*
Niel Godfrey Ponciano
niel.ponciano@nokia.com

USAGE
1. To compile
    <g++ *.cpp -I. -std=c++14>
    or
    <g++ *.cpp -I. -std=c++14 -g -Wall -Wextra -Werror -pedantic>
2. To run (this will run BfsAlgorithm approach)
    <./a.out>
    Then input the string to find
3. To test (this will run both BfsAlgorithm and RecursiveAlgorithm approach for verification)
    <python3 RandomStringGenerator.py | xargs ./a.out --test>
    or
    <./a.out --test HEXAGON HEAR QHN QHNQ AJ HARP Y RAPE>

SAMPLE RUN
    root@nponcian:/var/fpwork/nponcian/zzz2/HexagonalString# ./a.out

    Input:HEXAGON

    [BfsAlgorithm] The hexagonal grid contains 3 instance(s) of the word "HEXAGON"
    root@nponcian:/var/fpwork/nponcian/zzz2/HexagonalString# ./a.out

    Input:HARP

    [BfsAlgorithm] The hexagonal grid contains 3 instance(s) of the word "HARP"
    root@nponcian:/var/fpwork/nponcian/zzz2/HexagonalString# ./a.out

    Input:P

    [BfsAlgorithm] The hexagonal grid contains 3 instance(s) of the word "P"
    root@nponcian:/var/fpwork/nponcian/zzz2/HexagonalString# ./a.out

    Input:GA

    [BfsAlgorithm] The hexagonal grid contains 2 instance(s) of the word "GA"
    root@nponcian:/var/fpwork/nponcian/zzz2/HexagonalString# ./a.out

    Input:

    [BfsAlgorithm] The hexagonal grid contains 0 instance(s) of the word ""
    root@nponcian:/var/fpwork/nponcian/zzz2/HexagonalString# ./a.out

    Input:ABCD

    [BfsAlgorithm] The hexagonal grid contains 0 instance(s) of the word "ABCD"

SAMPLE TEST
    root@nponcian:/var/fpwork/nponcian/zzz2/HexagonalString# clear && python3 RandomStringGenerator.py | xargs ./a.out --test

    [RecursiveAlgorithm] The hexagonal grid contains 0 instance(s) of the word "RXPA"
    [BfsAlgorithm] The hexagonal grid contains 0 instance(s) of the word "RXPA"

    [RecursiveAlgorithm] The hexagonal grid contains 0 instance(s) of the word "RXAP"
    [BfsAlgorithm] The hexagonal grid contains 0 instance(s) of the word "RXAP"

    [RecursiveAlgorithm] The hexagonal grid contains 1 instance(s) of the word "RPXA"
    [BfsAlgorithm] The hexagonal grid contains 1 instance(s) of the word "RPXA"

    [RecursiveAlgorithm] The hexagonal grid contains 2 instance(s) of the word "RPAX"
    [BfsAlgorithm] The hexagonal grid contains 2 instance(s) of the word "RPAX"

    [RecursiveAlgorithm] The hexagonal grid contains 1 instance(s) of the word "RAXP"
    [BfsAlgorithm] The hexagonal grid contains 1 instance(s) of the word "RAXP"

    [RecursiveAlgorithm] The hexagonal grid contains 0 instance(s) of the word "RAPX"
    [BfsAlgorithm] The hexagonal grid contains 0 instance(s) of the word "RAPX"

    [RecursiveAlgorithm] The hexagonal grid contains 4 instance(s) of the word "XRPA"
    [BfsAlgorithm] The hexagonal grid contains 4 instance(s) of the word "XRPA"

    [RecursiveAlgorithm] The hexagonal grid contains 1 instance(s) of the word "XRAP"
    [BfsAlgorithm] The hexagonal grid contains 1 instance(s) of the word "XRAP"

    [RecursiveAlgorithm] The hexagonal grid contains 1 instance(s) of the word "XPRA"
    [BfsAlgorithm] The hexagonal grid contains 1 instance(s) of the word "XPRA"

    [RecursiveAlgorithm] The hexagonal grid contains 0 instance(s) of the word "XPAR"
    [BfsAlgorithm] The hexagonal grid contains 0 instance(s) of the word "XPAR"

    root@nponcian:/var/fpwork/nponcian/zzz2/HexagonalString# ./a.out --test HEXAGON HEAR QHN QHNQ AJ HARP Y RAPE

    [BfsAlgorithm] The hexagonal grid contains 3 instance(s) of the word "HEXAGON"
    [RecursiveAlgorithm] The hexagonal grid contains 3 instance(s) of the word "HEXAGON"

    [BfsAlgorithm] The hexagonal grid contains 3 instance(s) of the word "HEAR"
    [RecursiveAlgorithm] The hexagonal grid contains 3 instance(s) of the word "HEAR"

    [BfsAlgorithm] The hexagonal grid contains 1 instance(s) of the word "QHN"
    [RecursiveAlgorithm] The hexagonal grid contains 1 instance(s) of the word "QHN"

    [BfsAlgorithm] The hexagonal grid contains 0 instance(s) of the word "QHNQ"
    [RecursiveAlgorithm] The hexagonal grid contains 0 instance(s) of the word "QHNQ"

    [BfsAlgorithm] The hexagonal grid contains 1 instance(s) of the word "AJ"
    [RecursiveAlgorithm] The hexagonal grid contains 1 instance(s) of the word "AJ"

    [BfsAlgorithm] The hexagonal grid contains 3 instance(s) of the word "HARP"
    [RecursiveAlgorithm] The hexagonal grid contains 3 instance(s) of the word "HARP"

    [BfsAlgorithm] The hexagonal grid contains 3 instance(s) of the word "Y"
    [RecursiveAlgorithm] The hexagonal grid contains 3 instance(s) of the word "Y"

    [BfsAlgorithm] The hexagonal grid contains 1 instance(s) of the word "RAPE"
    [RecursiveAlgorithm] The hexagonal grid contains 1 instance(s) of the word "RAPE"
*/

void src_main(int, char**);
void test_main(int, char**);

int main(int argc, char** argv)
{
    if (argc > 1 && std::string(argv[1]) == "--test") test_main(argc, argv);
    else                                              src_main(argc, argv);

    inout::print();
    return 0;
}

void src_main(int, char**)
{
    std::string input = inout::getUserInputString();
    inout::printStringInstancesCount(input,
                                    algo::BfsAlgorithm::NAME,
                                    algo::BfsAlgorithm(input)());
}

void test_main(int argc, char** argv)
{
    for (int ctr = 2; ctr < argc; ++ctr)
    {
        auto bfsResult = algo::BfsAlgorithm(argv[ctr])();
        auto recursiveResult = algo::RecursiveAlgorithm(argv[ctr])();

        inout::printStringInstancesCount(argv[ctr], algo::BfsAlgorithm::NAME, bfsResult);
        inout::printStringInstancesCount(argv[ctr], algo::RecursiveAlgorithm::NAME, recursiveResult);
        inout::print();

        if (bfsResult != recursiveResult)
        {
            inout::print("Invalid result!\nInvalid result!\nInvalid result!\nInvalid result!");
            break;
        }
    }
}
