#ifndef ADVENTOFCODE_DAY3_H
#define ADVENTOFCODE_DAY3_H

struct position {
    int x;
    int y;
};

struct part_number {
    int value;
    position top_left;
    position bottom_right;
};

struct special_char {
    char ch;
    position pos;
};

part_number make_part_number(const int value, const int start, const int end, const int y) {
    return part_number {
        .value = value,
        .top_left = position {
            .x = start - 1,
            .y = y - 1
        },
        .bottom_right = position {
            .x = end + 1,
            .y = y + 1
        }
    };
}

special_char make_special_char(const char ch, const int x, const int y) {
    return special_char {
        .ch = ch,
        .pos = position {
            .x = x,
            .y = y
        }
    };
}

#endif //ADVENTOFCODE_DAY3_H
