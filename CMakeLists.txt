cmake_minimum_required(VERSION 3.27)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 23)

add_executable(day1 src/day1/day1.cpp
        src/util.cpp
        src/util.h)
add_executable(day2 src/day2/day2.cpp
        src/util.cpp
        src/util.h
        src/day2/day2.h)
add_executable(day3 src/day3/day3.cpp src/day3/day3.h
        src/util.cpp
        src/util.h)
