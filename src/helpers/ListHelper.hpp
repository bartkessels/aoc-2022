#pragma once

#include <string>
#include <list>

namespace AOC2022::helpers
{
    class ListHelper
    {
        public:
            ~ListHelper() = default;

            int countAllNumbersFromList(std::list<int> list);
            std::list<int> stringLinesToList(std::string block);
    };
}