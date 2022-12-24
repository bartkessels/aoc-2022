#pragma once

namespace AOC2022::results::day5
{
    struct Instruction
    {
        public:
            ~Instruction() = default;

            int noToMove = -1;
            int beginStackNumber = -1;
            int endStackNumber = -1;
    };
}