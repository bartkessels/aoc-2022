#pragma once

#include <memory>

#include "results/day4/models/Range.hpp"

namespace AOC2022::results::day4
{
    class Logic
    {
        public:
            ~Logic() = default;

            bool rangesIncludedInEachOther(std::shared_ptr<Range> rangeA, std::shared_ptr<Range> rangeB);
            bool rangesThatOverlap(std::shared_ptr<Range> rangeA, std::shared_ptr<Range> rangeB);
    };
}