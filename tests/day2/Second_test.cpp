#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include <memory>

#include "results/day2/Second.hpp"

using namespace AOC2022::results::day2;

class HttpServiceMock: public AOC2022::service::HttpService
{
    public:
        MAKE_MOCK1(getRawRequest, std::string(std::string), override);
};

TEST_CASE("Second result day 2")
{
    const auto& httpService = std::make_shared<HttpServiceMock>();
    const auto& input = "A Y\nB X\nC Z\n";

    ALLOW_CALL(*httpService, getRawRequest(trompeloeil::_)).RETURN(input);

    const auto& sut = std::make_unique<Second>(httpService);

    SECTION("Validate test case")
    {
        // Arrange

        // Act
        int result = sut->getResult();

        // Assert
        REQUIRE(result == 12);
    }
}