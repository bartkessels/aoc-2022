#include "results/day2/OutcomeMapper.hpp"

using namespace AOC2022::results::day2;

int OutcomeMapper::mapToPoints(Outcome outcome)
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
            return -1;
    }
}

Outcome OutcomeMapper::mapDecision(char decision)
{
    switch(decision)
    {
        case 'X':
            return Outcome::Lost;
        case 'Y':
            return Outcome::Draw;
        case 'Z':
            return Outcome::Won;
        default:
            throw "Unknown decision!";
    }
}
