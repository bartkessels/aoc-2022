#pragma once

#include <memory>
#include <string>

#include "data/Repository.hpp"
#include "results/day3/Input.hpp"
#include "results/day3/PriorityMapper.hpp"

namespace AOC2022::results::day3
{
    class First
    {
        public:
            explicit First(std::shared_ptr<data::Repository> repo);
            ~First() = default;

            int getResult();

        private:
            std::shared_ptr<Input> input;
            std::shared_ptr<PriorityMapper> priorityMapper;

            int getPointsForRuckSack(std::shared_ptr<RuckSack> ruckSack);
    };
}