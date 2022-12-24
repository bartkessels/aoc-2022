#pragma once

#include <memory>
#include <list>
#include <string>

#include "data/Repository.hpp"
#include "results/day5/models/Instruction.hpp"

namespace AOC2022::results::day5
{
    class Input
    {
        public:
            explicit Input(std::shared_ptr<data::Repository> repo);
            ~Input() = default;

            std::list<std::shared_ptr<Instruction>> getInstructions();

        private:
            std::shared_ptr<data::Repository> repo;

            std::list<std::shared_ptr<Instruction>> convertData(std::string data);
            std::shared_ptr<Instruction> convertInstruction(std::string data);
    };
}