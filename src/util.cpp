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
