#include "results/day5/Input.hpp"

using namespace AOC2022::results::day5;

Input::Input(std::shared_ptr<AOC2022::data::Repository> repo):
    repo(repo)
{

}

std::list<std::shared_ptr<Instruction>> Input::getInstructions()
{
    const auto& data = repo->getData(5);
    return convertData(data);
}

std::list<std::shared_ptr<Instruction>> Input::convertData(std::string data)
{
    const std::string delimiter = "\n";
    std::list<std::shared_ptr<Instruction>> result;

    size_t pos = 0;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        const auto& instruction = convertInstruction(data.substr(0, pos));

        result.push_back(instruction);
        data.erase(0, pos + delimiter.length());
    }

    if (!data.empty()) {
        auto instruction = convertInstruction(data.substr(0, data.length()));

        result.push_back(instruction);
        data.erase(0, data.length());
    }

    return result;
}

std::shared_ptr<Instruction> Input::convertInstruction(std::string data)
{
    const std::string delimiter = " ";
    const std::string move = "move ";
    const std::string from = "from ";
    const std::string to = "to ";

    data.erase(0, move.size());
    auto instruction = std::make_shared<Instruction>();

    size_t pos = 0;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        if (instruction->noToMove <= 0) {
            instruction->noToMove = std::stoi(data.substr(0, pos));
            data.erase(0, from.size());
        } else if (instruction->beginStackNumber <= 0) {
            instruction->beginStackNumber = std::stoi(data.substr(0, pos));
            data.erase(0, to.size());
        }

        data.erase(0, pos + delimiter.length());
    }

    if (!data.empty()) {
        instruction->endStackNumber = std::stoi(data);
    }

    return instruction;
}