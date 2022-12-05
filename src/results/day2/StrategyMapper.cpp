#include "results/day2/StrategyMapper.hpp"

using namespace AOC2022::results::day2;

Strategy StrategyMapper::mapStrategy(char strategy)
{
    switch (strategy)
    {
        case 'A':
        case 'X':
            return Strategy::Rock;
        case 'B':
        case 'Y':
            return Strategy::Paper;
        case 'C':
        case 'Z':
            return Strategy::Scissors;
        default:
            throw "Unsupported own strategy!";
    }
}

int StrategyMapper::mapToPoints(Strategy strategy)
{
    switch (strategy)
    {
        case Strategy::Rock:
            return 1;
        case Strategy::Paper:
            return 2;
        case Strategy::Scissors:
            return 3;
    };
}