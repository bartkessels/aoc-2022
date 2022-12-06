#pragma once

#include <memory>

#include "results/day2/Strategy.hpp"
#include "results/day2/Outcome.hpp"

namespace AOC2022::results::day2
{
    struct Round
    {
        public:
            ~Round() = default;

            std::shared_ptr<Strategy> oponentStrategy;
            std::shared_ptr<Strategy> ownStrategy;
            std::shared_ptr<Outcome> expectedOutcome;
    };
}