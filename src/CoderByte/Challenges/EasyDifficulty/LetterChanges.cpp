#include <CoderByte/Challenges/EasyDifficulty/LetterChanges.hpp>

#include <set>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::coderbyte::challenges::easy
{
namespace
{

common::Logger logger("LetterChanges");

const std::set<char> VOWELS =
{
    'a',
    'e',
    'i',
    'o',
    'u',
};

std::string letterChanges(const std::string& str)
{
    // code goes here
    std::string result;

    for (unsigned ctr = 0; ctr < str.size(); ctr++)
    {
        char ch = str.at(ctr);

        if ((ch >= 'A' && ch <= 'Y') ||
            (ch >= 'a' && ch <= 'y'))
        {
            ch++;
            if (VOWELS.count(ch))
            {
                ch = ch - 32;
            }
        }
        else if (ch == 'Z' || ch == 'z')
        {
            ch = 'A';
        }

        result = result + ch;
    }

    return result;
}

} // namespace

const std::string LetterChanges::CHALLENGE_NAME_ = "LetterChanges";

LetterChanges::LetterChanges()
{
}

std::string LetterChanges::name() const
{
    return CHALLENGE_NAME_;
}

common::Result LetterChanges::run()
{
    displayProblem();
    auto input = common::getUserInputString();
    auto result = letterChanges(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void LetterChanges::displayProblem() const
{
    logger.print("Have the function LetterChanges(str) take the str parameter being passed and modify it using the following algorithm.");
    logger.print("Replace every letter in the string with the letter following it in the alphabet (ie. c becomes d, z becomes a).");
    logger.print("Then capitalize every vowel in this new string (a, e, i, o, u) and finally return this modified string.");
}

} // namespace src::coderbyte::challenges::easy
