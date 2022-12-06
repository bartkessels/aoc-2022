#pragma once

#include <memory>
#include <string>

#include "results/day3/DataCleaner.hpp"
#include "results/day3/PriorityMapper.hpp"
#include "service/HttpService.hpp"

namespace AOC2022::results::day3
{
    class Second
    {
        public:
            explicit Second(std::shared_ptr<service::HttpService> httpService);\
            ~Second() = default;

            int getResult();

        private:
            std::shared_ptr<DataCleaner> dataCleaner;
            std::shared_ptr<PriorityMapper> priorityMapper;

            char getSameItemForRuckSacks(std::string ruckSackOne, std::string ruckSackTwo, std::string ruckSackThree);
            int getPointsForRuckSacks(std::string ruckSackOne, std::string ruckSackTwo, std::string ruckSackThree);
    };
}