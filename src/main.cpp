#include <memory>
#include <iostream>

#include "service/CprHttpService.hpp"

#include "results/day1/First.hpp"
#include "results/day1/Second.hpp"

#include "results/day2/First.hpp"
#include "results/day2/Second.hpp"

#include "results/day3/First.hpp"

using namespace AOC2022;
using namespace AOC2022::service;
using namespace AOC2022::results;

int main(int argc, char** args)
{
    std::string session = "53616c7465645f5fa325724bb6c8b65c5cadd980fe19924f52133d319e9c50c157396720b866af0f70993b0de1802437146f372fd79028e9277ebc27445600ef";
    const auto& httpService = std::make_shared<service::CprHttpService>(session);

    // Day 1
    std::cout << "###### DAY 1 ######" << std::endl; 
    const auto& day1First = std::make_shared<day1::First>(httpService);
    std::cout << day1First->getResult() << std::endl;
    const auto& day1Second = std::make_shared<day1::Second>(httpService);
    std::cout << day1Second->getResult() << std::endl;

    // Day 2
    std::cout << "###### DAY 2 ######" << std::endl; 
    const auto& day2First = std::make_shared<day2::First>(httpService);
    std::cout << day2First->getResult() << std::endl;
    const auto& day2Second = std::make_shared<day2::Second>(httpService);
    std::cout << day2Second->getResult() << std::endl;

    // Day 3
    std::cout << "###### DAY 3 ######" << std::endl; 
    const auto& day3First = std::make_shared<day3::First>(httpService);
    std::cout << day3First->getResult() << std::endl;

    return 0;
}