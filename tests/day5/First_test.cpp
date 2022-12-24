#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include <memory>

#include <iostream>

#include "data/Repository.hpp"
#include "results/day5/Input.hpp"
#include "results/day5/First.hpp"

using namespace AOC2022::data;
using namespace AOC2022::results::day5;

class RepositoryMock: public AOC2022::data::Repository
{
    public:
        MAKE_MOCK1(getData, std::string(int), override);
};

TEST_CASE("First result day 5")
{
    const auto& repository = std::make_shared<RepositoryMock>();
    const auto& input = "move 1 from 2 to 1\nmove 3 from 1 to 3\nmove 2 from 2 to 1\nmove 1 from 1 to 2";

    ALLOW_CALL(*repository, getData(trompeloeil::_)).RETURN(input);

    const auto& sut = std::make_unique<First>(repository);

    SECTION("Validate test case")
    {
        // Arrange
        sut->setupData(true);

        // Act
        const auto& result = sut->getResult();

        // Assert
        REQUIRE(result == "CMZ");
    }
}