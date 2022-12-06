#include "results/day1/First.hpp"

using namespace AOC2022::results::day1;

First::First(std::shared_ptr<data::Repository> repo)
{
    listHelper = std::make_unique<AOC2022::helpers::ListHelper>();
    input = std::make_unique<Input>(repo);
}

int First::getResult()
{
    int highestNumber = 0;
    const auto& blocks = input->getBlocks();
    
    for (auto blockIterator = blocks.begin(); blockIterator != blocks.end(); ++blockIterator) {
        int total = listHelper->countAllNumbersFromList((*blockIterator)->contents);
        
        highestNumber = std::max(highestNumber, total);
    }
    
    return highestNumber;
}