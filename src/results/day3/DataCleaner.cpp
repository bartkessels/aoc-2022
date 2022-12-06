#include "results/day3/DataCleaner.hpp"

using namespace AOC2022::results::day3;

DataCleaner::DataCleaner(std::shared_ptr<AOC2022::service::HttpService> httpService):
    httpService(httpService)
{

}

std::list<std::pair<std::string, std::string>> DataCleaner::getData()
{
    const auto& data = httpService->getRawRequest(uri);
    return convertData(data);
}

std::list<std::string> DataCleaner::getDataAsRuckSacks()
{
    const auto& data = httpService->getRawRequest(uri);
    return convertDataAsRuckSacks(data);
}

std::list<std::pair<std::string, std::string>> DataCleaner::convertData(std::string data)
{
    const std::string delimiter = "\n";
    std::list<std::pair<std::string, std::string>> result;

    size_t pos = 0;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        size_t halfPos = pos / 2;

        std::string firstCompartiment = data.substr(0, halfPos);
        std::string secondCompartiment = data.substr(halfPos, halfPos);

        result.push_back({firstCompartiment, secondCompartiment});
        data.erase(0, pos + delimiter.length());
    }

    return result;
}

std::list<std::string> DataCleaner::convertDataAsRuckSacks(std::string data)
{
    const std::string delimiter = "\n";
    std::list<std::string> result;

    size_t pos = 0;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        result.push_back(data.substr(0, pos));
        data.erase(0, pos + delimiter.length());
    }

    return result;
}