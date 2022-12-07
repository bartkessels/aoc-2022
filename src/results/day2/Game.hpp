#pragma once

#include <memory>

#include "results/day2/models/Strategy.hpp"
#include "results/day2/models/Outcome.hpp"

namespace AOC2022::results::day2
{
    class Game
    {
        public:
            ~Game() = default;

            Outcome playRound(Strategy oponentStrategy, Strategy ownStrategy);
            int getPoints(Strategy strategy, Outcome outcome);

        private:
            int getPointsForStrategy(Strategy strategy);
            int getPointsForOutcome(Outcome outcome);
    };
}