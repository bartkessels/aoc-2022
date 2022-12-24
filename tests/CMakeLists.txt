cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(SOURCEFILES
    ../src/helpers/ListHelper.cpp

    # Day 1
    ../src/results/day1/Input.cpp
    ../src/results/day1/First.cpp
    ../src/results/day1/Second.cpp

    # Day 2
    ../src/results/day2/Input.cpp
    ../src/results/day2/Game.cpp
    ../src/results/day2/First.cpp
    ../src/results/day2/Second.cpp

    # Day 3
    ../src/results/day3/Input.cpp
    ../src/results/day3/PriorityMapper.cpp
    ../src/results/day3/First.cpp
    ../src/results/day3/Second.cpp

    # Day 4
    ../src/results/day4/Input.cpp
    ../src/results/day4/Logic.cpp
    ../src/results/day4/First.cpp
    ../src/results/day4/Second.cpp

    # Day 5
    ../src/results/day5/Input.cpp
    ../src/results/day5/Logic.cpp
    ../src/results/day5/First.cpp
)

set(TESTFILES
    main.cpp

    # Day 1
    day1/Input_test.cpp
    day1/First_test.cpp
    day1/Second_test.cpp

    # Day 2
    day2/Input_test.cpp
    day2/Game_test.cpp
    day2/First_test.cpp
    day2/Second_test.cpp

    # Day 3
    day3/Input_test.cpp
    day3/PriorityMapper_test.cpp
    day3/First_test.cpp
    day3/Second_test.cpp

    # Day 4
    day4/Input_test.cpp
    day4/First_test.cpp
    day4/Second_test.cpp

    # Day 5
    day5/Input_test.cpp
    day5/First_test.cpp
)

add_executable(aoc_tests ${SOURCEFILES} ${TESTFILES})

include_directories(../src)

target_link_libraries(aoc_tests trompeloeil Catch2::Catch2)

enable_testing()
add_test(NAME aoc_tests COMMAND aoc_tests)