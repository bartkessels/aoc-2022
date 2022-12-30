#include "results/day5/Second.hpp"

using namespace AOC2022::results::day5;

Second::Second(std::shared_ptr<AOC2022::data::Repository> repo)
{
    input = std::make_shared<Input>(repo);
    logic = std::make_shared<Logic>();
}

std::string Second::getResult()
{
    const auto& instructions = input->getInstructions();
    logic->executeInstructionsInOrder(instructions);
    return logic->getTopFromStacks();
}

void Second::setupData(bool isTestData)
{
    if (isTestData) {
        logic->setupTestStacks();
    } else {
        logic->setupRegularStacks();
    }
}