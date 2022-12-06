#pragma once

#include <string>
#include <cctype>

namespace AOC2022::results::day3
{
    class PriorityMapper
    {
        public:
            ~PriorityMapper() = default;

            int map(char item);
    };
}