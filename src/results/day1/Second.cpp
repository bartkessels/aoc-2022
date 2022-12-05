#include "results/day1/Second.hpp"

using namespace AOC2022::results::day1;

Second::Second(std::shared_ptr<service::HttpService> httpService):
    Result(httpService, Second::uri)
{
    listHelper = std::make_shared<AOC2022::helpers::ListHelper>();
}

int Second::getResult()
{
    // Get blocks
    std::list<int> totals;
    std::list<std::string> blocks = getBlocks();
    
    for (auto blockIterator = blocks.begin(); blockIterator != blocks.end(); ++blockIterator) {
        const auto& blockList = listHelper->stringLinesToList(*blockIterator);
        int total = listHelper->countAllNumbersFromList(blockList);
        
        totals.push_back(total);
    }
    
    totals.sort(std::greater<int>());

    while (totals.size() > 3) {
        totals.pop_back();
    }

    return listHelper->countAllNumbersFromList(totals);
}

std::list<std::string> Second::getBlocks()
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
