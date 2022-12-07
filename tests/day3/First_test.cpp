#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include <memory>

#include "data/Repository.hpp"
#include "results/day3/First.hpp"

using namespace AOC2022::results::day3;

class RepositoryMock: public AOC2022::data::Repository
{
    public:
        MAKE_MOCK1(getData, std::string(int), override);
};

TEST_CASE("First result day 3")
{
    const auto& repository = std::make_shared<RepositoryMock>();
    const auto& input = "vJrwpWtwJgWrhcsFMMfFFhFp\njqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\nPmmdzqPrVvPwwTWBwg\nwMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\nttgJtRGJQctTZtZT\nCrZsJsPPZsGzwwsLwLmpwMDw\n";

    ALLOW_CALL(*repository, getData(trompeloeil::_)).RETURN(input);

    const auto& sut = std::make_unique<First>(repository);

    SECTION("Validate test case")
    {
        // Arrange

        // Act
        int result = sut->getResult();

        // Assert
        REQUIRE(result == 157);
    }
}