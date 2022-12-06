cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(aoc2022
    VERSION 0.0.1
    DESCRIPTION "Advent of Code 2022"
    HOMEPAGE_URL "https://github.com/bartkessels/aoc-2022"
)

# General project setup
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_XX_STANDARD 20)
set(CMAKE_XX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build)

# Subdirectories
add_subdirectory(third_party)
add_subdirectory(src)
add_subdirectory(tests)

# Copy input files to current working directory
file(GLOB input_files res/*.txt)
file(COPY ${input_files} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/res)