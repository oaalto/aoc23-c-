#include <catch2/catch_test_macros.hpp>
#include "../../src/day1/day1.h"
#include "../../src/util.h"

TEST_CASE("Day 1: Part 1", "Full test from file") {
    int sum = calculate_sum_from_file("test/day1/part1_input.txt", day1::part1::parse_line);
    REQUIRE(sum == 142);
}

TEST_CASE("Day 1: Part 2", "Full test from file") {
    int sum = calculate_sum_from_file("test/day1/part2_input.txt", day1::part2::parse_line);
    REQUIRE(sum == 281);
}