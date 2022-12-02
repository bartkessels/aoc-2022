#include "results/day1/First.hpp"

using namespace AOC2022::results::day1;

First::First(std::shared_ptr<service::HttpService> httpService):
    Result(httpService, First::uri)
{

}

int First::getResult()
{
    // Get blocks
    int highestNumber = 0;
    std::list<std::string> blocks = getBlocks();
    
    for (auto blockIterator = blocks.begin(); blockIterator != blocks.end(); ++blockIterator) {
        const auto& blockList = blockToList(*blockIterator);
        int total = countAllNumbersFromList(blockList);
        
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

std::list<int> First::blockToList(std::string block)
{
    const std::string delimiter = "\n";
    std::string input = block;
    std::list<int> numbers;

    size_t pos = 0;
    std::string token;

    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        numbers.push_back(std::stoi(token));

        input.erase(0, pos + delimiter.length());
    }

    if (!input.empty()) {
        numbers.push_back(std::stoi(input));
    }
    
    return numbers;
}

int First::countAllNumbersFromList(std::list<int> list)
{
    int total = 0;

    for (auto iterator = list.begin(); iterator != list.end(); ++iterator) {
        total += *iterator;
    }

    return total;
}