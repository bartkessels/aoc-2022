#pragma once

#include "results/day2/Constants.hpp"

namespace AOC2022::results::day2
{
    class RoundOutcomeMapper
    {
        public:
            ~RoundOutcomeMapper() = default;

            int mapToPoints(RoundOutcome outcome);
            RoundOutcome mapDecision(char decision);
    };
}