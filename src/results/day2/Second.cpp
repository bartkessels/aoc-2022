#include "results/day2/Second.hpp"

using namespace AOC2022::results::day2;

Second::Second(std::shared_ptr<AOC2022::data::Repository> repo)
{
    input = std::make_shared<Input>(repo);
    game = std::make_shared<Game>();
}

int Second::getResult()
{

    const auto& strategyGuide = input->getRounds();
    int totalScore = 0;

    for (const auto& round : strategyGuide) {
        round->ownStrategy = getOwnStrategy(round);
        totalScore += playRound(round);
    }

    return totalScore;
}

int Second::playRound(std::shared_ptr<Round> round)
{
    const auto& outcome = game->playRound(round->oponentStrategy, round->ownStrategy);
    return game->getPoints(round->ownStrategy, outcome);
}

Strategy Second::getOwnStrategy(std::shared_ptr<Round> round)
{
    if (round->expectedOutcome == Outcome::Draw)
        return round->oponentStrategy;

    if (round->expectedOutcome == Outcome::Won)
    {
        if (round->oponentStrategy == Strategy::Rock)
            return Strategy::Paper;
        if (round->oponentStrategy == Strategy::Paper)
            return Strategy::Scissors;
        if (round->oponentStrategy == Strategy::Scissors)
            return Strategy::Rock;
    }

    if (round->oponentStrategy == Strategy::Rock)
        return Strategy::Scissors;
    if (round->oponentStrategy == Strategy::Paper)
        return Strategy::Rock;
    if (round->oponentStrategy == Strategy::Scissors)
        return Strategy::Paper;

    throw "No valid strategy!";
}