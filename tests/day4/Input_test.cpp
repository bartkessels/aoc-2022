#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include <memory>

#include <iostream>

#include "data/Repository.hpp"
#include "results/day4/Input.hpp"

using namespace AOC2022::data;
using namespace AOC2022::results::day4;

class RepositoryMock: public AOC2022::data::Repository
{
    public:
        MAKE_MOCK1(getData, std::string(int), override);
};

TEST_CASE("Input day 4")
{
    const auto& repository = std::make_shared<RepositoryMock>();
    const auto& input = "2-4,6-8\n2-3,4-5\n5-7,7-9\n2-8,3-7\n6-6,4-6\n2-6,4-8";

    ALLOW_CALL(*repository, getData(trompeloeil::_)).RETURN(input);

    const auto& sut = std::make_unique<Input>(repository);

    SECTION("Returns it in a list of 6 asignments")
    {
        // Arrange

        // Act
        const auto& result = sut->getAssignments();

        // Assert
        REQUIRE(result.size() == 6);
    }

    SECTION("First assignment has correct start and end information")
    {
        // Arrange

        // Act
        const auto& result = sut->getAssignments();

        // Assert
        const auto& firstAssignment = *result.begin();

        REQUIRE(firstAssignment->firstElf->start == 2);
        REQUIRE(firstAssignment->firstElf->end == 4);
        REQUIRE(firstAssignment->secondElf->start == 6);
        REQUIRE(firstAssignment->secondElf->end == 8);
    }

    // SECTION("Last assignment has correct start and end information")
    // {
    //     // Arrange

    //     // Act
    //     const auto& result = sut->getAssignments();

    //     // Assert
    //     const auto& lastAssignment = *result.end();

    //     REQUIRE(lastAssignment->firstElf->start == 2);
    //     REQUIRE(lastAssignment->firstElf->end == 6);
    //     REQUIRE(lastAssignment->secondElf->start == 4);
    //     REQUIRE(lastAssignment->secondElf->end == 8);
    // }
}