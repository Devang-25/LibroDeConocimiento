#include <Challenges/CoderByte/EasyDifficulty/LetterCapitalize.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::coderbyte::easy
{
namespace
{

common::Logger logger("LetterCapitalize");

bool isCharSmallLetter(const char ch)
{
    return ch >= 'a' && ch <= 'z';
}

void convertToSmallLetter(char& ch)
{
    ch = ch - 32;
}

std::string letterCapitalize(std::string str)
{
    // code goes here
    for (unsigned ctr = 0; ctr < str.size(); ctr++)
    {
        if (ctr != 0 && str[ctr-1] != ' ') continue;
        if (isCharSmallLetter(str[ctr]))
        {
            convertToSmallLetter(str[ctr]);
        }
    }
    return str;
}

} // namespace

const std::string LetterCapitalize::CHALLENGE_NAME_ = "LetterCapitalize";

LetterCapitalize::LetterCapitalize()
{
}

std::string LetterCapitalize::name() const
{
    return CHALLENGE_NAME_;
}

common::Result LetterCapitalize::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputString(inputStream);
    auto result = letterCapitalize(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void LetterCapitalize::displayProblem() const
{
    logger.print("Have the function LetterCapitalize(str) take the str parameter being passed and capitalize the first letter of each word.");
    logger.print("Words will be separated by only one space.");
}

} // namespace src::challenges::coderbyte::easy
