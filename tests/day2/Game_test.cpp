#include <catch2/catch.hpp>
#include <memory>

#include "results/day2/Game.hpp"

using namespace AOC2022::results::day2;

TEST_CASE("Play round with desired outcome")
{
    const auto& sut = std::make_shared<Game>();

    SECTION("Strategies that end in draw")
    {
        // Arrange

        // Act
        const auto& rocks = sut->playRound(Strategy::Rock, Strategy::Rock);
        const auto& papers = sut->playRound(Strategy::Paper, Strategy::Paper);
        const auto& scissors = sut->playRound(Strategy::Scissors, Strategy::Scissors);

        // Assert
        REQUIRE(rocks == RoundOutcome::Draw);
        REQUIRE(papers == RoundOutcome::Draw);
        REQUIRE(scissors == RoundOutcome::Draw);
    }

    SECTION("Strategies that end in lost")
    {
        // Arrange

        // Act
        const auto& rock = sut->playRound(Strategy::Rock, Strategy::Scissors);
        const auto& paper = sut->playRound(Strategy::Paper, Strategy::Rock);
        const auto& scissor = sut->playRound(Strategy::Scissors, Strategy::Paper);

        // Assert
        REQUIRE(rock == RoundOutcome::Lost);
        REQUIRE(paper == RoundOutcome::Lost);
        REQUIRE(scissor == RoundOutcome::Lost);
    }

    SECTION("Strategies that end in wins")
    {
        // Arrange

        // Act
        const auto& rock = sut->playRound(Strategy::Rock, Strategy::Paper);
        const auto& paper = sut->playRound(Strategy::Paper, Strategy::Scissors);
        const auto& scissor = sut->playRound(Strategy::Scissors, Strategy::Rock);

        // Assert
        REQUIRE(rock == RoundOutcome::Won);
        REQUIRE(paper == RoundOutcome::Won);
        REQUIRE(scissor == RoundOutcome::Won);
    }
}