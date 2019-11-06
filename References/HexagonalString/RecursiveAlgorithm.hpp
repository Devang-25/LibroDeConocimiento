#ifndef RECURSIVEALGORITHM_HPP
#define RECURSIVEALGORITHM_HPP

#include <string>
#include <unordered_set>
#include <utility>

namespace algo
{

class PairHash
{
public:
    size_t operator()(const std::pair<int, int>& intPair) const;
};

class RecursiveAlgorithm
{
public:
    RecursiveAlgorithm(const std::string& targetString);

    static const std::string NAME;

    unsigned operator()();

private:
    void countFromPoint(
        const int row,
        const int col,
        const unsigned currentIndex,
        std::unordered_set<std::pair<int, int>, PairHash> processedRowColPairs);

    std::string targetString_;
    unsigned totalCount_;
};

} // namespace algo

#endif // RECURSIVEALGORITHM_HPP
