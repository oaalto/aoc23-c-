#include <string>
#include <iostream>
#include <regex>
#include <numeric>
#include <algorithm>
#include "../util.h"
#include "day2.h"

using namespace std;

static const int RED_CUBES = 12;
static const int GREEN_CUBES = 13;
static const int BLUE_CUBES = 14;

int parse_game_id(const string &line) {
    regex e("^Game (.*): (.*)");
    match_results<string::const_iterator> sm;
    if (regex_match(line, sm, e)) {
        return stoi(sm[1].str());
    }
    return 0;
}

string_view parse_cube_data(const string_view line) {
    const size_t index = line.find_first_of(':');
    return line.substr(index + 1);
}

void update_cube(cubes &cube, const string_view cube_str) {
    regex e("(.*) (red|green|blue)");
    match_results<string_view::const_iterator> sm;
    if (regex_match(cube_str.begin(), cube_str.end(), sm, e)) {
        const int count = stoi(sm[1].str());
        const string color = sm[2].str();
        if (color == "red") {
            cube.red += count;
        } else if (color == "green") {
            cube.green += count;
        } else if (color == "blue") {
            cube.blue += count;
        }
    }
}

vector<cubes> parse_cubes(const vector<string_view> &cube_strings) {
    vector<cubes> parsed_cubes;

    for (const string_view sv: cube_strings) {
        cubes cube {};
        auto splitted = split(sv, ',');
        for (auto one_cube: splitted) {
            update_cube(cube, one_cube);
        }
        parsed_cubes.push_back(cube);
    }

    return parsed_cubes;
}

vector<cubes> parse_cubes_from_line(const string &line) {
    const string_view cube_data = parse_cube_data(line);
    const vector<string_view> cube_strings = split(cube_data, ';');
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

    bool has_invalid_cubes(const vector<cubes> &cubes) {
        return ranges::any_of(cubes.begin(), cubes.end(), is_invalid_cube);
    }

    int parse_line(const string &line) {
        const int game_id = parse_game_id(line);
        vector<cubes> cubes = parse_cubes_from_line(line);

        return has_invalid_cubes(cubes) ? 0 : game_id;
    }

    void run() {
        int sum = calculate_sum_from_file("data/day2_input.txt", parse_line);

        cout << "Part 1 Sum: " << sum << endl;
    }
}

namespace part2 {
    cubes find_largest_values(const vector<cubes> &cubes_to_search) {
        cubes cube {};
        for (const cubes c: cubes_to_search) {
            cube.red = max(c.red, cube.red);
            cube.green = max(c.green, cube.green);
            cube.blue = max(c.blue, cube.blue);
        }
        return cube;
    }

    int parse_line(const string &line) {
        vector<cubes> cubes_from_line = parse_cubes_from_line(line);
        cubes cube = find_largest_values(cubes_from_line);
        return cube.red * cube.green * cube.blue;
    }

    void run() {
        int sum = calculate_sum_from_file("data/day2_input.txt", parse_line);

        cout << "Part 2 Sum: " << sum << endl;
    }
}

int main() {
    part1::run();
    part2::run();

    return 0;
}