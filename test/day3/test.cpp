#include <catch2/catch_test_macros.hpp>
#include "../../src/day3/day3.h"
#include "../../src/util.h"

TEST_CASE("Day 3: Part 1", "Full test from file") {
    std::vector<std::string> lines = read_file("test/day3/part1_input.txt");
    const auto special_characters = day3::part1::parse_special_characters(lines);

    const int result = day3::part1::calculate_result(lines, special_characters);
    REQUIRE(result == 4361);
}
