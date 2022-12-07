#pragma once

#include <memory>
#include <list>
#include <utility>

#include "data/Repository.hpp"
#include "results/day2/models/Round.hpp"
#include "results/day2/models/Strategy.hpp"
#include "results/day2/models/Outcome.hpp"

namespace AOC2022::results::day2
{
    class Input
    {
        public:
            explicit Input(std::shared_ptr<data::Repository> repo);
            ~Input() = default;

            std::list<std::shared_ptr<Round>> getRounds();

        private:
            std::shared_ptr<data::Repository> repo;
            std::list<std::shared_ptr<Round>> convertData(std::string data);
            Strategy mapStrategy(char strategy);
            Outcome mapExpectedOutcome(char outcome);
    };
}