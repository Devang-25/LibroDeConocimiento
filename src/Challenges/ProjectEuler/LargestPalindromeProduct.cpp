#include <Challenges/ProjectEuler/LargestPalindromeProduct.hpp>

#include <math.h>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::euler
{
namespace
{

common::Logger logger("LargestPalindromeProduct");

unsigned getReverseOfNumber(unsigned number)
{
    unsigned numberReverse = 0u;
    while (number > 0)
    {
        numberReverse = (numberReverse * 10) + (number % 10);
        number = number / 10;
    }
    return numberReverse;
}

unsigned largestPalindromeProduct(unsigned digitsCount)
{
    unsigned lowerLimit = digitsCount == 1 ?
                            0u :
                            pow(10, (digitsCount - 1));
    unsigned upperLimit = pow(10, (digitsCount)) - 1;

    unsigned maxProduct = 0u;
    unsigned maxProductFactor1 = 0u;
    unsigned maxProductFactor2 = 0u;

    for (unsigned multiplicand = upperLimit; multiplicand >= lowerLimit; multiplicand--)
    {
        for (unsigned multiplier = multiplicand; multiplier >= lowerLimit; multiplier--)
        {
            unsigned product = multiplicand * multiplier;
            unsigned productReverse = getReverseOfNumber(product);

            if (product == productReverse && product > maxProduct)
            {
                maxProductFactor1 = multiplicand;
                maxProductFactor2 = multiplier;
                maxProduct = product;
            }

            if (product <= maxProduct) break;
        }
    }
    logger.print(maxProductFactor1, " * ", maxProductFactor2, " = ", maxProduct);
    return maxProduct;
}

} // namespace

const std::string LargestPalindromeProduct::CHALLENGE_NAME_ = "LargestPalindromeProduct";

LargestPalindromeProduct::LargestPalindromeProduct()
{
}

std::string LargestPalindromeProduct::name() const
{
    return CHALLENGE_NAME_;
}

common::Result LargestPalindromeProduct::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputIntegralOrFloating<unsigned>(inputStream);
    auto result = largestPalindromeProduct(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void LargestPalindromeProduct::displayProblem() const
{
    logger.print("A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.");
    logger.print("Find the largest palindrome made from the product of two 3-digit numbers.");
}

} // namespace src::challenges::euler
