#include "results/day2/RoundOutcomeMapper.hpp"

using namespace AOC2022::results::day2;

int RoundOutcomeMapper::mapToPoints(RoundOutcome outcome)
{
    switch (outcome)
    {
        case RoundOutcome::Won:
            return 6;
        case RoundOutcome::Draw:
            return 3;
        case RoundOutcome::Lost:
            return 0;
    }
}
