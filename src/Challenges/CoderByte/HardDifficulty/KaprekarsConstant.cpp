#include <Challenges/CoderByte/HardDifficulty/KaprekarsConstant.hpp>

#include <algorithm>
#include <math.h>
#include <vector>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::coderbyte::hard
{
namespace
{

common::Logger logger("KaprekarsConstant");

std::vector<int> transformToSeriesOfDigits(int number, const unsigned digitsCount)
{
    std::vector<int> digits;

    for (int ctr = 0; number > 0; ctr++)
    {
        int digit = number % 10;
        digits.push_back(digit);

        number = number / 10;
    }
    for (unsigned ctr = digits.size(); ctr < digitsCount; ctr++)
    {
        digits.push_back(0);
    }

    return digits;
}

int transformToOneInteger(const std::vector<int>& digits)
{
    if (digits.empty()) return 0;

    int answer = digits.at(digits.size() - 1);
    int powerRaise = 1;

    for (int digitsCtr = digits.size() - 2; digitsCtr >= 0; digitsCtr--, powerRaise++)
    {
        answer = answer + (digits.at(digitsCtr) * (pow(10, powerRaise)));
    }

    return answer;
}

int kaprekarsConstant(int number)
{
    // code goes here
    const unsigned DIGITS_COUNT = 4;
    const int TARGET_ANSWER = 6174;
    unsigned count = 0;

    do
    {
        std::vector<int> digits = transformToSeriesOfDigits(number, DIGITS_COUNT);

        std::sort(digits.begin(), digits.end());
        int ascending = transformToOneInteger(digits);

        std::reverse(digits.begin(), digits.end());
        int descending = transformToOneInteger(digits);

        number = descending - ascending;
        count++;
    }
    while (number != TARGET_ANSWER);

    return count;
}

} // namespace

const std::string KaprekarsConstant::CHALLENGE_NAME_ = "KaprekarsConstant";

KaprekarsConstant::KaprekarsConstant()
{
}

std::string KaprekarsConstant::name() const
{
    return CHALLENGE_NAME_;
}

common::Result KaprekarsConstant::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputIntegralOrFloating<int>(inputStream);
    auto result = kaprekarsConstant(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void KaprekarsConstant::displayProblem() const
{
    logger.print("Have the function KaprekarsConstant(num) take the num parameter being passed which will be a 4-digit number with at least two distinct digits.");
    logger.print("Your program should perform the following routine on the number:");
    logger.print("Arrange the digits in descending order and in ascending order (adding zeroes to fit it to a 4-digit number), and subtract the smaller number from the bigger number.");
    logger.print("Then repeat the previous step.");
    logger.print("Performing this routine will always cause you to reach a fixed number: 6174.");
    logger.print("Then performing the routine on 6174 will always give you 6174 (7641 - 1467 = 6174).");
    logger.print("Your program should return the number of times this routine must be performed until 6174 is reached.");
    logger.print("For example: if num is 3524 your program should return 3 because of the following steps:");
    logger.print("(1) 5432 - 2345 = 3087, (2) 8730 - 0378 = 8352, (3) 8532 - 2358 = 6174. ");
}

} // namespace src::challenges::coderbyte::hard
