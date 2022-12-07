#include "results/day3/First.hpp"

using namespace AOC2022::results::day3;

First::First(std::shared_ptr<data::Repository> repo)
{
    input = std::make_shared<Input>(repo);
    priorityMapper = std::make_shared<PriorityMapper>();
}

int First::getResult()
{
    const auto& ruckSacks = input->getRuckSacks();
    int totalPoints = 0;

    for (const auto& ruckSack : ruckSacks) {
        totalPoints += getPointsForRuckSack(ruckSack);
    }

    return totalPoints;
}

int First::getPointsForRuckSack(std::shared_ptr<RuckSack> ruckSack)
{
    for (char itemA : ruckSack->compartimentOne) {
        size_t foundPos = ruckSack->compartimentTwo.find(itemA);

        if (foundPos != std::string::npos)
            return priorityMapper->map(itemA);
    }

    throw "No matching characters!";
}