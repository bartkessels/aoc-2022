#pragma once

#include <string>

namespace AOC2022::data
{
    struct Repository
    {
        public:
            ~Repository() = default;

            virtual std::string getData(int day) = 0;
    };
}