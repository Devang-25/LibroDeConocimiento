#include <Challenges/CoderByte/MediumDifficulty/EightQueens.hpp>

#include <string>
#include <vector>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::coderbyte::medium
{
namespace
{

common::Logger logger("EightQueens");

struct Queen
{
    int row;
    int col;

    bool willAttack(const Queen& other)
    {
        auto isSameRow = [this](const Queen& other)
            {
                return this->row == other.row;
            };
        auto isSameColumn = [this](const Queen& other)
            {
                return this->col == other.col;
            };
        auto isSameDiagonal = [this](const Queen& other)
            {
                int rowDifference = this->row > other.row ?
                                        this->row - other.row :
                                        other.row - this->row;
                int colDifference = this->col > other.col ?
                                        this->col - other.col :
                                        other.col - this->col;
                return rowDifference == colDifference;
            };
        return isSameRow(other) || isSameColumn(other) || isSameDiagonal(other);
    }
};

std::string getNumbers(const std::string& stringInput)
{
    std::string numbers = "";
    for (unsigned ctr = 0; ctr < stringInput.size(); ctr++)
    {
        if (stringInput.at(ctr) >= '0' &&
            stringInput.at(ctr) <= '9')
        {
            numbers = numbers + stringInput.at(ctr);
        }
    }
    return numbers;
}

std::vector<Queen> getQueens(const std::string& stringInput)
{
    std::string numbers = getNumbers(stringInput);

    if (numbers.size() != 16) return {};

    std::vector<Queen> queens;
    for (unsigned ctr = 0; ctr < numbers.size(); ctr=ctr+2)
    {
        queens.push_back(
            {
                numbers.at(ctr) - '0',
                numbers.at(ctr + 1) - '0',
            });
    }
    return queens;
}

std::string eightQueens(const std::string& stringInput)
{
    auto queens = getQueens(stringInput);
    for (unsigned currentQueen = 0; currentQueen < queens.size(); currentQueen++)
    {
        for (unsigned otherQueen = 0; otherQueen < queens.size(); otherQueen++)
        {
            if (otherQueen == currentQueen) continue;

            if (queens.at(currentQueen).willAttack(queens.at(otherQueen)))
            {
                const auto& foundQueen = queens.at(currentQueen);
                std::string value = "(" + std::to_string(foundQueen.row) + "," +
                                    std::to_string(foundQueen.col) + ")";
                return value;
            }
        }
    }
    return "true";
}

// std::string eightQueens(std::string strArr[])
// {
//     // code goes here
//     std::string combinedInput = "";
//     for (unsigned ctr = 0; ctr < 8; ctr++)
//     {
//         combinedInput = combinedInput + strArr[ctr];
//     }
//     return eightQueens(combinedInput);
// }

} // namespace

const std::string EightQueens::CHALLENGE_NAME_ = "EightQueens";

EightQueens::EightQueens()
{
}

std::string EightQueens::name() const
{
    return CHALLENGE_NAME_;
}

common::Result EightQueens::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputString(inputStream);
    auto result = eightQueens(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void EightQueens::displayProblem() const
{
    logger.print("Have the function EightQueens(strArr) read strArr which will be an array consisting of the locations of eight Queens on a standard 8x8 chess board with no other pieces on the board.");
    logger.print("The structure of strArr will be the following: [\"(x,y)\", \"(x,y)\", ...] where (x,y) represents the position of the current queen on the chessboard (x and y will both range from 1 to 8 where 1,1 is the bottom-left of the chessboard and 8,8 is the top-right).");
    logger.print("Your program should determine if all of the queens are placed in such a way where none of them are attacking each other.");
    logger.print("If this is true for the given input, return the string true otherwise return the first queen in the list that is attacking another piece in the same format it was provided.");
    logger.print("For example: if strArr is [\"(2,1)\", \"(4,2)\", \"(6,3)\", \"(8,4)\", \"(3,5)\", \"(1,6)\", \"(7,7)\", \"(5,8)\"] then your program should return the string true.");
    logger.print("Sample Test Cases");
    logger.print("Input:{\"(2,1)\", \"(4,3)\", \"(6,3)\", \"(8,4)\", \"(3,4)\", \"(1,6)\", \"(7,7)\", \"(5,8)\"}");
    logger.print("Output:\"(2,1)\"");
    logger.print("Input:{\"(2,1)\", \"(5,3)\", \"(6,3)\", \"(8,4)\", \"(3,4)\", \"(1,8)\", \"(7,7)\", \"(5,8)\"}");
    logger.print("Output:\"(5,3)\"");
}

} // namespace src::challenges::coderbyte::medium
