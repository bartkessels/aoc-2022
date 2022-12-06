#include <catch2/catch.hpp>
#include <trompeloeil.hpp>
#include <memory>

#include "data/Repository.hpp"
#include "results/day1/Input.hpp"

using namespace AOC2022::data;
using namespace AOC2022::results::day1;

class RepositoryMock: public AOC2022::data::Repository
{
    public:
        MAKE_MOCK1(getData, std::string(int), override);
};

TEST_CASE("Input day 1")
{
    const auto& repository = std::make_shared<RepositoryMock>();
    const auto& input = "1000\n2000\n3000\n\n4000\n\n5000\n6000\n\n7000\n8000\n9000\n\n10000";

    ALLOW_CALL(*repository, getData(trompeloeil::_)).RETURN(input);

    const auto& sut = std::make_unique<Input>(repository);

    SECTION("Returns it in a list of 3 blocks")
    {
        // Arrange

        // Act
        const auto& result = sut->getBlocks();

        // Assert
        REQUIRE(result.size() == 5);
    }
}