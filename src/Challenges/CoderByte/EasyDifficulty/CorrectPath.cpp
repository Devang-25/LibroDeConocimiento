#include <Challenges/CoderByte/EasyDifficulty/CorrectPath.hpp>

#include <algorithm>
#include <string>
#include <vector>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::coderbyte::easy
{
namespace
{

common::Logger logger("CorrectPath");

const char directions[] = "lrud";

struct Coordinates
{
    int x;
    int y;

    bool operator==(const Coordinates& other)
    {
        return x == other.x && y == other.y;
    }
};

/*
00, 01, 02, 03, 04,
10, 11, 12, 13, 14,
20, 21, 22, 23, 24,
30, 31, 32, 33, 34,
40, 41, 42, 43, 44,
*/

const int MAX_COORDINATES = 4;
std::pair<bool, std::string> found = {false, ""};

std::string correctPathWithRepeatingNodes_shortestPath(
    std::string str,
    unsigned currentStrIndex,
    Coordinates currentCoordinates)
{
    // code goes here
    for (unsigned ctr = currentStrIndex; ctr < str.size() && !found.first; ctr++)
    {
        if (str[ctr] == '?')
        {
            unsigned directionsCtr = 0u;
            while (!found.first && directions[directionsCtr] != '\0')
            {
                std::string strCopy = str;
                strCopy[ctr] = directions[directionsCtr];
                correctPathWithRepeatingNodes_shortestPath(strCopy, ctr, currentCoordinates);
                directionsCtr++;
            }
            continue;
        }

        int newX = 0;
        int newY = 0;

        if (str[ctr] == 'l') newY--;
        else if (str[ctr] == 'r') newY++;
        else if (str[ctr] == 'u') newX--;
        else if (str[ctr] == 'd') newX++;

        currentCoordinates.x = currentCoordinates.x + newX;
        currentCoordinates.y = currentCoordinates.y + newY;

        if (currentCoordinates.x < 0 || currentCoordinates.x > MAX_COORDINATES ||
            currentCoordinates.y < 0 || currentCoordinates.y > MAX_COORDINATES)
        {
            return {};
        }
        else if (currentCoordinates.x == MAX_COORDINATES && currentCoordinates.y == MAX_COORDINATES)
        {
            found = {true, str.substr(0, ctr+1)};
        }
    }
    return found.second;
}

std::string correctPathWithoutRepeatingNodes_shortestPath(
    std::string str,
    unsigned currentStrIndex,
    Coordinates currentCoordinates,
    std::vector<Coordinates> visitedCoordinates = {{0,0}})
{
    // code goes here
    for (unsigned ctr = currentStrIndex; ctr < str.size() && !found.first; ctr++)
    {
        if (str[ctr] == '?')
        {
            unsigned directionsCtr = 0u;
            while (!found.first && directions[directionsCtr] != '\0')
            {
                std::string strCopy = str;
                strCopy[ctr] = directions[directionsCtr];
                correctPathWithoutRepeatingNodes_shortestPath(strCopy, ctr, currentCoordinates, visitedCoordinates);
                directionsCtr++;
            }
            continue;
        }

        int newX = 0;
        int newY = 0;

        if (str[ctr] == 'l') newY--;
        else if (str[ctr] == 'r') newY++;
        else if (str[ctr] == 'u') newX--;
        else if (str[ctr] == 'd') newX++;

        currentCoordinates.x = currentCoordinates.x + newX;
        currentCoordinates.y = currentCoordinates.y + newY;

        if (currentCoordinates.x < 0 || currentCoordinates.x > MAX_COORDINATES ||
            currentCoordinates.y < 0 || currentCoordinates.y > MAX_COORDINATES ||
            std::find(visitedCoordinates.begin(), visitedCoordinates.end(), currentCoordinates) != visitedCoordinates.end())
        {
            return {};
        }
        else if (currentCoordinates.x == MAX_COORDINATES && currentCoordinates.y == MAX_COORDINATES)
        {
            found = {true, str.substr(0, ctr+1)};
        }

        visitedCoordinates.push_back(currentCoordinates);
    }
    return found.second;
}

std::string correctPathWithoutRepeatingNodes(
    std::string str,
    unsigned currentStrIndex,
    Coordinates currentCoordinates,
    std::vector<Coordinates> visitedCoordinates = {{0,0}})
{
    // code goes here
    for (unsigned ctr = currentStrIndex; ctr < str.size() && !found.first; ctr++)
    {
        if (str[ctr] == '?')
        {
            unsigned directionsCtr = 0u;
            while (!found.first && directions[directionsCtr] != '\0')
            {
                std::string strCopy = str;
                strCopy[ctr] = directions[directionsCtr];
                correctPathWithoutRepeatingNodes(strCopy, ctr, currentCoordinates, visitedCoordinates);
                directionsCtr++;
            }
            continue;
        }

        int newX = 0;
        int newY = 0;

        if (str[ctr] == 'l') newY--;
        else if (str[ctr] == 'r') newY++;
        else if (str[ctr] == 'u') newX--;
        else if (str[ctr] == 'd') newX++;

        currentCoordinates.x = currentCoordinates.x + newX;
        currentCoordinates.y = currentCoordinates.y + newY;

        if (currentCoordinates.x < 0 || currentCoordinates.x > MAX_COORDINATES ||
            currentCoordinates.y < 0 || currentCoordinates.y > MAX_COORDINATES ||
            std::find(visitedCoordinates.begin(), visitedCoordinates.end(), currentCoordinates) != visitedCoordinates.end())
        {
            return {};
        }
        else if (currentCoordinates.x == MAX_COORDINATES && currentCoordinates.y == MAX_COORDINATES && (ctr + 1) == str.size())
        {
            found = {true, str.substr(0, ctr+1)};
        }

        visitedCoordinates.push_back(currentCoordinates);

    }
    return found.second;
}

std::string correctPath(const std::string& input)
{
    found = {};
    auto output1 = correctPathWithRepeatingNodes_shortestPath(input, 0, {0,0});

    found = {};
    auto output2 = correctPathWithoutRepeatingNodes_shortestPath(input, 0, {0,0});

    found = {};
    auto output3 = correctPathWithoutRepeatingNodes(input, 0, {0,0});

    logger.print("input                                         ", input);
    logger.print("correctPathWithRepeatingNodes_shortestPath    ", output1);
    logger.print("correctPathWithoutRepeatingNodes_shortestPath ", output2);
    logger.print("correctPathWithoutRepeatingNodes              ", output3);

    return output3;
}

} // namespace

const std::string CorrectPath::CHALLENGE_NAME_ = "CorrectPath";

CorrectPath::CorrectPath()
{
}

std::string CorrectPath::name() const
{
    return CHALLENGE_NAME_;
}

common::Result CorrectPath::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputString(inputStream);
    auto result = correctPath(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void CorrectPath::displayProblem() const
{
    logger.print("Have the function CorrectPath(str) read the str parameter being passed, which will represent the movements made in a 5x5 grid of cells starting from the top left position.");
    logger.print("The characters in the input string will be entirely composed of: r, l, u, d, ?.");
    logger.print("Each of the characters stand for the direction to take within the grid, for example: r = right, l = left, u = up, d = down.");
    logger.print("Your goal is to determine what characters the question marks should be in order for a path to be created to go from the top left of the grid all the way to the bottom right without touching previously travelled on cells in the grid.");
    logger.print("For example: if str is r?d?drdd then your program should output the final correct string that will allow a path to be formed from the top left of a 5x5 grid to the bottom right. For this input, your program should therefore return the string rrdrdrdd.");
    logger.print("There will only ever be one correct path and there will always be at least one question mark within the input string.");
    logger.print("Input: ???rrurdr?");
    logger.print("Output:dddrrurdrd");
    logger.print();
    logger.print("Input: drdr??rrddd?");
    logger.print("Output:drdruurrdddd");
    logger.print();
    logger.print("Input: ??rr???rrddd????rr??");
    logger.print("Output: ddrrulurrdddllldrrrr");
}

} // namespace src::challenges::coderbyte::easy
