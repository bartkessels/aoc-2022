cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCEFILES
    main.cpp
    helpers/ListHelper.cpp
    service/CprHttpService.cpp

    # Day 1
    results/day1/First.cpp
    results/day1/Second.cpp

    # Day 2
    results/day2/StrategyMapper.cpp
    results/day2/RoundOutcomeMapper.cpp
    results/day2/DataCleaner.cpp
    results/day2/First.cpp
    results/day2/Second.cpp
    results/day2/Game.cpp

    # Day 3
    results/day3/DataCleaner.cpp
    results/day3/PriorityMapper.cpp
    results/day3/First.cpp
    results/day3/Second.cpp

    results/Result.cpp
)

add_executable(
        ${CMAKE_PROJECT_NAME}
        ${SOURCEFILES}
)


install(TARGETS ${CMAKE_PROJECT_NAME}
        RUNTIME
        DESTINATION bin
)

# Link libraries
target_link_libraries(${CMAKE_PROJECT_NAME} cpr::cpr)