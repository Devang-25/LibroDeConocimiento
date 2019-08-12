#include <Challenges/HackerRank/QueensAttack.hpp>

#include <bits/stdc++.h> // I got it from HackerRank, pretty cool :D

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::hacker
{
namespace
{

common::Logger logger("QueensAttack");

// Declaring my own optional as HackerRank doesn't support boost::optional and I don't want std::optional yet
template <typename T>
class MyOptional
{
public:
    MyOptional() :
        isValueInitialized_(false),
        value_()
    {
    }

    MyOptional(const T& value) :
        isValueInitialized_(true),
        value_(value)
    {
    }

    MyOptional& operator=(const MyOptional& other)
    {
        isValueInitialized_ = other.isValueInitialized_;
        value_ = other.value_;
        return *this;
    }

    MyOptional& operator=(const T& value)
    {
        isValueInitialized_ = true;
        value_ = value;
        return *this;
    }

    operator bool()
    {
        return isValueInitialized_;
    }

    T getValueOr(const T& value)
    {
        return isValueInitialized_ ?
                value_ :
                value;
    }

private:
    bool isValueInitialized_;
    T value_;
};

int queensAttack(
    int n,
    int,// k,
    int r_q,
    int c_q,
    const std::vector<std::vector<int>>& obstacles)
{
    MyOptional<int> nearestLeftConstraint;
    MyOptional<int> nearestRightConstraint;
    MyOptional<int> nearestDownConstraint;
    MyOptional<int> nearestUpConstraint;
    MyOptional<int> nearestDiagonalDownLeftAttacks;
    MyOptional<int> nearestDiagonalDownRightAttacks;
    MyOptional<int> nearestDiagonalUpLeftAttacks;
    MyOptional<int> nearestDiagonalUpRightAttacks;

    for (const auto& xy : obstacles)
    {
        const int obstacleX = xy.at(0);
        const int obstacleY = xy.at(1);
        if (obstacleX == r_q && obstacleY == c_q) continue;

        if (obstacleX == r_q)
        {
            if (obstacleY < c_q && (!nearestLeftConstraint || obstacleY > nearestLeftConstraint.getValueOr(0)))        nearestLeftConstraint = obstacleY;
            else if (obstacleY > c_q && (!nearestRightConstraint || obstacleY < nearestRightConstraint.getValueOr(0))) nearestRightConstraint = obstacleY;
        }
        else if (obstacleY == c_q)
        {
            if (obstacleX < r_q && (!nearestDownConstraint || obstacleX > nearestDownConstraint.getValueOr(0)))  nearestDownConstraint = obstacleX;
            else if (obstacleX > r_q && (!nearestUpConstraint || obstacleX < nearestUpConstraint.getValueOr(0))) nearestUpConstraint = obstacleX;
        }
        else
        {
            int xDiff = r_q - obstacleX;
            int yDiff = c_q - obstacleY;
            int xDiffAbs = std::abs(xDiff);
            int yDiffAbs = std::abs(yDiff);
            if (xDiffAbs != yDiffAbs) continue;

            if (xDiff > 0) // down diagonal
            {
                if (yDiff > 0 && (!nearestDiagonalDownLeftAttacks || yDiffAbs < nearestDiagonalDownLeftAttacks.getValueOr(0))) // left diagonal
                {
                    nearestDiagonalDownLeftAttacks = yDiffAbs;
                }
                else if (yDiff < 0 && (!nearestDiagonalDownRightAttacks || yDiffAbs < nearestDiagonalDownRightAttacks.getValueOr(0))) // right diagonal
                {
                    nearestDiagonalDownRightAttacks = yDiffAbs;
                }
            }
            else if (xDiff < 0) // up diagonal
            {
                if (yDiff > 0 && (!nearestDiagonalUpLeftAttacks || yDiffAbs < nearestDiagonalUpLeftAttacks.getValueOr(0))) // left diagonal
                {
                    nearestDiagonalUpLeftAttacks = yDiffAbs;
                }
                else if (yDiff < 0 && (!nearestDiagonalUpRightAttacks || yDiffAbs < nearestDiagonalUpRightAttacks.getValueOr(0))) // right diagonal
                {
                    nearestDiagonalUpRightAttacks = yDiffAbs;
                }
            }
        }
    }

    // std::cout << nearestLeftConstraint.getValueOr(0) << " nearestLeftConstraint\n";
    // std::cout << nearestRightConstraint.getValueOr(0) << " nearestRightConstraint\n";
    // std::cout << nearestDownConstraint.getValueOr(0) << " nearestDownConstraint\n";
    // std::cout << nearestUpConstraint.getValueOr(0) << " nearestUpConstraint\n";
    // std::cout << nearestDiagonalDownLeftAttacks.getValueOr(0) << " nearestDiagonalDownLeftAttacks\n";
    // std::cout << nearestDiagonalDownRightAttacks.getValueOr(0) << " nearestDiagonalDownRightAttacks\n";
    // std::cout << nearestDiagonalUpLeftAttacks.getValueOr(0) << " nearestDiagonalUpLeftAttacks\n";
    // std::cout << nearestDiagonalUpRightAttacks.getValueOr(0) << " nearestDiagonalUpRightAttacks\n";

    int maxLeftAttacks = c_q - 1;
    int maxRightAttacks = n - c_q;
    int maxDownAttacks = r_q - 1;
    int maxUpAttacks = n - r_q;
    int maxDiagonalDownLeftAttacks = std::min(maxDownAttacks, maxLeftAttacks);
    int maxDiagonalDownRightAttacks = std::min(maxDownAttacks, maxRightAttacks);
    int maxDiagonalUpLeftAttacks = std::min(maxUpAttacks, maxLeftAttacks);
    int maxDiagonalUpRightAttacks = std::min(maxUpAttacks, maxRightAttacks);

    // std::cout << "\n\n\n nearestLeftConstraint " << c_q - 1 - nearestLeftConstraint.getValueOr(0);
    // std::cout << "\n nearestRightConstraint " << nearestRightConstraint.getValueOr(n) - c_q - 1;
    // std::cout << "\n nearestDownConstraint " << r_q - 1 - nearestDownConstraint.getValueOr(0);
    // std::cout << "\n nearestUpConstraint " << nearestUpConstraint.getValueOr(n) - r_q;
    // std::cout << "\n nearestDiagonalDownLeftAttacks " << nearestDiagonalDownLeftAttacks.getValueOr(maxDiagonalDownLeftAttacks);
    // std::cout << "\n nearestDiagonalDownRightAttacks " << nearestDiagonalDownRightAttacks.getValueOr(maxDiagonalDownRightAttacks);
    // std::cout << "\n nearestDiagonalUpLeftAttacks " << nearestDiagonalUpLeftAttacks.getValueOr(maxDiagonalUpLeftAttacks);
    // std::cout << "\n nearestDiagonalUpRightAttacks " << nearestDiagonalUpRightAttacks.getValueOr(maxDiagonalUpRightAttacks);

    return c_q - 1 - nearestLeftConstraint.getValueOr(0) +
            nearestRightConstraint.getValueOr(n + 1) - c_q - 1 +
            r_q - 1 - nearestDownConstraint.getValueOr(0) +
            nearestUpConstraint.getValueOr(n + 1) - r_q - 1 +
            nearestDiagonalDownLeftAttacks.getValueOr(maxDiagonalDownLeftAttacks + 1) - 1 +
            nearestDiagonalDownRightAttacks.getValueOr(maxDiagonalDownRightAttacks + 1) - 1 +
            nearestDiagonalUpLeftAttacks.getValueOr(maxDiagonalUpLeftAttacks + 1) - 1 +
            nearestDiagonalUpRightAttacks.getValueOr(maxDiagonalUpRightAttacks + 1) - 1;
}

} // namespace

const std::string QueensAttack::CHALLENGE_NAME_ = "QueensAttack";

QueensAttack::QueensAttack()
{
}

std::string QueensAttack::name() const
{
    return CHALLENGE_NAME_;
}

common::Result QueensAttack::run(std::istream&)// inputStream)
{
    displayProblem();

    logger.print("Inputs are disabled for this Challenge due to lack of design for it.");
    logger.print("Feature for it is queued. As of the moment to try this, manually edit .cpp file");

    // auto input = common::getUserInputString(inputStream);
    auto result = queensAttack(0, 0, 0, 0, {});
    logger.print("Result: ", result);

    result_.set(result);
    return result_;
}

void QueensAttack::displayProblem() const
{
    logger.print("You will be given a square chess board with one queen and a number of obstacles placed on it.");
    logger.print("Determine how many squares the queen can attack.");
    logger.print();
    logger.print("A queen is standing on an n x n chessboard. The chess board's rows are numbered from 1 to n, going from bottom to top. Its columns are numbered from 1 to n, going from left to right. Each square is referenced by a tuple, (r, c), describing the row, r, and column, c, where the square is located.");
    logger.print();
    logger.print("The queen is standing at position (r_q, c_q). In a single move, she can attack any square in any of the eight directions (left, right, up, down, and the four diagonals).");
    logger.print();
    logger.print("There are obstacles on the chessboard, each preventing the queen from attacking any square beyond it on that path. For example, an obstacle at location  in the diagram prevents the queen from attacking cells (3, 5), (2, 6), and (1, 7):");
    logger.print();
    logger.print("81  82  83  84  85  86  87  88");
    logger.print("71  72  73  74  75  76  77  78");
    logger.print("61  62  63  64  65  66  67  68");
    logger.print("51  52  53  54  55  56  57  58");
    logger.print("41  42  43  Q   45  46  47  48");
    logger.print("31  32  33  34  X   36  37  38");
    logger.print("21  22  23  24  25  26  27  28");
    logger.print("11  12  13  14  15  16  17  18");
    logger.print();
    logger.print("Given the queen's position and the locations of all the obstacles, find and print the number of squares the queen can attack from her position at (r_q, c_q). In the board above, there are 24 such squares.");
    logger.print();
    logger.print("Sample Input 0");
    logger.print("4 0");
    logger.print("4 4");
    logger.print("Sample Output 0");
    logger.print("9");
    logger.print();
    logger.print("Sample Input 1");
    logger.print("5 3");
    logger.print("4 3");
    logger.print("5 5");
    logger.print("4 2");
    logger.print("2 3");
    logger.print("Sample Output 1");
    logger.print("10");
    logger.print();
    logger.print("Sample Input 2");
    logger.print("1 0");
    logger.print("1 1");
    logger.print("Sample Output 2");
    logger.print("0");
}

    // auto answer = queensAttack(8, 0, 5, 4,
    //     {
    //         {8,3},
    //         {8,7},
    //         {7,4},
    //         {7,7},
    //         {6,3},
    //         {5,1},
    //         {3,2},
    //         {2,4},
    //         {1,6},
    //         {5,7},
    //     });
    // std::cout << "\n\n" <<answer; // answer is 14?

} // namespace src::challenges::hacker
