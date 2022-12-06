#pragma once

#include <string>
#include <memory>
#include <list>
#include <utility>

#include "results/day2/Constants.hpp"
#include "results/day2/DataCleaner.hpp"
#include "results/day2/Game.hpp"
#include "results/day2/RoundOutcomeMapper.hpp"
#include "results/day2/StrategyMapper.hpp"

namespace AOC2022::results::day2
{
    class Second
    {
        public:
            explicit Second(std::shared_ptr<service::HttpService> httpService);
            ~Second() = default;

            int getResult();
        
        private:
            std::shared_ptr<DataCleaner> dataCleaner;


            std::shared_ptr<RoundOutcomeMapper> outcomeMapper;
            std::shared_ptr<StrategyMapper> strategyMapper;
            std::shared_ptr<Game> game;

            int getRoundResult(Strategy oponentStrategy, Strategy ownStrategy);
            Strategy getOwnStrategy(Strategy oponentStrategy, RoundOutcome expectedOutcome);
    };
}