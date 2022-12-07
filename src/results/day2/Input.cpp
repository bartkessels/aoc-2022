#include "results/day2/Input.hpp"

using namespace AOC2022::results::day2;

Input::Input(std::shared_ptr<AOC2022::data::Repository> repo):
    repo(repo)
{

}

std::list<std::shared_ptr<Round>> Input::getRounds()
{
    std::string input = repo->getData(2);
    return convertData(input);
}

std::list<std::shared_ptr<Round>> Input::convertData(std::string data)
{
    const std::string delimiter = "\n";
    std::list<std::shared_ptr<Round>> result;

    size_t pos = 0;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        const auto& round = std::make_shared<Round>();

        // data[0] = oponent strategy
        // data[1] = space
        // data[2] = own strategy or expected outcome

        round->oponentStrategy = mapStrategy(data[0]);
        round->ownStrategy = mapStrategy(data[2]);
        round->expectedOutcome = mapExpectedOutcome(data[2]);

        result.push_back(round);
        data.erase(0, pos + delimiter.length());
    }

    return result;
}

Strategy Input::mapStrategy(char strategy)
{
    switch (strategy)
    {
        case 'A':
        case 'X':
            return Strategy::Rock;
        case 'B':
        case 'Y':
            return Strategy::Paper;
        case 'C':
        case 'Z':
            return Strategy::Scissors;
        default:
            throw "Unsupported strategy!";
    }
}

Outcome Input::mapExpectedOutcome(char expectedOutcome)
{
    switch(expectedOutcome)
    {
        case 'X':
            return Outcome::Lost;
        case 'Y':
            return Outcome::Draw;
        case 'Z':
            return Outcome::Won;
        default:
            throw "Unsupported outcome!";
    }
}