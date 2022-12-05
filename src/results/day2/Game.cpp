#include "results/day2/Game.hpp"

using namespace AOC2022::results::day2;

RoundOutcome Game::playRound(Strategy oponentStrategy, Strategy ownStrategy)
{
    if (oponentStrategy == ownStrategy)
        return RoundOutcome::Draw;

    if (oponentStrategy == Strategy::Rock && ownStrategy == Strategy::Scissors)
        return RoundOutcome::Lost;

    if (oponentStrategy == Strategy::Paper && ownStrategy == Strategy::Rock)
        return RoundOutcome::Lost;

    if (oponentStrategy == Strategy::Scissors && ownStrategy == Strategy::Paper)
        return RoundOutcome::Lost;
        
    // If we haven't lost, we've won!
    return RoundOutcome::Won;
}