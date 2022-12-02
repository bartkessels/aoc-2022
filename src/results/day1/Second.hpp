#pragma once

#include <string>
#include <list>

#include "results/Result.hpp"

namespace AOC2022::results::day1
{
    class Second: public results::Result
    {
        public:
            explicit Second(std::shared_ptr<service::HttpService> httpService);
            ~Second() = default;

            int getResult() override;
        
            static inline const std::string uri = "https://adventofcode.com/2022/day/1/input";

        private:
            std::list<std::string> getBlocks();
            std::list<int> blockToList(std::string block);
            int countAllNumbersFromList(std::list<int> list);
            std::list<int> sortList(std::list<int> list);
    };
}