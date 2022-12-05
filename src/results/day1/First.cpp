#include "results/day1/First.hpp"

using namespace AOC2022::results::day1;

First::First(std::shared_ptr<service::HttpService> httpService):
    Result(httpService, First::uri)
{
    listHelper = std::make_shared<AOC2022::helpers::ListHelper>();
}

int First::getResult()
{
    // Get blocks
    int highestNumber = 0;
    std::list<std::string> blocks = getBlocks();
    
    for (auto blockIterator = blocks.begin(); blockIterator != blocks.end(); ++blockIterator) {
        const auto& blockList = listHelper->stringLinesToList(*blockIterator);
        int total = listHelper->countAllNumbersFromList(blockList);
        
        highestNumber = std::max(highestNumber, total);
    }
    
    return highestNumber;
}

std::list<std::string> First::getBlocks()
{
    const std::string delimiter = "\n\n";
    std::string input = getData();
    std::list<std::string> blocks;

    size_t pos = 0;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        std::string token = input.substr(0, pos);
        blocks.push_back(token);

        input.erase(0, pos + delimiter.length());
    }

    if (!input.empty()) {
        blocks.push_back(input);
    }

    return blocks;
}