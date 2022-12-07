#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include <memory>

#include "results/day2/First.hpp"

using namespace AOC2022::data;
using namespace AOC2022::results::day2;

class RepositoryMock: public Repository
{
    public:
        MAKE_MOCK1(getData, std::string(int), override);
};

TEST_CASE("First result day 2")
{
    const auto& repository = std::make_shared<RepositoryMock>();
    const auto& input = "A Y\nB X\nC Z\n";

    ALLOW_CALL(*repository, getData(trompeloeil::_)).RETURN(input);

    const auto& sut = std::make_unique<First>(repository);

    SECTION("Validate test case")
    {
        // Arrange

        // Act
        int result = sut->getResult();

        // Assert
        REQUIRE(result == 15);
    }
}