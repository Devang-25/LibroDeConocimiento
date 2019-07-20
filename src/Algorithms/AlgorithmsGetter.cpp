#include <Algorithms/AlgorithmsGetter.hpp>

#include <Algorithms/Graph/Bfs.hpp>
#include <Algorithms/IAlgorithm.hpp>

namespace src::algo
{

std::vector<std::shared_ptr<IAlgorithm>> getAllAlgorithms()
{
    return
        {
            std::make_shared<graph::Bfs>(),
        };
}

std::map<std::string, unsigned> getAlgorithmsNameAndIdMap(
    const std::vector<std::shared_ptr<IAlgorithm>>& algorithms)
{
    std::map<std::string, unsigned> nameAndId;

    unsigned id = 0;
    for (const auto& algorithm : algorithms)
    {
        nameAndId[algorithm->name()] = id;
        id++;
    }

    return nameAndId;
}

} // namespace src::algo
