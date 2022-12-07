#include "results/day2/Game.hpp"

using namespace AOC2022::results::day2;

Outcome Game::playRound(Strategy oponentStrategy, Strategy ownStrategy)
{
    if (oponentStrategy == ownStrategy)
        return Outcome::Draw;

    if (oponentStrategy == Strategy::Rock && ownStrategy == Strategy::Scissors)
        return Outcome::Lost;

    if (oponentStrategy == Strategy::Paper && ownStrategy == Strategy::Rock)
        return Outcome::Lost;

    if (oponentStrategy == Strategy::Scissors && ownStrategy == Strategy::Paper)
        return Outcome::Lost;
        
    // If we haven't lost, we've won!
    return Outcome::Won;
}

int Game::getPoints(Strategy strategy, Outcome outcome)
{
    return getPointsForStrategy(strategy) + getPointsForOutcome(outcome);
}

int Game::getPointsForStrategy(Strategy strategy)
{
    switch (strategy)
    {
        case Strategy::Rock:
            return 1;
        case Strategy::Paper:
            return 2;
        case Strategy::Scissors:
            return 3;
        default:
            throw "Unsupported strategy!";
    };
}

int Game::getPointsForOutcome(Outcome outcome)
{
    switch (outcome)
    {
        case Outcome::Won:
            return 6;
        case Outcome::Draw:
            return 3;
        case Outcome::Lost:
            return 0;
        default:
            throw "Unsupprted outcome!";
    }
}