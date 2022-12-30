cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCEFILES
    main.cpp
    data/FileRepository.cpp
    helpers/ListHelper.cpp

    # Day 1
    results/day1/Input.cpp
    results/day1/First.cpp
    results/day1/Second.cpp

    # Day 2
    results/day2/Input.cpp
    results/day2/Game.cpp
    results/day2/First.cpp
    results/day2/Second.cpp

    # Day 3
    results/day3/Input.cpp
    results/day3/PriorityMapper.cpp
    results/day3/First.cpp
    results/day3/Second.cpp

    # Day 4
    results/day4/Input.cpp
    results/day4/Logic.cpp
    results/day4/First.cpp
    results/day4/Second.cpp

    # Day 5
    results/day5/Input.cpp
    results/day5/Logic.cpp
    results/day5/First.cpp
    results/day5/Second.cpp
)

add_executable(
        ${CMAKE_PROJECT_NAME}
        ${SOURCEFILES}
)


install(TARGETS ${CMAKE_PROJECT_NAME}
        RUNTIME
        DESTINATION bin
)