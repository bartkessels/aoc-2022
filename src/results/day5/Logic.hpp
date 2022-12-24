#pragma once

#include <memory>
#include <stack>
#include <string>
#include <sstream>
#include <list>

#include "results/day5/models/Instruction.hpp"

namespace AOC2022::results::day5
{
    class Logic
    {
        public:
            ~Logic() = default;

            void setupTestStacks();
            void setupRegularStacks();
            void executeInstructions(std::list<std::shared_ptr<Instruction>> instructions);
            void executeInstruction(std::shared_ptr<Instruction> instruction);
            std::string getTopFromStacks();

        private:
            void setupStacks(int noStacks);
            void insertInStack(int stackNumber, std::string Logic);
            std::string getItemsFromStack(int stackNum, int noItems);
            std::shared_ptr<std::stack<char>> getStack(int stackNumber);

            std::list<std::shared_ptr<std::stack<char>>> stacks;
    };
}