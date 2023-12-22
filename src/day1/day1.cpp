#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
#include "../util.h"

using namespace std;

static const string NUMBERS = "0123456789";
static const map<string, string> NUMBER_MAP = {
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

namespace part1 {
    int parse_line(const string &line) {
        auto first = line.find_first_of(NUMBERS);
        auto last = line.find_last_of(NUMBERS);

        return stoi(line.substr(first, 1) + line.substr(last, 1));
    }

    void run() {
        int sum = calculate_sum_from_file("data/day1_input.txt", parse_line);

        cout << "Part 1 Sum: " << sum << endl;
    }
}

namespace part2 {
    void check_for_words(const string &line, vector<tuple<size_t, string>> &found_numbers) {
        for (auto &word: NUMBER_MAP) {
            auto first = line.find(word.first);
            if (first != string::npos) {
                found_numbers.emplace_back(first, word.second);
            }
            auto last = line.rfind(word.first);
            if (last != string::npos) {
                found_numbers.emplace_back(last, word.second);
            }
        }
    }

    bool number_comparator(const tuple<size_t, string> &t1, const tuple<size_t, string> &t2) {
        size_t first = get<0>(t1);
        size_t second = get<0>(t2);
        return first < second;
    }

    int parse_line(const string &line) {
        vector<tuple<size_t, string>> found_numbers;

        auto first = line.find_first_of(NUMBERS);
        if (first != string::npos) {
            found_numbers.emplace_back(first, line.substr(first, 1));
        }

        auto last = line.find_last_of(NUMBERS);
        if (last != string::npos) {
            found_numbers.emplace_back(last, line.substr(last, 1));
        }

        check_for_words(line, found_numbers);

        sort(found_numbers.begin(), found_numbers.end(), number_comparator);

        auto first_num = found_numbers[0];
        auto last_num = found_numbers[found_numbers.size() - 1];

        return stoi(get<1>(first_num) + get<1>(last_num));
    }

    void run() {
        int sum = calculate_sum_from_file("data/day1_input.txt", parse_line);
        cout << "Part 2 Sum: " << sum << endl;
    }
}

int main() {
    part1::run();
    part2::run();

    return 0;
}
