#pragma once

#include <string>
#include <memory>
#include <list>
#include <utility>

#include "results/day2/Input.hpp"
#include "results/day2/Game.hpp"
#include "results/day2/models/Round.hpp"
#include "results/day2/models/Strategy.hpp"

namespace AOC2022::results::day2
{
    class Second
    {
        public:
            explicit Second(std::shared_ptr<data::Repository> repo);
            ~Second() = default;

            int getResult();
        
        private:
            std::shared_ptr<Input> input;
            std::shared_ptr<Game> game;

            int playRound(std::shared_ptr<Round> round);
            Strategy getOwnStrategy(std::shared_ptr<Round> round);
    };
}