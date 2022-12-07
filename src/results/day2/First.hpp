#pragma once

#include <string>
#include <memory>
#include <list>
#include <utility>

#include "results/day2/Input.hpp"
#include "results/day2/Game.hpp"
#include "results/day2/models/Round.hpp"

namespace AOC2022::results::day2
{
    class First
    {
        public:
            explicit First(std::shared_ptr<data::Repository> repo);
            ~First() = default;

            int getResult();
        
        private:
            std::shared_ptr<Input> input;
            std::shared_ptr<Game> game;

            int playRound(std::shared_ptr<Round> round);
    };
}