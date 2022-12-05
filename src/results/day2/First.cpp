#include "results/day2/First.hpp"

using namespace AOC2022::results::day2;

First::First(std::shared_ptr<service::HttpService> httpService)
{
    outcomeMapper = std::make_shared<RoundOutcomeMapper>();
    strategyMapper = std::make_shared<StrategyMapper>();
    game = std::make_shared<Game>();
    dataCleaner = std::make_shared<DataCleaner>(httpService);
}

int First::getResult()
{
    const auto& strategyGuide = dataCleaner->getData();
    int totalScore = 0;

    for (const auto& round : strategyGuide) {
        totalScore += getRoundResult(round.first, round.second);
    }

    return totalScore;
}

int First::getRoundResult(char oponent, char own)
{
    const auto& oponentStrategy = strategyMapper->mapStrategy(oponent);
    const auto& ownStrategy = strategyMapper->mapStrategy(own);
    const auto& roundOutcome = game->playRound(oponentStrategy, ownStrategy);

    int outcomeScore = outcomeMapper->mapToPoints(roundOutcome);
    int strategyScore = strategyMapper->mapToPoints(ownStrategy);

    return outcomeScore + strategyScore;
}