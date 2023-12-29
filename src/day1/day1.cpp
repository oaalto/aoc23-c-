/**
 * Advent of Code 2023 day 1.
 * https://adventofcode.com/2023/day/1
 *
 * In part 1 the task is to find the first and last number from all the lines, then combine them into a number and sum
 * all of them.
 *
 * In part 2 we notice that some of the numbers are actually spelled out and we have the recalculate the sum again.
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include "../util.h"
#include "day1.h"

static const std::string NUMBERS = "0123456789";
static const std::map<std::string, std::string> NUMBER_MAP = {
    {"one",   "1"},
    {"two",   "2"},
    {"three", "3"},
    {"four",  "4"},
    {"five",  "5"},
    {"six",   "6"},
    {"seven", "7"},
    {"eight", "8"},
    {"nine",  "9"}
};

namespace day1::part1 {
    int parse_line(const std::string &line) {
        auto first = line.find_first_of(NUMBERS);
        auto last = line.find_last_of(NUMBERS);

        return stoi(line.substr(first, 1) + line.substr(last, 1));
    }

    void run() {
        int sum = calculate_sum_from_file("data/day1_input.txt", parse_line);

        std::cout << "Part 1 Sum: " << sum << std::endl;
    }
}

namespace day1::part2 {
    /**
     * Look for spelled out numbers, only the first and last on the line are added to the output vector.
     *
     * @param line The input string
     * @param found_numbers The vector which contains the found numbers and their indices.
     */
    void check_for_words(const std::string &line, std::vector<std::tuple<size_t, std::string>> &found_numbers) {
        for (auto &word: NUMBER_MAP) {
            auto first = line.find(word.first);
            if (first != std::string::npos) {
                found_numbers.emplace_back(first, word.second);
            }
            auto last = line.rfind(word.first);
            if (last != std::string::npos) {
                found_numbers.emplace_back(last, word.second);
            }
        }
    }

    int parse_line(const std::string &line) {
        std::vector<std::tuple<size_t, std::string>> found_numbers;

        auto first = line.find_first_of(NUMBERS);
        if (first != std::string::npos) {
            found_numbers.emplace_back(first, line.substr(first, 1));
        }

        auto last = line.find_last_of(NUMBERS);
        if (last != std::string::npos) {
            found_numbers.emplace_back(last, line.substr(last, 1));
        }

        check_for_words(line, found_numbers);

        auto number_comparator = [](const std::tuple<size_t, std::string> &t1,
                                    const std::tuple<size_t, std::string> &t2) {
            size_t first = get<0>(t1);
            size_t second = get<0>(t2);
            return first < second;
        };
        sort(found_numbers.begin(), found_numbers.end(), number_comparator);

        auto first_num = found_numbers[0];
        auto last_num = found_numbers[found_numbers.size() - 1];

        return stoi(get<1>(first_num) + get<1>(last_num));
    }

    void run() {
        int sum = calculate_sum_from_file("data/day1_input.txt", parse_line);
        std::cout << "Part 2 Sum: " << sum << std::endl;
    }
}
