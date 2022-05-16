#include <string>
#include <cassert>
#include <iostream>

#include "piece.h"

Position::Position() : index(0) {};
Position::Position(int index_in) : index(index_in) {};
Position::Position(int x_in, int y_in) : index(y_in * 8 + x_in) {};
Position::Position(std::string inp) {
    char col_ = inp[0];
    char row_ = inp[1];

    int x = tolower(col_) - 'a';
    int y = row_ - '1';

    index = y * 8 + x;
};

int Position::x() const {
    return index % 8;
}

int Position::y() const {
    return index / 8;
}

Position operator+(Position & lhs, int rhs) {
    return Position(lhs.index + rhs);
}

std::ostream & operator<<(std::ostream & os, const Position & pos) {
    os << char('A' + pos.x());
    os << char('1' + pos.y());
    return os;
}

std::ostream & operator<<(std::ostream & os, Color & c) {
    switch (c)
    {
    case Color::White:
        return os << "White";
    case Color::Black:
        return os << "Black";
    }
    assert(false);
    return os;
}

std::ostream & operator<<(std::ostream & os, Piece * & piece) {
    os << piece->team << " ";
    os << piece->name;
    return os;
}

Piece::Piece(char c, Color t, Game * g, std::string n, Position p)
 : team(t), icon(c), board(g), name(n), pos(p) {
    if (t == Color::Black) { icon = toupper(icon); }
}

// valid moves

bool Pawn::valid_move(Position) {
    return false;
}

bool Bishop::valid_move(Position) {
    return false;
}

bool Knight::valid_move(Position) {
    return false;
}

bool Rook::valid_move(Position) {
    return false;
}

bool Queen::valid_move(Position) {
    return false;
}

bool King::valid_move(Position) {
    return false;
}