#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "FileHandler.hpp"
#include "MagicSquareFinder.hpp"
#include "MatrixOutputter.hpp"
#include "MatrixData.hpp"

namespace
{

const std::string DEFAULT_INPUT_FILE_NAME = "./MatrixFiles/matrix.txt";
const std::string OUTPUT_FILE_POSTFIX = "_output";
const std::string DEFAULT_OUTPUT_FILE_NAME = "output.txt";
const std::string PRINT_TO_SCREEN_FLAG = "--printtoscreen";

} // namespace

int main(int argc, char** argv)
{
    std::cout << "\nExecution started";

    std::string inputFilename = DEFAULT_INPUT_FILE_NAME;
    std::string outputFilename = DEFAULT_OUTPUT_FILE_NAME; // inputFilename + OUTPUT_FILE_POSTFIX;
    bool printToScreen = false;
    for (int ctr = 1; ctr < argc; ++ctr)
    {
        if (std::string(argv[ctr]) == PRINT_TO_SCREEN_FLAG) printToScreen = true;
        else                                                inputFilename = argv[ctr];
    }
    
    auto matrix = src::file::getMatrixFromFile(inputFilename);
    auto subMatrices = src::magicsquare::getAllMagicSquaresSubMatrices(matrix);

    if (printToScreen) src::output::streamMatrixAndSubMatrices(matrix, subMatrices);

    std::stringstream resultStream;
    src::output::streamMatrixAndSubMatrices(matrix, subMatrices, resultStream);
    src::file::writeContentsToFile(outputFilename, resultStream.str());

    std::cout << "\nExecution finished\n";
    return 0;
}

/*
The CHALLENGE:
Given a matrix of size NxM containing positive and negative
numbers, write a program that finds all square sub-matrices
where the sum of each column, row, and diagonal are the same.
Input matrix is stored in a text file matrix.txt.
Output should display all sub-matrices from smallest to largest
(excluding 1x1 matrices), separated by CR/LF and should be
saved in a text file named output.txt.
Sample Input:
-1 0 3 3
2 4 3 3
4 3 2 5
3 2 4 -6
Output:
3 3
3 3
2 4 3
4 3 2
3 2 4
*/