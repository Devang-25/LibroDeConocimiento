#include <Challenges/CoderByte/HardDifficulty/MaximalSquare.hpp>

#include <algorithm>
#include <string>
#include <vector>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::coderbyte::hard
{
namespace
{

common::Logger logger("MaximalSquare");

std::vector<std::vector<char>> transformToMultidimensionalContainer(const std::string& input)
{
    std::vector<std::vector<char>> rowCharsVec;
    for (unsigned chIndex = 0u; chIndex < input.size(); chIndex++)
    {
        if (rowCharsVec.empty() || !rowCharsVec.back().empty())
        {
            rowCharsVec.push_back({});
        }
        while (chIndex < input.size() &&
                (input.at(chIndex) == '0' || input.at(chIndex) == '1'))
        {
            rowCharsVec.back().push_back(input.at(chIndex));
            chIndex++;
        }
    }
    return rowCharsVec;
}

template <typename T>
void printMultidimensionalContainer(const T& container)
{
    for (const auto& contents : container)
    {
        logger.printNoFormatting("\n");
        for (const auto& item : contents)
        {
            logger.printNoFormatting(item, " ");
        }
    }
}

unsigned maximalSquare(const std::string& input)
{
    // code goes here
    auto rowCharsVec = transformToMultidimensionalContainer(input);
    printMultidimensionalContainer(rowCharsVec);

    unsigned largestResult = 0u;
    for (unsigned row = 0u; row < rowCharsVec.size() - largestResult; row++)
    {
        for (unsigned col = 0u; col < rowCharsVec[row].size() - largestResult; col++)
        {
            if (rowCharsVec[row][col] == '0') continue;

            // This solution would count the maximum square length that each coordinate. Each coordinate
            // will be trated as the origin node and thus would only be spanned to the right and down
            unsigned horizontalCount = 0u;
            unsigned verticalCount = 0u;
            for (unsigned rowCtr = row; rowCtr < rowCharsVec.size(); rowCtr++)
            {
                unsigned currentHorizontalCount = 0u;
                unsigned colCtr = col;
                while (colCtr < rowCharsVec[rowCtr].size() &&
                        rowCharsVec[rowCtr][colCtr] == '1')
                {
                    currentHorizontalCount++;
                    colCtr++;
                }

                if (horizontalCount == 0)
                {
                    horizontalCount = currentHorizontalCount;
                }
                else if (horizontalCount > currentHorizontalCount)
                {
                    if (currentHorizontalCount > verticalCount) verticalCount++;
                    break;
                }

                verticalCount++;
            }
            unsigned currentCoordinateResult = std::min(horizontalCount, verticalCount);
            largestResult = std::max(largestResult, currentCoordinateResult);
        }
    }

    logger.print("Largest square length: ", largestResult);
    return largestResult*largestResult;
}

// unsigned maximalSquare(std::string strArr[])
// {
//     // code goes here
//     unsigned strCount = 0u;
//     while (!strArr[strCount].empty()) strCount++;

//     std::string input = "";
//     for (unsigned ctr = 0u; ctr < strCount; ctr++)
//     {
//         input = input + strArr[ctr] + " ";
//     }
//     return maximalSquare(input);
// }

} // namespace

const std::string MaximalSquare::CHALLENGE_NAME_ = "MaximalSquare";

MaximalSquare::MaximalSquare()
{
}

std::string MaximalSquare::name() const
{
    return CHALLENGE_NAME_;
}

common::Result MaximalSquare::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputString(inputStream);
    auto result = maximalSquare(input);
    logger.print("Result: ", result);

    result_.set(result);
    return result_;
}

void MaximalSquare::displayProblem() const
{
    logger.print("Have the function MaximalSquare(strArr) take the strArr parameter being passed which will be a 2D matrix of 0 and 1's, and determine the area of the largest square submatrix that contains all 1's.");
    logger.print("A square submatrix is one of equal width and height, and your program should return the area of the largest submatrix that contains only 1's.");
    logger.print("For example: if strArr is [\"10100\", \"10111\", \"11111\", \"10010\"] then this looks like the following matrix: ");
    logger.print("1 0 1 0 0");
    logger.print("1 0 1 1 1");
    logger.print("1 1 1 1 1");
    logger.print("1 0 0 1 0 ");
    logger.print("For the input above, you can see the bolded 1's create the largest square submatrix of size 2x2, so your program should return the area which is 4. You can assume the input will not be empty.");
    logger.print("1. For the input [10100, 10111, 11111, 10010] your output was incorrect. The correct answer is 4.");
    logger.print("2. For the input [0111, 1101, 0111] your output was incorrect. The correct answer is 1.");
    logger.print("3. For the input [1111, 1111] your output was incorrect. The correct answer is 4.");
    logger.print("4. For the input [1111, 1111, 1111] your output was incorrect. The correct answer is 9.");
    logger.print("5. For the input [1111, 1101, 1111, 0111] your output was incorrect. The correct answer is 4.");
    logger.print("6. For the input [01001, 11111, 01011, 11011] your output was incorrect. The correct answer is 4.");
    logger.print("7. For the input [01001, 11111, 01011, 11111, 01111, 11111] your output was incorrect. The correct answer is 9.");
    logger.print("8. For the input [101101, 111111, 010111, 111111] your output was incorrect. The correct answer is 9.");
    logger.print("9. For the input [101101, 111111, 011111, 111111, 001111, 011111] your output was incorrect. The correct answer is 16.");
}

} // namespace src::challenges::coderbyte::hard
