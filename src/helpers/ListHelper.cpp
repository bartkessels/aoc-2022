#include "helpers/ListHelper.hpp"

using namespace AOC2022::helpers;

int ListHelper::countAllNumbersFromList(std::list<std::string> list)
{
    int total = 0;

    for (auto iterator = list.begin(); iterator != list.end(); ++iterator) {
        total += std::stoi(*iterator);
    }

    return total;
}

int ListHelper::countAllNumbersFromList(std::list<int> list)
{
    int total = 0;

    for (auto iterator = list.begin(); iterator != list.end(); ++iterator) {
        total += *iterator;
    }

    return total;
}

std::list<int> ListHelper::stringLinesToList(std::string block)
{
    const std::string delimiter = "\n";
    std::string input = block;
    std::list<int> numbers;

    size_t pos = 0;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        std::string token = input.substr(0, pos);
        numbers.push_back(std::stoi(token));

        input.erase(0, pos + delimiter.length());
    }

    if (!input.empty()) {
        numbers.push_back(std::stoi(input));
    }
    
    return numbers;
}