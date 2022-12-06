#include "results/day3/Second.hpp"

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

    for (auto it = ruckSacks.begin(); it != ruckSacks.end(); std::advance(it, 3)) {
        const auto& ruckSackOne = it;
        const auto& ruckSackTwo = std::next(ruckSackOne);
        const auto& ruckSackThree = std::next(ruckSackTwo);

        totalPoints += getPointsForRuckSacks(*ruckSackOne, *ruckSackTwo, *ruckSackThree);
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