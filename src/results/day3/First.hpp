#pragma once

#include <memory>
#include <string>

#include "results/day3/DataCleaner.hpp"
#include "results/day3/PriorityMapper.hpp"
#include "service/HttpService.hpp"

namespace AOC2022::results::day3
{
    class First
    {
        public:
            explicit First(std::shared_ptr<service::HttpService> httpService);\
            ~First() = default;

            int getResult();

        private:
            std::shared_ptr<DataCleaner> dataCleaner;
            std::shared_ptr<PriorityMapper> priorityMapper;

            char getSameItemForCompartiments(std::string firstCompartiment, std::string secondCompartiment);
            int getPointsForRuckSack(std::pair<std::string, std::string> ruckSack);
    };
}