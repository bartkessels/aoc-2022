#include <catch2/catch.hpp>
#include <memory>

#include "results/day3/PriorityMapper.hpp"

using namespace AOC2022::results::day3;

TEST_CASE("Priority mapper day 3")
{
    const auto& sut = std::make_shared<PriorityMapper>();

    SECTION("Map characters to points")
    {
        // Arrange

        // Act
        const auto& resLowA = sut->map('a');
        const auto& resLowB = sut->map('b');
        const auto& resLowC = sut->map('c');
        const auto& resLowX = sut->map('x');
        const auto& resLowY = sut->map('y');
        const auto& resLowZ = sut->map('z');
        const auto& resUpA = sut->map('A');
        const auto& resUpB = sut->map('B');
        const auto& resUpC = sut->map('C');
        const auto& resUpX = sut->map('X');
        const auto& resUpY = sut->map('Y');
        const auto& resUpZ = sut->map('Z');

        // Assert
        REQUIRE(resLowA == 1);
        REQUIRE(resLowB == 2);
        REQUIRE(resLowC == 3);
        REQUIRE(resLowX == 24);
        REQUIRE(resLowY == 25);
        REQUIRE(resLowZ == 26);
        REQUIRE(resUpA == 27);
        REQUIRE(resUpB == 28);
        REQUIRE(resUpC == 29);
        REQUIRE(resUpX == 50);
        REQUIRE(resUpY == 51);
        REQUIRE(resUpZ == 52);
    }
}