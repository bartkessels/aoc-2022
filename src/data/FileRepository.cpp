#include "data/FileRepository.hpp"
#include <iostream>
using namespace AOC2022::data;

std::string FileRepository::getData(int day)
{
    // TODO: FIX THIS!
    std::string fileName = "res/day" + std::to_string(day) + ".txt"; //std::format("res/day{0}.txt", day);
    std::ifstream file(fileName);
    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();;
}