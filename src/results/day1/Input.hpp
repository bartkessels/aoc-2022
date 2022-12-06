#pragma once

#include <list>
#include <string>
#include <memory>

#include "data/Repository.hpp"
#include "results/day1/Block.hpp"

namespace AOC2022::results::day1
{
    class Input
    {
        public:
            explicit Input(std::shared_ptr<data::Repository> repo);
            ~Input() = default;

            std::list<std::shared_ptr<Block>> getBlocks();
            std::list<std::string> splitBy(std::string input, std::string delimiter);

        private:
            std::shared_ptr<data::Repository> repo;
    };
}