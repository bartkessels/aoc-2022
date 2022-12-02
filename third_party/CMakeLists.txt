cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

include(FetchContent)

# ------------------------------------------------------------------------------
# Trompeloeil
FetchContent_Declare(
    extern_trompeloeil

    GIT_REPOSITORY https://github.com/rollbear/trompeloeil.git
    GIT_TAG        v42)
FetchContent_MakeAvailable(extern_trompeloeil)

# ------------------------------------------------------------------------------
# Catch2
FetchContent_Declare(
    extern_catch2

    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v2.13.9)
FetchContent_MakeAvailable(extern_catch2)

# ------------------------------------------------------------------------------
# CPR
FetchContent_Declare(
        extern_cpr

        GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG        1.9.3)
FetchContent_MakeAvailable(extern_cpr)