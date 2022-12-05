#pragma once

#include "results/day2/Constants.hpp"

namespace AOC2022::results::day2
{
    class StrategyMapper
    {
        public:
            ~StrategyMapper() = default;

            int mapToPoints(Strategy strategy);
            Strategy mapStrategy(char strategy);
    };
}