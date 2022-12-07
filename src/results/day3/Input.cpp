#include "results/day3/Input.hpp"

using namespace AOC2022::results::day3;

Input::Input(std::shared_ptr<AOC2022::data::Repository> repo):
    repo(repo)
{

}

std::list<std::shared_ptr<RuckSack>> Input::getRuckSacks()
{
    std::string input = repo->getData(3);
    return convertData(input);
}

std::list<std::shared_ptr<RuckSack>> Input::convertData(std::string data)
{
    const std::string delimiter = "\n";
    std::list<std::shared_ptr<RuckSack>> result;

    size_t pos = 0;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        size_t halfPos = pos / 2;
        const auto& ruckSack = std::make_shared<RuckSack>();

        ruckSack->compartimentOne = data.substr(0, halfPos);
        ruckSack->compartimentTwo = data.substr(halfPos, halfPos);

        result.push_back(ruckSack);
        data.erase(0, pos + delimiter.length());
    }

    return result;
}