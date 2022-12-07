#include "results/day4/Second.hpp"

using namespace AOC2022::results::day4;

Second::Second(std::shared_ptr<AOC2022::data::Repository> repo)
{
    input = std::make_shared<Input>(repo);
    logic = std::make_shared<Logic>();
}

int Second::getResult()
{
    const auto& assigments = input->getAssignments();
    int totalPoints = 0;

    for (const auto& assignment : assigments) {
        if (logic->rangesThatOverlap(assignment->firstElf, assignment->secondElf))
            totalPoints++;
    }

    return totalPoints;
}