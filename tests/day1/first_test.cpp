#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include <memory>

#include "results/day1/First.hpp"

using namespace AOC2022::results::day1;

class HttpServiceMock: public AOC2022::service::HttpService
{
    public:
        MAKE_MOCK1(getRawRequest, std::string(std::string), override);
};

TEST_CASE("First result day 1")
{
    const auto& httpService = std::make_shared<HttpServiceMock>();
    const auto& input = "1000\n2000\n3000\n\n4000\n\n5000\n6000\n\n7000\n8000\n9000\n\n10000";

    ALLOW_CALL(*httpService, getRawRequest(First::uri)).RETURN(input);

    const auto& sut = std::make_unique<First>(httpService);

    SECTION("Validate test case")
    {
        // Arrange

        // Act
        int result = sut->getResult();

        // Assert
        REQUIRE(result == 24000);
    }
}