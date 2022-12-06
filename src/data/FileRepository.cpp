#include "data/FileRepository.hpp"

using namespace AOC2022::data;

std::string FileRepository::getData(int day)
{
    // TODO: FIX THIS!
    std::string fileName = "res/day" + std::to_string(day) + ".txt"; //std::format("res/day{0}.txt", day);
    std::ifstream stream(fileName);
    std::string contents;
    
    if (stream.is_open()) {
        stream >> contents;
        stream.close();
    }
    
    return contents;
}