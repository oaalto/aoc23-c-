#include <fstream>
#include "util.h"

int calculate_sum_from_file(const std::string &file_name, const std::function<int(const std::string &)> &callback) {
    int sum = 0;

    std::ifstream file(file_name);
    for (std::string line; getline(file, line);) {
        sum += callback(line);
    }

    return sum;
}

std::vector<std::string> read_file(const std::string &file_name) {
    std::vector<std::string> lines;
    std::ifstream file(file_name);
    for (std::string line; getline(file, line);) {
        lines.push_back(line);
    }
    return lines;
}

std::vector<std::string_view> split(const std::string_view str, const char delim) {
    std::vector<std::string_view> strings;

    size_t prev_index = 0;
    size_t index = str.find(delim);
    while (index != std::string::npos) {
        strings.push_back(str.substr(prev_index, index - prev_index));
        prev_index = index + 1;
        index = str.find(delim, index + 1);
    }

    strings.push_back(str.substr(prev_index));

    return strings;
}
