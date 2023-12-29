cmake_minimum_required(VERSION 3.27)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 23)

add_executable(aoc
        src/main.cpp
        src/day1/day1.h
        src/day1/day1.cpp
        src/day2/day2.h
        src/day2/day2.cpp
        src/day3/day3.h
        src/day3/day3.cpp
        src/util.cpp
        src/util.h
)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests
        test/day1/test.cpp
        src/day1/day1.h
        src/day1/day1.cpp
        src/day2/day2.h
        src/day2/day2.cpp
        src/day3/day3.h
        src/day3/day3.cpp
        src/util.cpp
        src/util.h
)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)