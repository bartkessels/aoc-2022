#include "results/day3/Second.hpp"

using namespace AOC2022::results::day3;

Second::Second(std::shared_ptr<AOC2022::data::Repository> repo)
{
    input = std::make_shared<Input>(repo);
    priorityMapper = std::make_shared<PriorityMapper>();
}

int Second::getResult()
{
    auto ruckSacks = input->getRuckSacks();
    int totalPoints = 0;

    for (auto it = ruckSacks.begin(); it != ruckSacks.end(); std::advance(it, 3)) {
        const auto& ruckSackOne = it;
        const auto& ruckSackTwo = std::next(ruckSackOne);
        const auto& ruckSackThree = std::next(ruckSackTwo);

        totalPoints += getPointsForRuckSacks(*ruckSackOne, *ruckSackTwo, *ruckSackThree);
    }

    return totalPoints;
}

int Second::getPointsForRuckSacks(std::shared_ptr<RuckSack> ruckSackOne, std::shared_ptr<RuckSack> ruckSackTwo, std::shared_ptr<RuckSack> ruckSackThree)
{
    std::string biggestRuckSack = ruckSackOne->getContents();

    if (ruckSackTwo->getContents().size() > biggestRuckSack.size())
        biggestRuckSack = ruckSackTwo->getContents();
    if (ruckSackThree->getContents().size() > biggestRuckSack.size())
        biggestRuckSack = ruckSackThree->getContents();

    for (char item : biggestRuckSack) {
        size_t posRuckSackOne = ruckSackOne->getContents().find(item);
        size_t posRuckSackTwo = ruckSackTwo->getContents().find(item);
        size_t posRuckSackThree = ruckSackThree->getContents().find(item);

        if (posRuckSackOne != std::string::npos && posRuckSackTwo != std::string::npos && posRuckSackThree != std::string::npos)
            return priorityMapper->map(item);
    }

    throw "No matching characters!";
}
