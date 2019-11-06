#ifndef BFSALGORITHM_HPP
#define BFSALGORITHM_HPP

#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

namespace algo
{

struct Node
{
    char data;
    std::vector<Node*> connectedNodes;
    std::vector<std::unordered_set<Node*>> visitedNodePaths;
};

class BfsAlgorithm
{
public:
    BfsAlgorithm(const std::string& targetString);

    ~BfsAlgorithm();

    static const std::string NAME;

    unsigned operator()();

private:
    void prepareGraph();

    void createNodes();

    void connectNodes();

    void countFromPoint(
        const int row,
        const int col);

    std::vector<std::vector<Node*>> graph_;
    std::string targetString_;
    unsigned totalCount_;
};

} // namespace algo

#endif // BFSALGORITHM_HPP
