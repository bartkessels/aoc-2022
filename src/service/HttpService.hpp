#pragma once

#include <string>

namespace AOC2022::service
{
    struct HttpService
    {
        public:
            ~HttpService() = default;

            virtual std::string getRawRequest(std::string uri) = 0;
    };
}