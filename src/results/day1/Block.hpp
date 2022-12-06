#pragma once

#include <list>
#include <string>

namespace AOC2022::results::day1
{
    struct Block
    {
        public:
            ~Block() = default;

            std::list<std::string> contents;
    };
}