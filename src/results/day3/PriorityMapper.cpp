#include "results/day3/PriorityMapper.hpp"

using namespace AOC2022::results::day3;

int PriorityMapper::map(char item)
{
    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return alphabet.find(item) + 1;
}