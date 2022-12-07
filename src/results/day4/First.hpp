#pragma once

#include <memory>
#include <string>

#include "data/Repository.hpp"
#include "results/day4/Input.hpp"
#include "results/day4/Logic.hpp"

namespace AOC2022::results::day4
{
    class First
    {
        public:
            explicit First(std::shared_ptr<data::Repository> repo);
            ~First() = default;

            int getResult();

        private:
            std::shared_ptr<Input> input;
            std::shared_ptr<Logic> logic;
    };
}