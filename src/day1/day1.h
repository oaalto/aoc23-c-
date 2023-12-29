#ifndef ADVENTOFCODE_DAY1_H
#define ADVENTOFCODE_DAY1_H

#include <string>

namespace day1 {
    namespace part1 {
        /**
         * Find the first and last number on the line and combine them into an integer.
         * This function assumes that there is at least 1 number in the input string.
         *
         * @param line The input string
         * @return The number gotten by combining the two numbers found.
         */
        int parse_line(const std::string &line);

        void run();
    }

    namespace part2 {
        /**
         * Find all the possible first and last numbers from the input, sort them and combine the first and last into
         * the result number.
         *
         * @param line The input string
         * @return The number combined from the first and last number, either spelled out or numeric.
         */
        int parse_line(const std::string &line);

        void run();
    }
}

#endif //ADVENTOFCODE_DAY1_H
