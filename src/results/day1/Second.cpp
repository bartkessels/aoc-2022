#include "results/day1/Second.hpp"

using namespace AOC2022::results::day1;

Second::Second(std::shared_ptr<data::Repository> repo)
{
    listHelper = std::make_unique<AOC2022::helpers::ListHelper>();
    input = std::make_unique<Input>(repo);
}

int Second::getResult()
{
    // Get blocks
    std::list<int> totals;
    const auto& blocks = input->getBlocks();
    
    for (auto blockIterator = blocks.begin(); blockIterator != blocks.end(); ++blockIterator) {
        int total = listHelper->countAllNumbersFromList((*blockIterator)->contents);
        
        totals.push_back(total);
    }
    
    totals.sort(std::greater<int>());

    while (totals.size() > 3) {
        totals.pop_back();
    }

    return listHelper->countAllNumbersFromList(totals);
}
