#pragma once

#include <cpr/cpr.h>
#include <string>

#include "service/HttpService.hpp"

namespace AOC2022::service
{
    class CprHttpService : public HttpService
    {
        public:
            ~CprHttpService() = default;

            std::string getRawRequest(std::string uri) override;
    };
}