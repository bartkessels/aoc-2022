#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include <memory>

#include <iostream>

#include "data/Repository.hpp"
#include "results/day4/First.hpp"

using namespace AOC2022::data;
using namespace AOC2022::results::day4;

class RepositoryMock: public AOC2022::data::Repository
{
    public:
        MAKE_MOCK1(getData, std::string(int), override);
};

TEST_CASE("First result day 4")
{
    const auto& repository = std::make_shared<RepositoryMock>();
    const auto& input = "2-4,6-8\n2-3,4-5\n5-7,7-9\n2-8,3-7\n6-6,4-6\n2-6,4-8";

    ALLOW_CALL(*repository, getData(trompeloeil::_)).RETURN(input);

    const auto& sut = std::make_unique<First>(repository);

    SECTION("Validate test case")
    {
        // Arrange

        // Act
        int result = sut->getResult();

        // Assert
        REQUIRE(result == 2);
    }
}