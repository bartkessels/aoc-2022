#pragma once

#include <string>

namespace AOC2022::results::day3
{
    struct RuckSack
    {
        public:
            ~RuckSack() = default;

            std::string compartimentOne;
            std::string compartimentTwo;

            std::string getContents() {
                return compartimentOne.append(compartimentTwo);
            }
    };
}