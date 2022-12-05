#include <catch2/catch.hpp>
#include <memory>

#include "results/day2/StrategyMapper.hpp"

using namespace AOC2022::results::day2;

TEST_CASE("Strategy mapper day 2")
{
    const auto& sut = std::make_shared<StrategyMapper>();

    SECTION("Map characters to strategy")
    {
        // Arrange

        // Act
        const auto& resA = sut->mapStrategy('A');
        const auto& resB = sut->mapStrategy('B');
        const auto& resC = sut->mapStrategy('C');
        const auto& resX = sut->mapStrategy('X');
        const auto& resY = sut->mapStrategy('Y');
        const auto& resZ = sut->mapStrategy('Z');

        // Assert
        REQUIRE(resA == Strategy::Rock);
        REQUIRE(resB == Strategy::Paper);
        REQUIRE(resC == Strategy::Scissors);
        REQUIRE(resX == Strategy::Rock);
        REQUIRE(resY == Strategy::Paper);
        REQUIRE(resZ == Strategy::Scissors);
    }

    SECTION("Map strategy to points")
    {
        // Arrange

        // Assert
        char rock = sut->mapToPoints(Strategy::Rock);
        char paper = sut->mapToPoints(Strategy::Paper);
        char scissors = sut->mapToPoints(Strategy::Scissors);

        // Assert
        REQUIRE(rock == 1);
        REQUIRE(paper == 2);
        REQUIRE(scissors == 3);
    }
}