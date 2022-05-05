#include <string>
#include <cassert>
#include <iostream>

#include "piece.h"

Position::Position() : x(0), y(0) { };
Position::Position(int x_in, int y_in) : x(x_in), y(y_in) {
    assert(x >= 0 && x <= 7);
    assert(y >= 0 && y <= 7);
};
Position::Position(std::string inp) {
    char col_ = inp[0];
    char row_ = inp[1];

    x = tolower(col_) - 'a';
    y = row_ - '1';
};

std::ostream & operator<<(std::ostream & os, const Position & pos) {
    os << char('A' + pos.x);
    os << char('1' + pos.y);
    return os;
}

Piece::Piece(char c, Color t) : team(t), icon(c) {
    if (t == Color::Black) { icon = toupper(icon); }
}