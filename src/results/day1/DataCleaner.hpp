#pragma once

#include <memory>
#include <string>
#include <list>

#include "service/HttpService.hpp"

namespace AOC2022::results::day1
{
    class DataCleaner
    {
        public:
            explicit DataCleaner(std::shared_ptr<service::HttpService> httpService);
            ~DataCleaner() = default;

            std::list<std::string> getBlocks();

        private:
            std::shared_ptr<service::HttpService> httpService;
    };
}