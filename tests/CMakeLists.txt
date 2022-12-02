cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

# Copy test_file.txt to current working directory
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res/test_file.txt
        DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

set(SOURCEFILES

)

set(TESTFILES
    main.cpp
)

add_executable(aoc_tests ${SOURCEFILES} ${TESTFILES})

include_directories(../src)

target_link_libraries(aoc_tests cpr::cpr)
target_link_libraries(aoc_tests trompeloeil Catch2::Catch2)

enable_testing()
add_test(NAME aoc_tests COMMAND aoc_tests)