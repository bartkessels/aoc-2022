#include "service/CprHttpService.hpp"

using namespace AOC2022::service;

CprHttpService::CprHttpService(std::string session):
    session(std::move(session))
{

}

std::string CprHttpService::getRawRequest(std::string uri)
{
    cpr::Response response = cpr::Get(cpr::Url{ uri }, cpr::Cookie{ "session", session });
    return response.text;
}