#ifndef ADVENTOFCODE_UTIL_H
#define ADVENTOFCODE_UTIL_H

#include <string>
#include <functional>
#include <string_view>
#include <vector>

/**
 * Read the given file line by line and run them through the callback which parses a number from them. Finally return
 * a sum of the numbers to the caller.
 *
 * @param file_name The name of the input file
 * @param callback The callback which parses the input number from a line
 * @return All input numbers summed up.
 */
int calculate_sum_from_file(const std::string &, const std::function<int(const std::string &)> &);

/**
 * Read the file into memory line by line.
 *
 * @param file_name The name of the input file
 * @return A vector of strings containing the lines from the file.
 */
std::vector<std::string> read_file(const std::string &);

#endif //ADVENTOFCODE_UTIL_H
