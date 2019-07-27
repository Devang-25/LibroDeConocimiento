#include <Challenges/ProjectEuler/LargestProductInASeries.hpp>

#include <boost/algorithm/string.hpp>
#include <deque>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::euler
{
namespace
{

common::Logger logger("LargestProductInASeries");

std::pair<std::string, std::string> parseInput(const std::string& input)
{
    std::vector<std::string> splittedInput;
    boost::split(splittedInput, input, boost::is_any_of(" "));

    return splittedInput.size() == 2 ?
            std::make_pair(splittedInput.at(0), splittedInput.at(1)) :
            std::make_pair("0", "0");
}

inline int convertChToInt(const char ch)
{
    return ch - '0';
}

long multiplyNumbers(const std::deque<int>& numbers)
{
    long product = 1;
    for (const auto& num : numbers)
    {
        product = product * num;
    }
    return product;
}

void printNumbers(const std::deque<int>& numbers)
{
    std::string numbersStr = "";
    for (const auto& num : numbers)
    {
        numbersStr = numbersStr + std::to_string(num);
    }
    logger.print("Numbers: ", numbersStr);
}

long largestProductInASeries(const std::string& input)
{
    auto [adjacentCountStr, numbersStr] = parseInput(input); // C++ 17 Structured bindings :)
    unsigned adjacentCount = std::stoul(adjacentCountStr);

    std::deque<int> currentNumbers;
    long currentProduct = 0;

    std::deque<int> largestProductNumbers;
    long largestProduct = 0;

    unsigned ctr = 0u;
    while (ctr < numbersStr.size())
    {
        // If current number is 0, no need to iterate through it as any combintaion will result to 0.
        // Clear current state to start anew on next element.
        if (int currentNumber = convertChToInt(numbersStr.at(ctr)); currentNumber == 0) // C++ 17 Init if :)
        {
            currentNumbers.clear();
            currentProduct = 0;
            ctr++;
            continue;
        }

        // To not multiply all numbers everytime when moving 1 step, just divide the last product
        // computed with the number to be removed from the factors (which is the front in queue) and
        // then just multiply with the new factor.
        int previousFront = 0;
        if (!currentNumbers.empty())
        {
            previousFront = currentNumbers.front();
            currentNumbers.pop_front();
        }

        // Replace the removal of queue's front (in other words, the leftmost digit) with the next element.
        while (currentNumbers.size() < adjacentCount && ctr < numbersStr.size())
        {
            int number = convertChToInt(numbersStr.at(ctr));
            currentNumbers.push_back(number);
            ctr++;
        }

        if (currentNumbers.size() != adjacentCount) continue;

        currentProduct = (currentProduct == 0) ?
                            multiplyNumbers(currentNumbers) :
                            (currentProduct / previousFront) * currentNumbers.back();
        if (currentProduct > largestProduct)
        {
            largestProduct = currentProduct;
            largestProductNumbers = currentNumbers;
        }
    }

    printNumbers(largestProductNumbers);
    return largestProduct;
}

} // namespace

const std::string LargestProductInASeries::CHALLENGE_NAME_ = "LargestProductInASeries";

LargestProductInASeries::LargestProductInASeries()
{
}

std::string LargestProductInASeries::name() const
{
    return CHALLENGE_NAME_;
}

common::Result LargestProductInASeries::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputString(inputStream);
    auto result = largestProductInASeries(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void LargestProductInASeries::displayProblem() const
{
    logger.print("The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.");
    logger.print("7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450");
    logger.print("Find the thirteen adjacent digits in the 1000-digit number that have the greatest product.");
    logger.print("What is the value of this product?");
    logger.print("Input format: [Nummber of adjacent digits][space][n-digit number]");
    logger.print("Example input:");
    logger.print("\t4 70560574902614079729686524145351004748216637048440319989000889524345065854122758");
    logger.print("Example input:");
    logger.print("\t13 73167176531330624919225119674426574742355349194934969835203127745063262395783180");
}

} // namespace src::challenges::euler
