#pragma once

#include <memory>
#include <list>
#include <utility>

#include "data/Repository.hpp"
#include "results/day3/models/RuckSack.hpp"

namespace AOC2022::results::day3
{
    class Input
    {
        public:
            explicit Input(std::shared_ptr<data::Repository> repo);
            ~Input() = default;

            std::list<std::shared_ptr<RuckSack>> getRuckSacks();

        private:
            std::shared_ptr<data::Repository> repo;
            std::list<std::shared_ptr<RuckSack>> convertData(std::string data);
    };
}