cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(SOURCEFILES
    ../src/results/Result.cpp
    ../src/helpers/ListHelper.cpp

    ../src/results/day1/First.cpp
    ../src/results/day1/Second.cpp
)

set(TESTFILES
    main.cpp

    day1/first_test.cpp
    day1/second_test.cpp
)

add_executable(aoc_tests ${SOURCEFILES} ${TESTFILES})

include_directories(../src)

target_link_libraries(aoc_tests cpr::cpr)
target_link_libraries(aoc_tests trompeloeil Catch2::Catch2)

enable_testing()
add_test(NAME aoc_tests COMMAND aoc_tests)