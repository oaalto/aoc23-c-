#ifndef ADVENTOFCODE_DAY3_H
#define ADVENTOFCODE_DAY3_H

#include <string>
#include <vector>

namespace day3 {
    /**
     * A (x, y) coordinate in the input.
     */
    struct position {
        int x;
        int y;

        position(const int x, const int y) : x(x), y(y) {}
    };

    /**
     * A single part number and its bounding rectangle.
     */
    struct part_number {
        int value;
        position top_left;
        position bottom_right;

        part_number(const int value, const int start, const int end, const int y) : value(value),
                                                                                    top_left(
                                                                                        position(start - 1, y - 1)),
                                                                                    bottom_right(
                                                                                        position(end + 1, y + 1)) {}
    };

    /**
     * A single special character and its position.
     */
    struct special_char {
        char ch;
        position pos;

        special_char(const char ch, const int x, const int y) : ch(ch), pos(position(x, y)) {}
    };


    namespace part1 {
        /**
         * Parse all special characters and their locations from the input lines.
         *
         * @param lines All input lines
         * @return A vector of all special characters found.
         */
        std::vector<special_char> parse_special_characters(const std::vector<std::string> &lines);

        /**
         * Parse all valid part numbers from the input given the list of special characters. Return the summed up value from
         * all the valid part numbers.
         *
         * @param lines All input lines
         * @param special_characters All special characters found from the input.
         * @return The summed up value from all valid part numbers.
         */
        int calculate_result(const std::vector<std::string> &lines,
                             const std::vector<special_char> &special_characters);

        void run();
    }
}

#endif //ADVENTOFCODE_DAY3_H
