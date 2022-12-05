cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCEFILES
    main.cpp
    helpers/ListHelper.cpp
    service/CprHttpService.cpp

    # Day 1
    results/day1/First.cpp
    results/day1/Second.cpp

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