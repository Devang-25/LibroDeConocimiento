#include <Challenges/HackerRank/NonDivisibleSubset.hpp>

#include <bits/stdc++.h>

#include <boost/algorithm/string.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::hacker
{
namespace
{

common::Logger logger("NonDivisibleSubset");

// SOLUTION 1 : Non-optimized version
// unsigned maxCount = 0;

// bool willNewNumberIntoVectorResultToDivisibleNumber(
//     const std::vector<int>& numbers,
//     const int newNumber,
//     const int divisibleNumber)
// {
//     return std::any_of(numbers.begin(), numbers.end(),
//         [&newNumber, &divisibleNumber](const int vectorNumber)
//         {
//             return (vectorNumber + newNumber) % divisibleNumber == 0;
//         });
// }

// int nonDivisibleSubset(
//     const int k,
//     const std::vector<int>& s,
//     std::vector<int> subset)
// {
//     for (unsigned ctr = 0u; ctr < s.size(); ++ctr)
//     {
//         if (subset.size() + s.size() <= maxCount) return maxCount;
//         if (willNewNumberIntoVectorResultToDivisibleNumber(subset, s.at(ctr), k))
//         {
//             continue;
//         }

//         subset.push_back(s.at(ctr));
//         if (subset.size() > maxCount)
//         {
//             maxCount = subset.size();
//         }

//         nonDivisibleSubset(k, {s.begin() + ctr + 1, s.end()}, subset);
//         subset.pop_back();
//     }

//     return maxCount;
// }

// SOLUTION 2 : Optimized version
using Digit = int;
using Count = int;

int nonDivisibleSubset(
    const int k,
    const std::vector<int>& s)
{
    std::unordered_map<Digit, Count> digitCountMap;
    for (const auto& digit : s)
    {
        ++(digitCountMap[digit % k]);
    }

    int maxCount = digitCountMap.count(0);

    int mid = k / 2;
    if (mid + mid == k)
    {
        --mid;
        if (digitCountMap.count(mid))
        {
            ++maxCount;
        }
    }

    for (int ctr = 1; ctr <= mid; ++ctr)
    {
        maxCount += std::max(digitCountMap[ctr], digitCountMap[k-ctr]);
    }

    return maxCount;
}

int nonDivisibleSubset(const std::string& input)
{
    // maxCount = 0u; // For SOLUTION 1

    std::vector<std::string> splittedInputs;
    boost::split(splittedInputs, input, boost::is_any_of(" "));

    int k = std::stoi(splittedInputs[0]);
    std::vector<int> s;
    for (unsigned ctr = 1u; ctr < splittedInputs.size(); ++ctr)
    {
        s.push_back(std::stoi(splittedInputs[ctr]));
    }

    return nonDivisibleSubset(k, s);
}

} // namespace

const std::string NonDivisibleSubset::CHALLENGE_NAME_ = "NonDivisibleSubset";

NonDivisibleSubset::NonDivisibleSubset()
{
}

std::string NonDivisibleSubset::name() const
{
    return CHALLENGE_NAME_;
}

common::Result NonDivisibleSubset::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputString(inputStream);
    auto result = nonDivisibleSubset(input);
    logger.print("Result: ", result);

    result_.set(result);
    return result_;
}

void NonDivisibleSubset::displayProblem() const
{
    logger.print("Given a set of distinct integers, print the size of a maximal subset of S where the sum of any 2 numbers in S\" is not evenly divisible by k.");
    logger.print("For example, the array S = [19, 10, 12, 10, 24, 25, 22] and k = 4. One of the arrays that can be created is S\"[0] = [10, 12, 25]. Another is S\"[1] = [19, 22, 24]. After testing all permutations, the maximum length solution array has 3 elements.");
    logger.print("Input format should be: [Divisible number] [Vector of numbers to search for]");
    logger.print("Example: 3 1 7 2 4");
    logger.print("    This means to search [1 7 2 4] for combinations not divisible by [3]");
    logger.print("Sample Test Cases");
    logger.print("Input: 3 1 7 2 4");
    logger.print("Output: 3");
    logger.print("Input: 7 278 576 496 727 410 124 338 149 209 702 282 718 771 575 436");
    logger.print("Output: 11");
    logger.print("Input: 100 309267605 950194689 233722125 213126284 803693764 8935112 996038935 584313952 914835305 801525456 866383133 362172865 863648229 286776502 692327018 666753852 355282290 17871142 298513364 385271128 381614363 51907124 524655580 318461672 856056174 743148359 122540533 894882430 461004263 770611637 195891196 250883515 88820738 101970673 922112577 704068081 430304169 190207059 354357071 500100938 738432380 524997841 775875005 403466223 96414507 235932505 855760945 869180428 924648274 17349551 683594506 928312664 682231587 851074570 769192164 754107180 978356507 748489842 57037209 285121804");
    logger.print("Output: 52");
}

} // namespace src::challenges::hacker
