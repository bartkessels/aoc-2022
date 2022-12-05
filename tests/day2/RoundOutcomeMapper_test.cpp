#include <catch2/catch.hpp>
#include <memory>

#include "results/day2/RoundOutcomeMapper.hpp"

using namespace AOC2022::results::day2;

TEST_CASE("Round outcome mapper day 2")
{
    const auto& sut = std::make_shared<RoundOutcomeMapper>();

    SECTION("Map round result to points")
    {
        // Arrange

        // Act
        const auto& won = sut->mapToPoints(RoundOutcome::Won);
        const auto& draw = sut->mapToPoints(RoundOutcome::Draw);
        const auto& lost = sut->mapToPoints(RoundOutcome::Lost);

        // Assert
        REQUIRE(won == 6);
        REQUIRE(draw == 3);
        REQUIRE(lost == 0);
    }
}