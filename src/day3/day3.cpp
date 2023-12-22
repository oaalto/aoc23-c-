#include "day3.h"
#include "../util.h"
#include <print>
#include <ranges>
#include <algorithm>

using namespace std;

namespace part1 {
    vector<special_char> parse_special_characters_from_line(const pair<int, string> &line_info) {
        auto is_special_char = [](const pair<int, char> &p) {
            return p.second != '.' && !isdigit(p.second);
        };
        auto to_special_char = [y = line_info.first](const pair<int, char> &p) {
            return make_special_char(p.second, p.first, y);
        };

        return line_info.second
               | views::enumerate
               | views::filter(is_special_char)
               | views::transform(to_special_char)
               | ranges::to<vector>();
    }

    vector<special_char> parse_special_characters(const vector<string> &lines) {
        return lines
               | views::enumerate
               | views::transform(parse_special_characters_from_line)
               | views::join
               | ranges::to<vector>();
    }

    vector<part_number> parse_part_numbers_from_line(const pair<int, string> &line_info) {
        auto is_digit = [](const pair<int, char> &p) {
            return isdigit(p.second);
        };

        struct reducer {
            int start_digit_pos = -1;
            int end_digit_pos = 0;
            string cur_part_number;
            vector<part_number> part_numbers;
        };
        auto to_part_number =
            [&, y = line_info.first](reducer r, const pair<int, char> &p) {
                if (r.start_digit_pos == -1) {
                    r.start_digit_pos = p.first;
                    r.end_digit_pos = p.first;
                }

                if (p.first - r.end_digit_pos > 1) {
                    r.part_numbers.push_back(make_part_number(stoi(r.cur_part_number), r.start_digit_pos,
                                                              r.end_digit_pos, y));

                    r.start_digit_pos = p.first;
                    r.end_digit_pos = p.first;
                    r.cur_part_number = p.second;
                } else {
                    r.cur_part_number += p.second;
                    r.end_digit_pos = p.first;
                }

                return r;
            };

        auto digits_view = line_info.second
                           | views::enumerate
                           | views::filter(is_digit);

        auto r = ranges::fold_left(digits_view, reducer {},
                                   to_part_number);

        // Handle possible numbers from the end of the line
        int last_num = stoi(r.cur_part_number);
        if (!r.part_numbers.empty() && r.part_numbers.back().value != last_num) {
            r.part_numbers.push_back(make_part_number(last_num, r.start_digit_pos, r.end_digit_pos,
                                                      line_info.first));
        }

        return r.part_numbers;
    }

    bool rect_contains(const position &top_left, const position &bottom_right, const position &pos) {
        return pos.x >= top_left.x && pos.x <= bottom_right.x
               && pos.y >= top_left.y && pos.y <= bottom_right.y;
    }

    int calculate_result(const vector<string> &lines, const vector<special_char> &special_characters) {
        auto filter = [special_characters](const part_number &pn) {
            return ranges::any_of(special_characters, [pn](const special_char sc) {
                return rect_contains(pn.top_left, pn.bottom_right, sc.pos);
            });
        };

        auto part_number_view = lines
                                | views::enumerate
                                | views::transform(parse_part_numbers_from_line)
                                | views::join
                                | views::filter(filter);

        return ranges::fold_left(part_number_view, 0, [](int sum, const part_number &pn) {
            return sum + pn.value;
        });
    }

    void run() {
        vector<string> lines = read_file("data/day3_input.txt");
        const auto special_characters = parse_special_characters(lines);

        const int result = calculate_result(lines, special_characters);

        println("Part 1 result: {}", result);
    }
}

int main() {
    part1::run();

    return 0;
}