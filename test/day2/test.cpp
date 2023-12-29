#include <catch2/catch_test_macros.hpp>
#include "../../src/day2/day2.h"
#include "../../src/util.h"

TEST_CASE("Day 2: Part 1", "Full test from file") {
    int sum = calculate_sum_from_file("test/day2/part1_input.txt", day2::part1::parse_line);
    REQUIRE(sum == 8);
}

TEST_CASE("Day 2: Part 2", "Full test from file") {
    int sum = calculate_sum_from_file("test/day2/part2_input.txt", day2::part2::parse_line);
    REQUIRE(sum == 2286);
}