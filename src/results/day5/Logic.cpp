#include "results/day5/Logic.hpp"

using namespace AOC2022::results::day5;

void Logic::setupTestStacks()
{
    /*
            [D]    
        [N] [C]    
        [Z] [M] [P]
        1   2   3 
    */

    const auto& stack1Logic = "ZN";
    const auto& stack2Logic = "MCD";
    const auto& stack3Logic = "P";

    insertInStack(1, stack1Logic);
    insertInStack(2, stack2Logic);
    insertInStack(3, stack3Logic);
}

void Logic::setupRegularStacks()
{
    /*
            [G] [R]                 [P]    
            [H] [W]     [T] [P]     [H]    
            [F] [T] [P] [B] [D]     [N]    
        [L] [T] [M] [Q] [L] [C]     [Z]    
        [C] [C] [N] [V] [S] [H]     [V] [G]
        [G] [L] [F] [D] [M] [V] [T] [J] [H]
        [M] [D] [J] [F] [F] [N] [C] [S] [F]
        [Q] [R] [V] [J] [N] [R] [H] [G] [Z]
        1   2   3   4   5   6   7   8   9 
    */

    const auto& stack1Logic = "QMGCL";
    const auto& stack2Logic = "RDLCTFHG";
    const auto& stack3Logic = "VJFNMTWR";
    const auto& stack4Logic = "JFDVQP";
    const auto& stack5Logic = "NFMSLBT";
    const auto& stack6Logic = "RNVHCDP";
    const auto& stack7Logic = "HCT";
    const auto& stack8Logic = "GSJVZNHP";
    const auto& stack9Logic = "ZFHG";

    insertInStack(1, stack1Logic);
    insertInStack(2, stack2Logic);
    insertInStack(3, stack3Logic);
    insertInStack(4, stack4Logic);
    insertInStack(5, stack5Logic);
    insertInStack(6, stack6Logic);
    insertInStack(7, stack7Logic);
    insertInStack(8, stack8Logic);
    insertInStack(9, stack9Logic);
}

void Logic::executeInstructions(std::list<std::shared_ptr<Instruction>> instructions)
{
    for (const auto& instruction : instructions) {
        executeInstruction(instruction);
    }
}

void Logic::executeInstructionsInOrder(std::list<std::shared_ptr<Instruction>> instructions)
{
    for (const auto& instruction : instructions) {
        executeInstructionInOrder(instruction);
    }
}

void Logic::executeInstruction(std::shared_ptr<Instruction> instruction)
{
    const auto& itemsToMove = getItemsFromStack(instruction->beginStackNumber, instruction->noToMove);
    insertInStack(instruction->endStackNumber, itemsToMove);
}

void Logic::executeInstructionInOrder(std::shared_ptr<Instruction> instruction)
{
    const auto& itemsToMove = getItemsFromStackInSameOrder(instruction->beginStackNumber, instruction->noToMove);
    insertInStack(instruction->endStackNumber, itemsToMove);
}

std::string Logic::getTopFromStacks()
{
    std::string items;

    for (int i = 1; i <= stacks.size(); i++) {
        auto stack = getStack(i);
        items.push_back(stack->top());
    }
    
    return items;
}

void Logic::insertInStack(int stackNumber, std::string logic)
{
    if (stacks.size() < stackNumber) {
        stacks.push_back(std::make_shared<std::stack<char>>());
    }

    const auto& stack = getStack(stackNumber);

    for (auto character : logic) {
        stack->push(character);
    }
}

std::string Logic::getItemsFromStack(int stackNum, int noItems)
{
    const auto& stack = getStack(stackNum);
    std::string items;

    if (noItems > stack->size()) {
        throw "Cannot retrieve more items than the stack length";
    }

    for (int i = 0; i < noItems; i++) {
        items.push_back(stack->top());
        stack->pop();
    }

    return items;
}

std::string Logic::getItemsFromStackInSameOrder(int stackNum, int noItems)
{
    const auto& stack = getStack(stackNum);
    std::string items;

    if (noItems > stack->size()) {
        throw "Cannot retrieve more items than the stack length";
    }

    for (int i = 0; i < noItems; i++) {
        items.insert(items.begin(), stack->top());
        stack->pop();
    }

    return items;
}

std::shared_ptr<std::stack<char>> Logic::getStack(int stackNumber)
{
    int curStackNumber = 1;

    for (auto stack : stacks) {
        if (curStackNumber == stackNumber) {
            return stack;
        }

        curStackNumber++;
    }

    throw "Stack not found!";
}