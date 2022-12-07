#pragma once

#include <memory>
#include <list>

#include "results/day4/models/Range.hpp"

namespace AOC2022::results::day4
{
    struct Assignment
    {
        public:
            ~Assignment() = default;

            std::shared_ptr<Range> firstElf;
            std::shared_ptr<Range> secondElf;
    };
}