#ifndef ADVENTOFCODE_UTIL_H
#define ADVENTOFCODE_UTIL_H

#include <string>
#include <functional>
#include <string_view>
#include <vector>

int calculate_sum_from_file(const std::string &, const std::function<int(const std::string &)> &);

std::vector<std::string> read_file(const std::string &);

std::vector<std::string_view> split(std::string_view, char);

#endif //ADVENTOFCODE_UTIL_H
