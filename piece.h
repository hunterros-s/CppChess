#ifndef _PIECE_
#define _PIECE_


enum class Pieces {
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King
};

enum class Color {
    Black,
    White
};

//ROW = Y
//COL = X
struct Position {
    int x;
    int y;
    Position();
    Position(int, int);
    Position(std::string);
};

struct Piece {
    Color team;
    char icon;

    Piece(char, Color);
};

struct Pawn : Piece {
    Pawn(Color t) : Piece('p', t) {};
};

struct Bishop : Piece {
    Bishop(Color t) : Piece('b', t) {};
};

struct Knight : Piece {
    Knight(Color t) : Piece('n', t) {};
};

struct Rook : Piece {
    Rook(Color t) : Piece('r', t) {};
};

struct Queen : Piece {
    Queen(Color t) : Piece('q', t) {};
};

struct King : Piece {
    King(Color t) : Piece('k', t) {};
};

std::ostream & operator<<(std::ostream &, const Position &);

#endif