#include "results/Result.hpp"

using namespace AOC2022::results;

Result::Result(std::shared_ptr<AOC2022::service::HttpService> httpService, std::string uri):
    httpService(httpService),
    uri(uri)
{

}

std::string Result::getData()
{
    return httpService->getRawRequest(uri);
}
