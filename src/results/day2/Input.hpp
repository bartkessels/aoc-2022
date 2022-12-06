#pragma once

#include <memory>
#include <list>
#include <utility>

#include "data/Repository.hpp"

namespace AOC2022::results::day2
{
    class Input
    {
        public:
            explicit DataCleaner(std::shared_ptr<data::Repository> repo);
            ~DataCleaner() = default;

            std::list<std::pair<char, char>> getData();

        private:
            std::shared_ptr<data::Repository> repo;
            std::list<std::pair<char, char>> convertData(std::string data);
    };
}