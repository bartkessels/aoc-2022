#include "results/day3/First.hpp"
#include <iostream>
using namespace AOC2022::results::day3;

First::First(std::shared_ptr<service::HttpService> httpService)
{
    dataCleaner = std::make_shared<DataCleaner>(httpService);
    priorityMapper = std::make_shared<PriorityMapper>();
}

int First::getResult()
{
    const auto& ruckSacks = dataCleaner->getData();
    int totalPoints = 0;

    for (const auto& ruckSack : ruckSacks) {
        totalPoints += getPointsForRuckSack(ruckSack);
    }

    return totalPoints;
}

char First::getSameItemForCompartiments(std::string firstCompartiment, std::string secondCompartiment)
{
    for (char itemA : firstCompartiment) {
        size_t foundPos = secondCompartiment.find(itemA);
        std::cout << "Item: " << itemA << std::endl;

        if (foundPos != std::string::npos)
            return itemA;
    }

    throw "No matching characters!";
}

int First::getPointsForRuckSack(std::pair<std::string, std::string> ruckSack)
{
    std::cout << "RS ----------------------" << std::endl;
    char sameItem = getSameItemForCompartiments(ruckSack.first, ruckSack.second);
    return priorityMapper->map(sameItem);
}