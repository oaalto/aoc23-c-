#include <string>
#include <iostream>
#include <regex>
#include <numeric>
#include <algorithm>
#include <ranges>
#include "../util.h"
#include "day2.h"

static const int RED_CUBES = 12;
static const int GREEN_CUBES = 13;
static const int BLUE_CUBES = 14;

int parse_game_id(const std::string &line) {
    std::regex e("^Game (.*): (.*)");
    std::match_results<std::string::const_iterator> sm;
    if (regex_match(line, sm, e)) {
        return stoi(sm[1].str());
    }
    return 0;
}

std::string_view parse_cube_data(const std::string_view line) {
    const size_t index = line.find_first_of(':');
    return line.substr(index + 1);
}

void update_cube(cubes &cube, const std::string_view cube_str) {
    std::regex e("(.*) (red|green|blue)");
    std::match_results<std::string_view::const_iterator> sm;
    if (regex_match(cube_str.begin(), cube_str.end(), sm, e)) {
        const int count = stoi(sm[1].str());
        const std::string color = sm[2].str();
        if (color == "red") {
            cube.red += count;
        } else if (color == "green") {
            cube.green += count;
        } else if (color == "blue") {
            cube.blue += count;
        }
    }
}

std::vector<cubes> parse_cubes(const std::vector<std::string_view> &cube_strings) {
    std::vector<cubes> parsed_cubes;

    for (const std::string_view sv: cube_strings) {
        cubes cube {};
        auto splitted = std::views::split(sv, ',');
        for (auto one_cube: splitted) {
            update_cube(cube, std::string_view(one_cube));
        }
        parsed_cubes.push_back(cube);
    }

    return parsed_cubes;
}

std::vector<cubes> parse_cubes_from_line(const std::string &line) {
    const std::string_view cube_data = parse_cube_data(line);
    const std::vector<std::string_view> cube_strings =
        cube_data
        | std::views::split(';')
        | std::views::transform([](auto r) { return std::string_view(r); })
        | std::ranges::to<std::vector>();
    return parse_cubes(cube_strings);
}

namespace part1 {
    bool is_valid_cube(const cubes &cube) {
        return cube.red <= RED_CUBES &&
               cube.green <= GREEN_CUBES &&
               cube.blue <= BLUE_CUBES;
    }

    bool is_invalid_cube(const cubes &cube) {
        return !is_valid_cube(cube);
    }

    bool has_invalid_cubes(const std::vector<cubes> &cubes) {
        return std::ranges::any_of(cubes.begin(), cubes.end(), is_invalid_cube);
    }

    int parse_line(const std::string &line) {
        const int game_id = parse_game_id(line);
        std::vector<cubes> cubes = parse_cubes_from_line(line);

        return has_invalid_cubes(cubes) ? 0 : game_id;
    }

    void run() {
        int sum = calculate_sum_from_file("data/day2_input.txt", parse_line);

        std::cout << "Part 1 Sum: " << sum << std::endl;
    }
}

namespace part2 {
    cubes find_largest_values(const std::vector<cubes> &cubes_to_search) {
        cubes cube {};
        for (const cubes c: cubes_to_search) {
            cube.red = std::max(c.red, cube.red);
            cube.green = std::max(c.green, cube.green);
            cube.blue = std::max(c.blue, cube.blue);
        }
        return cube;
    }

    int parse_line(const std::string &line) {
        std::vector<cubes> cubes_from_line = parse_cubes_from_line(line);
        cubes cube = find_largest_values(cubes_from_line);
        return cube.red * cube.green * cube.blue;
    }

    void run() {
        int sum = calculate_sum_from_file("data/day2_input.txt", parse_line);

        std::cout << "Part 2 Sum: " << sum << std::endl;
    }
}

int main() {
    part1::run();
    part2::run();

    return 0;
}