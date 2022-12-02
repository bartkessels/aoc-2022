#include "service/CprHttpService.hpp"

using namespace AOC2022::service;

std::string CprHttpService::getRawRequest(std::string uri)
{
    cpr::Response response = cpr::Get(cpr::Url{ uri }, cpr::Cookie{ "session", "53616c7465645f5ff298ddc033d6b4b457d8f263b171594549b55e5cff3b0b9879ab66161a65565d773f15d0a4b7b3fad5d56e0856239e7a30b341d20361b906" });
    return response.text;
}