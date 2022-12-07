#include "results/day4/First.hpp"

using namespace AOC2022::results::day4;

First::First(std::shared_ptr<AOC2022::data::Repository> repo)
{
    input = std::make_shared<Input>(repo);
    logic = std::make_shared<Logic>();
}

int First::getResult()
{
    const auto& assigments = input->getAssignments();
    int totalPoints = 0;

    for (const auto& assignment : assigments) {
        if (logic->rangesIncludedInEachOther(assignment->firstElf, assignment->secondElf))
            totalPoints++;
    }

    return totalPoints;
}