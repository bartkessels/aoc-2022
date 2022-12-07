#pragma once

#include <list>
#include <memory>
#include <string>

#include "data/Repository.hpp"
#include "results/day4/models/Assignment.hpp"
#include "results/day4/models/Range.hpp"

namespace AOC2022::results::day4
{
    class Input
    {
        public:
            explicit Input(std::shared_ptr<data::Repository> repo);
            ~Input() = default;

            std::list<std::shared_ptr<Assignment>> getAssignments();

        private:
            std::shared_ptr<data::Repository> repo;
            std::list<std::shared_ptr<Assignment>> convertData(std::string data);
            std::shared_ptr<Range> getRange(std::string data);
    };
}