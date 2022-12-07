#pragma once

#include <memory>
#include <string>

#include "data/Repository.hpp"
#include "results/day3/Input.hpp"
#include "results/day3/PriorityMapper.hpp"

namespace AOC2022::results::day3
{
    class Second
    {
        public:
            explicit Second(std::shared_ptr<data::Repository> repo);
            ~Second() = default;

            int getResult();

        private:
            std::shared_ptr<Input> input;
            std::shared_ptr<PriorityMapper> priorityMapper;

            int getPointsForRuckSacks(std::shared_ptr<RuckSack> ruckSackOne, std::shared_ptr<RuckSack> ruckSackTwo, std::shared_ptr<RuckSack> ruckSackThree);
    };
}