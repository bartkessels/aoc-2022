#include "results/day2/Second.hpp"

using namespace AOC2022::results::day2;

Second::Second(std::shared_ptr<service::HttpService> httpService)
{
    outcomeMapper = std::make_shared<RoundOutcomeMapper>();
    strategyMapper = std::make_shared<StrategyMapper>();
    game = std::make_shared<Game>();
    dataCleaner = std::make_shared<DataCleaner>(httpService);
}

int Second::getResult()
{
    const auto& strategyGuide = dataCleaner->getData();
    int totalScore = 0;

    for (const auto& round : strategyGuide) {
        const auto& oponentStrategy = strategyMapper->mapStrategy(round.first);
        const auto& expectedOutcome = outcomeMapper->mapDecision(round.second);
        const auto& ownStrategy = getOwnStrategy(oponentStrategy, expectedOutcome);

        totalScore += getRoundResult(oponentStrategy, ownStrategy);
    }

    return totalScore;
}

int Second::getRoundResult(Strategy oponentStrategy, Strategy ownStrategy)
{
    const auto& roundOutcome = game->playRound(oponentStrategy, ownStrategy);

    int outcomeScore = outcomeMapper->mapToPoints(roundOutcome);
    int strategyScore = strategyMapper->mapToPoints(ownStrategy);

    return outcomeScore + strategyScore;
}

Strategy Second::getOwnStrategy(Strategy oponentStrategy, RoundOutcome expectedOutcome)
{
    if (expectedOutcome == RoundOutcome::Draw)
        return oponentStrategy;

    if (expectedOutcome == RoundOutcome::Won)
    {
        if (oponentStrategy == Strategy::Rock)
            return Strategy::Paper;
        if (oponentStrategy == Strategy::Paper)
            return Strategy::Scissors;
        if (oponentStrategy == Strategy::Scissors)
            return Strategy::Rock;
    }

    if (oponentStrategy == Strategy::Rock)
        return Strategy::Scissors;
    if (oponentStrategy == Strategy::Paper)
        return Strategy::Rock;
    if (oponentStrategy == Strategy::Scissors)
        return Strategy::Paper;

    throw "No valid strategy!";
}