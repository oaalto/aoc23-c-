#include <fstream>
#include "util.h"

using namespace std;

int calculate_sum_from_file(const string &file_name, const function<int(const string &)> &callback) {
    int sum = 0;

    ifstream file(file_name);
    for (string line; getline(file, line);) {
        sum += callback(line);
    }

    return sum;
}

vector<string> read_file(const string &file_name) {
    vector<string> lines;
    ifstream file(file_name);
    for (string line; getline(file, line);) {
        lines.push_back(line);
    }
    return lines;
}

vector<string_view> split(const string_view str, const char delim) {
    vector<string_view> strings;

    size_t prev_index = 0;
    size_t index = str.find(delim);
    while (index != string::npos) {
        strings.push_back(str.substr(prev_index, index - prev_index));
        prev_index = index + 1;
        index = str.find(delim, index + 1);
    }

    strings.push_back(str.substr(prev_index));

    return strings;
}
