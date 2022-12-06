#pragma once

#include "results/day2/Outcome.hpp"

namespace AOC2022::results::day2
{
    class OutcomeMapper
    {
        public:
            ~OutcomeMapper() = default;

            int mapToPoints(Outcome outcome);
            Outcome mapDecision(char decision);
    };
}