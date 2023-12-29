#include <fstream>
#include "util.h"

/**
 * Read the given file line by line and run them through the callback which parses a number from them. Finally return
 * a sum of the numbers to the caller.
 *
 * @param file_name The name of the input file
 * @param callback The callback which parses the input number from a line
 * @return All input numbers summed up.
 */
int calculate_sum_from_file(const std::string &file_name, const std::function<int(const std::string &)> &callback) {
    int sum = 0;

    std::ifstream file(file_name);
    for (std::string line; getline(file, line);) {
        sum += callback(line);
    }

    return sum;
}

/**
 * Read the file into memory line by line.
 *
 * @param file_name The name of the input file
 * @return A vector of strings containing the lines from the file.
 */
std::vector<std::string> read_file(const std::string &file_name) {
    std::vector<std::string> lines;
    std::ifstream file(file_name);
    for (std::string line; getline(file, line);) {
        lines.push_back(line);
    }
    return lines;
}
