#include "results/day5/First.hpp"

using namespace AOC2022::results::day5;

First::First(std::shared_ptr<AOC2022::data::Repository> repo)
{
    input = std::make_shared<Input>(repo);
    logic = std::make_shared<Logic>();
}

std::string First::getResult()
{
    const auto& instructions = input->getInstructions();
    logic->executeInstructions(instructions);
    return logic->getTopFromStacks();
}

void First::setupData(bool isTestData)
{
    if (isTestData) {
        logic->setupTestStacks();
    } else {
        logic->setupRegularStacks();
    }
}