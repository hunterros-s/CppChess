#ifndef _GAME_
#define _GAME_

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#include "piece.h"

/*

WHITE = 0
BLACK = 1

*/


class Game {
private:

    Piece * Board[8*8] = {nullptr};
    /////
    Piece * & find(int, int);

    //maybe use a map??
    std::vector<Piece *> white_pieces;
    std::vector<Piece *> black_pieces;
public:
    //i should generate an attack and defend map.
    //i should make a vector for each sides' pieces

    Piece * & at(Position);

    Piece * & operator[](Position);

    friend std::ostream & operator<<(std::ostream &, Game &);

    void add(Position, Pieces, Color);

    void del(Position);

    void clear_board();

    void populate();

    bool legality_test(std::string, std::string);
    //need to check based on two conditions:
    //if the king is not in check:
    //  the moving piece is not absolutely pinned on it's move direction
    //  en passant requires special horizontal pin test of both involved pawns, which disappear from the same rank
    //  while castling, rook is not pinned horizontally
    //
    //if the king is in check:
    //  double check: only king moves to non-attacked squares, sliding check x-rays the king
    //  single check:
    //  capture of checking piece. the capturing piece is not absolutely pinned
    //  king moves to non-attacked sqaures, sliding check x-rays the king
    //  interposing moves in case of distance sliding check. the moving piece is not absolutely pinned

    void move_piece(Position, Position);

    ~Game();
    //normal constructor
    Game() {};
    //disable copy constructor
    Game(const Game &) = delete;
    //disable assignment operator
    Game & operator=(const Game &) = delete;
};

#endif