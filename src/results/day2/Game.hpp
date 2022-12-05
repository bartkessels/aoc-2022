#pragma once

#include <memory>

#include "results/day2/Constants.hpp"

namespace AOC2022::results::day2
{
    class Game
    {
        public:
            ~Game() = default;

            RoundOutcome playRound(Strategy oponentStrategy, Strategy ownStrategy);
    };
}