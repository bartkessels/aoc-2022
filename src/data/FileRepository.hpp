#pragma once

#include <string>
#include <format>
#include <fstream>
#include <iostream>

#include "data/Repository.hpp"

namespace AOC2022::data
{
    class FileRepository: public Repository
    {
        public:
            ~FileRepository() = default;

            std::string getData(int day) override;
    };
}