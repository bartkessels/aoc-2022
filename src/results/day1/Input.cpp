#include "results/day1/Input.hpp"

using namespace AOC2022::results::day1;

Input::Input(std::shared_ptr<AOC2022::data::Repository> repo):
    repo(repo)
{

}

std::list<std::shared_ptr<Block>> Input::getBlocks()
{
    std::list<std::shared_ptr<Block>> blocks;

    std::string input = repo->getData(1);
    const auto& rawBlocks = splitBy(input, "\n\n");

    for (const auto& rawBlock : rawBlocks) {
        const auto& block = std::make_shared<Block>();
        block->contents = splitBy(rawBlock, "\n");

        blocks.push_back(block);
    }

    return blocks;
}

std::list<std::string> Input::splitBy(std::string input, std::string delimiter)
{
    std::list<std::string> result;

    size_t pos = 0;
    while ((pos = input.find(delimiter)) != std::string::npos) {
        std::string token = input.substr(0, pos);
        result.push_back(token);

        input.erase(0, pos + delimiter.length());
    }

    if (!input.empty()) {
        result.push_back(input);
    }

    return result;
}