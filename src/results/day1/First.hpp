#pragma once

#include <string>
#include <list>

#include "helpers/ListHelper.hpp"
#include "results/Result.hpp"

namespace AOC2022::results::day1
{
    class First: public results::Result
    {
        public:
            explicit First(std::shared_ptr<service::HttpService> httpService);
            ~First() = default;

            int getResult() override;
        
            static inline const std::string uri = "https://adventofcode.com/2022/day/1/input";

        private:
            std::list<std::string> getBlocks();
            std::shared_ptr<helpers::ListHelper> listHelper;
    };
}