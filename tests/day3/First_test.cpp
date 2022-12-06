#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include <memory>

#include "results/day3/First.hpp"

using namespace AOC2022::results::day3;

class HttpServiceMock: public AOC2022::service::HttpService
{
    public:
        MAKE_MOCK1(getRawRequest, std::string(std::string), override);
};

TEST_CASE("First result day 3")
{
    const auto& httpService = std::make_shared<HttpServiceMock>();
    const auto& input = "vJrwpWtwJgWrhcsFMMfFFhFp\njqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\nPmmdzqPrVvPwwTWBwg\nwMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\nttgJtRGJQctTZtZT\nCrZsJsPPZsGzwwsLwLmpwMDw\n";

    ALLOW_CALL(*httpService, getRawRequest(trompeloeil::_)).RETURN(input);

    const auto& sut = std::make_unique<First>(httpService);

    SECTION("Validate test case")
    {
        // Arrange

        // Act
        int result = sut->getResult();

        // Assert
        REQUIRE(result == 157);
    }
}