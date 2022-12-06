cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(SOURCEFILES
    ../src/results/Result.cpp
    ../src/helpers/ListHelper.cpp

    # Day 1
    ../src/results/day1/First.cpp
    ../src/results/day1/Second.cpp

    # Day 2
    ../src/results/day2/StrategyMapper.cpp
    ../src/results/day2/RoundOutcomeMapper.cpp
    ../src/results/day2/DataCleaner.cpp
    ../src/results/day2/First.cpp
    ../src/results/day2/Second.cpp
    ../src/results/day2/Game.cpp

    # Day 3
    ../src/results/day3/DataCleaner.cpp
    ../src/results/day3/PriorityMapper.cpp
    ../src/results/day3/First.cpp
)

set(TESTFILES
    main.cpp

    # Day 1
    day1/first_test.cpp
    day1/second_test.cpp

    # Day 2
    day2/RoundOutcomeMapper_test.cpp
    day2/StrategyMapper_test.cpp
    day2/First_test.cpp
    day2/Second_test.cpp
    day2/Game_test.cpp

    # Day 3
    day3/PriorityMapper_test.cpp
    day3/First_test.cpp
)

add_executable(aoc_tests ${SOURCEFILES} ${TESTFILES})

include_directories(../src)

target_link_libraries(aoc_tests cpr::cpr)
target_link_libraries(aoc_tests trompeloeil Catch2::Catch2)

enable_testing()
add_test(NAME aoc_tests COMMAND aoc_tests)