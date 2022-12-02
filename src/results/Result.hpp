#pragma once

#include <memory>
#include <string>

#include "service/HttpService.hpp"

namespace AOC2022::results
{
    // template <typename T>
    class Result
    {
        public:
            explicit Result(std::shared_ptr<service::HttpService> httpService, std::string uri);
            virtual ~Result() = default;

            virtual int getResult() = 0;

        protected:
            std::string getData();

        private:
            std::string uri;
            std::shared_ptr<service::HttpService> httpService;
    };
}