#include <memory>
#include <iostream>

#include "data/FileRepository.hpp"

#include "results/day1/First.hpp"
#include "results/day1/Second.hpp"

#include "results/day2/First.hpp"
#include "results/day2/Second.hpp"

#include "results/day3/First.hpp"
#include "results/day3/Second.hpp"

#include "results/day4/First.hpp"
#include "results/day4/Second.hpp"

#include "results/day5/First.hpp"
#include "results/day5/Second.hpp"

using namespace AOC2022;
using namespace AOC2022::results;

int main(int argc, char** args)
{
    const auto& repository = std::make_shared<data::FileRepository>();

    // Day 1
    std::cout << "###### DAY 1 ######" << std::endl; 
    const auto& day1First = std::make_shared<day1::First>(repository);
    std::cout << day1First->getResult() << std::endl;
    const auto& day1Second = std::make_shared<day1::Second>(repository);
    std::cout << day1Second->getResult() << std::endl;

    // Day 2
    std::cout << "###### DAY 2 ######" << std::endl; 
    const auto& day2First = std::make_shared<day2::First>(repository);
    std::cout << day2First->getResult() << std::endl;
    const auto& day2Second = std::make_shared<day2::Second>(repository);
    std::cout << day2Second->getResult() << std::endl;

    // Day 3
    std::cout << "###### DAY 3 ######" << std::endl; 
    const auto& day3First = std::make_shared<day3::First>(repository);
    std::cout << day3First->getResult() << std::endl;
    const auto& day3Second = std::make_shared<day3::Second>(repository);
    std::cout << day3Second->getResult() << std::endl;

    // Day 4
    std::cout << "###### DAY 4 ######" << std::endl; 
    const auto& day4First = std::make_shared<day4::First>(repository);
    std::cout << day4First->getResult() << std::endl;
    const auto& day4Second = std::make_shared<day4::Second>(repository);
    std::cout << day4Second->getResult() << std::endl;

    // Day 5
    std::cout << "###### DAY 5 ######" << std::endl; 
    const auto& day5First = std::make_shared<day5::First>(repository);
    day5First->setupData();
    std::cout << day5First->getResult() << std::endl;
    const auto& day5Second = std::make_shared<day5::Second>(repository);
    day5Second->setupData();
    std::cout << day5Second->getResult() << std::endl;

    return 0;
}