#ifndef _PIECE_
#define _PIECE_

#include <bitset>

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

std::ostream & operator<<(std::ostream &, Color &);

//ROW = Y
//COL = X

struct Position {
    int index;
    Position();
    Position(int);
    Position(int, int);
    Position(std::string);

    int y() const;
    int x() const;
};

Position operator+(Position &, int);

// move map
// 0s represent ineligble moves, 1s represent valid moves.
class MoveMap {
private:
    std::bitset<64> map;
public:
    //col = x, row = y
    int & at(int, int);
    int & operator[](Position);
};

MoveMap operator+(MoveMap & lhs, MoveMap & rhs);

//forward declaration:
class Game;

struct Piece {
    Color team;
    char icon;
    Game * board;
    std::string name;
    Position pos;

    Piece(char, Color, Game *, std::string, Position);

    virtual bool valid_move(Position) = 0;
};

struct Pawn : Piece {
    Pawn(Color t, Game * g, Position p) : Piece('p', t, g, "Pawn", p) {};
    bool can_double_move = true;
    bool valid_move(Position) override;
};

struct Bishop : Piece {
    Bishop(Color t, Game * g, Position p) : Piece('b', t, g, "Bishop", p) {};

    bool valid_move(Position) override;
};

struct Knight : Piece {
    Knight(Color t, Game * g, Position p) : Piece('n', t, g, "Knight", p) {};

    bool valid_move(Position) override;
};

struct Rook : Piece {
    Rook(Color t, Game * g, Position p) : Piece('r', t, g, "Rook", p) {};

    bool valid_move(Position) override;
};

struct Queen : Piece {
    Queen(Color t, Game * g, Position p) : Piece('q', t, g, "Queen", p) {};

    bool valid_move(Position) override;
};

struct King : Piece {
    King(Color t, Game * g, Position p) : Piece('k', t, g, "King", p) {};

    bool valid_move(Position) override;
};

std::ostream & operator<<(std::ostream &, const Position &);

std::ostream & operator<<(std::ostream &, Piece * &);

#endif