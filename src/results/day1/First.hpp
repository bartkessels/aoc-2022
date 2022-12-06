#pragma once

#include <string>
#include <list>

#include "data/Repository.hpp"
#include "helpers/ListHelper.hpp"
#include "results/day1/Input.hpp"

namespace AOC2022::results::day1
{
    class First
    {
        public:
            explicit First(std::shared_ptr<data::Repository> repo);
            ~First() = default;

            int getResult();

        private:
            std::unique_ptr<helpers::ListHelper> listHelper;
            std::unique_ptr<Input> input;
    };
}