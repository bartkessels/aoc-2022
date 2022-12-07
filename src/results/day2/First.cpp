#include "results/day2/First.hpp"

using namespace AOC2022::results::day2;

First::First(std::shared_ptr<AOC2022::data::Repository> repo)
{
    input = std::make_shared<Input>(repo);
    game = std::make_shared<Game>();
}

int First::getResult()
{
    const auto& strategyGuide = input->getRounds();
    int totalScore = 0;

    for (const auto& round : strategyGuide) {
        totalScore += playRound(round);
    }

    return totalScore;
}

int First::playRound(std::shared_ptr<Round> round)
{
    const auto& outcome = game->playRound(round->oponentStrategy, round->ownStrategy);
    return game->getPoints(round->ownStrategy, outcome);
}