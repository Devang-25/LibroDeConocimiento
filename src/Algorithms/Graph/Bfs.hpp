#ifndef SRC_ALGORITHMS_GRAPH_BFS_HPP
#define SRC_ALGORITHMS_GRAPH_BFS_HPP

#include <Algorithms/IAlgorithm.hpp>

namespace src::algo::graph
{

class Bfs : public IAlgorithm
{
public:
    Bfs();

    virtual std::string name() const override;

    virtual common::Result run(std::istream& inputStream = std::cin) override;

    virtual void displayGuide() const override;

private:
    static const std::string ALGORITHM_NAME_;

    common::Result result_;
};

} // namespace src::algo::graph

#endif // SRC_ALGORITHMS_GRAPH_BFS_HPP
