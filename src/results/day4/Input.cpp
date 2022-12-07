#include "results/day4/Input.hpp"

using namespace AOC2022::results::day4;

Input::Input(std::shared_ptr<AOC2022::data::Repository> repo):
    repo(repo)
{

}

std::list<std::shared_ptr<Assignment>> Input::getAssignments()
{
    const auto& data = repo->getData(4);
    return convertData(data);
}

std::list<std::shared_ptr<Assignment>> Input::convertData(std::string data)
{
    const std::string delimiter = "\n";
    std::list<std::shared_ptr<Assignment>> result;

    size_t pos = 0;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        const auto& assignment = std::make_shared<Assignment>();
        assignment->firstElf = getRange(data.substr(0, data.find(",")));
        assignment->secondElf = getRange(data.substr(data.find(",") + 1, pos));

        result.push_back(assignment);
        data.erase(0, pos + delimiter.length());
    }

    if (!data.empty()) {
        const auto& assignment = std::make_shared<Assignment>();
        assignment->firstElf = getRange(data.substr(0, data.find(",")));
        assignment->secondElf = getRange(data.substr(data.find(",") + 1, data.size()));

        result.push_back(assignment);
        data.erase(0, pos + data.size());
    }

    return result;
}

std::shared_ptr<Range> Input::getRange(std::string data)
{
    const auto& range = std::make_shared<Range>();

    // data[0] => range start
    // data[1] => -
    // data[2] => range end
    range->start = std::stoi(data.substr(0, data.find("-")));
    range->end = std::stoi(data.substr(data.find("-") + 1, data.length()));

    return range;
}