#include "results/day2/DataCleaner.hpp"

using namespace AOC2022::results::day2;

DataCleaner::DataCleaner(std::shared_ptr<AOC2022::service::HttpService> httpService):
    httpService(httpService)
{

}

std::list<std::pair<char, char>> DataCleaner::getData()
{
    const auto& data = httpService->getRawRequest(uri);
    return convertData(data);
}

std::list<std::pair<char, char>> DataCleaner::convertData(std::string data)
{
    const std::string delimiter = "\n";
    std::list<std::pair<char, char>> result;

    size_t pos = 0;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        char a = data[0];   // Oponent move
        // data[1]          // SPACE
        char b = data[2];   // Own move

        result.push_back({a, b});
        data.erase(0, pos + delimiter.length());
    }

    return result;
}