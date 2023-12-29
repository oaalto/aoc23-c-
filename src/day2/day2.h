#ifndef ADVENTOFCODE_DAY2_H
#define ADVENTOFCODE_DAY2_H

#include <string>

namespace day2 {
    /**
     * A container for a single hand in a game.
     */
    struct cubes {
        int red = 0;
        int green = 0;
        int blue = 0;
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

#endif //ADVENTOFCODE_DAY2_H
