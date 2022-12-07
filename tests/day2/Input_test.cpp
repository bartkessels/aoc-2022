#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include <memory>

#include "data/Repository.hpp"
#include "results/day2/Input.hpp"

using namespace AOC2022::data;
using namespace AOC2022::results::day2;

class RepositoryMock: public AOC2022::data::Repository
{
    public:
        MAKE_MOCK1(getData, std::string(int), override);
};

TEST_CASE("Input day 2")
{
    const auto& repository = std::make_shared<RepositoryMock>();
    const auto& input = "A Y\nB X\nC Z\n";

    ALLOW_CALL(*repository, getData(trompeloeil::_)).RETURN(input);

    const auto& sut = std::make_unique<Input>(repository);

    SECTION("Returns it in a list of 3 rounds")
    {
        // Arrange

        // Act
        const auto& result = sut->getRounds();

        // Assert
        REQUIRE(result.size() == 3);
    }
}