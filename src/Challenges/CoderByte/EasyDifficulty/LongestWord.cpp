#include <Challenges/CoderByte/EasyDifficulty/LongestWord.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::coderbyte::easy
{
namespace
{

common::Logger logger("LongestWord");

std::string longestWord(const std::string& sen)
{
    // code goes here
    std::string winner = "";
    std::string challenger = "";

    for (unsigned a = 0; a < sen.size(); a++)
    {
        char ch = sen.at(a);

        if ((ch >= 65 && ch <= 90) ||
            (ch >= 97 && ch <= 122))
        {
            challenger = challenger + ch;
            continue;
        }
        if (challenger.size() > winner.size())
        {
            winner = challenger;
        }

        challenger = "";
    }

    return challenger.size() > winner.size() ? challenger : winner;
}

} // namespace

const std::string LongestWord::CHALLENGE_NAME_ = "LongestWord";

LongestWord::LongestWord()
{
}

std::string LongestWord::name() const
{
    return CHALLENGE_NAME_;
}

common::Result LongestWord::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputString(inputStream);
    auto result = longestWord(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void LongestWord::displayProblem() const
{
    logger.print("Have the function LongestWord(sen) take the sen parameter being passed and return the largest word in the string.");
    logger.print("If there are two or more words that are the same length, return the first word from the string with that length.");
    logger.print("Ignore punctuation and assume sen will not be empty.");
}

} // namespace src::challenges::coderbyte::easy
