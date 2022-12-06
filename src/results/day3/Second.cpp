#include "results/day3/Second.hpp"
#include <iostream>

using namespace AOC2022::results::day3;

Second::Second(std::shared_ptr<service::HttpService> httpService)
{
    dataCleaner = std::make_shared<DataCleaner>(httpService);
    priorityMapper = std::make_shared<PriorityMapper>();
}

int Second::getResult()
{
    auto ruckSacks = dataCleaner->getDataAsRuckSacks();
    int totalPoints = 0;

    std::cout << "RUCKSACKS: " << ruckSacks.size() << std::endl;

    while (ruckSacks.size() > 0) {
        ruckSacks.swap()
    }

    for (int index = 0; index < ruckSacks.size(); index += 3) {
        const auto& ruckSackOne = ruckSacks.begin();
        const auto& ruckSackTwo = ruckSacks.begin()++;
        const auto& ruckSackThree = ruckSacks.begin()++++;

        totalPoints += getSameItemForRuckSacks(*ruckSackOne, *ruckSackTwo, *ruckSackThree);

        std::cout << "POINTS: " << totalPoints << std::endl;

        // Pop
        ruckSacks.pop_front();
        ruckSacks.pop_front();
        ruckSacks.pop_front();
    }

    return totalPoints;
}

char Second::getSameItemForRuckSacks(std::string ruckSackOne, std::string ruckSackTwo, std::string ruckSackThree)
{
    std::string biggestRuckSack = ruckSackOne;

    if (ruckSackTwo.size() > biggestRuckSack.size())
        biggestRuckSack = ruckSackTwo;
    if (ruckSackThree.size() > biggestRuckSack.size())
        biggestRuckSack = ruckSackThree;

    for (char item : biggestRuckSack) {
        size_t posRuckSackOne = ruckSackOne.find(item);
        size_t posRuckSackTwo = ruckSackTwo.find(item);
        size_t posRuckSackThree = ruckSackThree.find(item);

        std::cout << "CHAR: " << item << std::endl;

        if (posRuckSackOne != std::string::npos && posRuckSackTwo != std::string::npos && posRuckSackThree != std::string::npos)
            return item;
    }

    throw "No matching characters!";
}

int Second::getPointsForRuckSacks(std::string ruckSackOne, std::string ruckSackTwo, std::string ruckSackThree)
{
    char sameItem = getSameItemForRuckSacks(ruckSackOne, ruckSackTwo, ruckSackThree);
    return priorityMapper->map(sameItem);
}