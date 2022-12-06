#pragma once

#include <memory>
#include <list>
#include <utility>

#include "service/HttpService.hpp"

namespace AOC2022::results::day3
{
    class DataCleaner
    {
        public:
            explicit DataCleaner(std::shared_ptr<service::HttpService> httpService);
            ~DataCleaner() = default;

            std::list<std::pair<std::string, std::string>> getData();

        private:
            std::shared_ptr<service::HttpService> httpService;
            std::list<std::pair<std::string, std::string>> convertData(std::string data);
            const std::string uri = "https://adventofcode.com/2022/day/3/input";
    };
}