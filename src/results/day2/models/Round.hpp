#pragma once

#include "results/day2/models/Strategy.hpp"
#include "results/day2/models/Outcome.hpp"

namespace AOC2022::results::day2
{
    struct Round
    {
        public:
            ~Round() = default;

            Strategy oponentStrategy;
            Strategy ownStrategy;
            Outcome expectedOutcome;
    };
}