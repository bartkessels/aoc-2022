#include "service/HttpService.hpp"

using namespace AOC2022::service;

std::string HttpService::getRawRequest(std::string uri)
{
    cpr::Response response = cpr::Get(cpr::Url{ uri });
    return response.text;
}