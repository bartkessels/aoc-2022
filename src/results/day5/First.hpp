#pragma once

#include <memory>
#include <string>

#include "data/Repository.hpp"
#include "results/day5/Input.hpp"
#include "results/day5/Logic.hpp"

namespace AOC2022::results::day5
{
    class First
    {
        public:
            explicit First(std::shared_ptr<data::Repository> repo);
            ~First() = default;

            std::string getResult();
            void setupData(bool isTestData = false);

        private:
            std::shared_ptr<Input> input;
            std::shared_ptr<Logic> logic;
    };
}