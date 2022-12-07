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
        REQUIRE(rocks == Outcome::Draw);
        REQUIRE(papers == Outcome::Draw);
        REQUIRE(scissors == Outcome::Draw);
    }

    SECTION("Strategies that end in lost")
    {
        // Arrange

        // Act
        const auto& rock = sut->playRound(Strategy::Rock, Strategy::Scissors);
        const auto& paper = sut->playRound(Strategy::Paper, Strategy::Rock);
        const auto& scissor = sut->playRound(Strategy::Scissors, Strategy::Paper);

        // Assert
        REQUIRE(rock == Outcome::Lost);
        REQUIRE(paper == Outcome::Lost);
        REQUIRE(scissor == Outcome::Lost);
    }

    SECTION("Strategies that end in wins")
    {
        // Arrange

        // Act
        const auto& rock = sut->playRound(Strategy::Rock, Strategy::Paper);
        const auto& paper = sut->playRound(Strategy::Paper, Strategy::Scissors);
        const auto& scissor = sut->playRound(Strategy::Scissors, Strategy::Rock);

        // Assert
        REQUIRE(rock == Outcome::Won);
        REQUIRE(paper == Outcome::Won);
        REQUIRE(scissor == Outcome::Won);
    }

    SECTION("Map round result to points")
    {
        // Arrange

        // Act
        const auto& wonRock = sut->getPoints(Strategy::Rock, Outcome::Won);
        const auto& wonPaper = sut->getPoints(Strategy::Paper, Outcome::Won);
        const auto& wonScissors = sut->getPoints(Strategy::Scissors, Outcome::Won);
        const auto& drawRock = sut->getPoints(Strategy::Rock, Outcome::Draw);
        const auto& drawPaper = sut->getPoints(Strategy::Paper, Outcome::Draw);
        const auto& drawScissors = sut->getPoints(Strategy::Scissors, Outcome::Draw);
        const auto& lostRock = sut->getPoints(Strategy::Rock, Outcome::Lost);
        const auto& lostPaper = sut->getPoints(Strategy::Paper, Outcome::Lost);
        const auto& lostScissors = sut->getPoints(Strategy::Scissors, Outcome::Lost);

        // Assert
        REQUIRE(wonRock == 7);
        REQUIRE(wonPaper == 8);
        REQUIRE(wonScissors == 9);
        REQUIRE(drawRock == 4);
        REQUIRE(drawPaper == 5);
        REQUIRE(drawScissors == 6);
        REQUIRE(lostRock == 1);
        REQUIRE(lostPaper == 2);
        REQUIRE(lostScissors == 3);
    }
}