#include <memory>
#include <iostream>

#include "service/CprHttpService.hpp"

#include "results/day1/First.hpp"
#include "results/day1/Second.hpp"

using namespace AOC2022;
using namespace AOC2022::service;
using namespace AOC2022::results;

int main(int argc, char** args)
{
    const auto& httpService = std::make_shared<service::CprHttpService>();

    // Day 1
    std::cout << "###### DAY ! ######" << std::endl; 
    const auto& day1First = std::make_shared<day1::First>(httpService);
    std::cout << day1First->getResult() << std::endl;
    const auto& day1Second = std::make_shared<day1::Second>(httpService);
    std::cout << day1Second->getResult() << std::endl;

    return 0;
}