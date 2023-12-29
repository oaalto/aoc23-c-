#ifndef ADVENTOFCODE_DAY3_H
#define ADVENTOFCODE_DAY3_H

#include <string>

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
        int parse_line(const std::string &line);

        void run();
    }

    namespace part2 {
        int parse_line(const std::string &line);

        void run();
    }
}

#endif //ADVENTOFCODE_DAY3_H
