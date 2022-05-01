#include "piece.h"
#include <vector>
#include <cassert>

class Board {
private:
    Piece * b[8*8] = {nullptr};
public:
    Piece * & operator()(int, int);
    Piece * & operator[](std::string);

    Board & add(std::string, Piece *);

    ~Board();
};
Piece * & Board::operator()(int row, int col) {
    assert(row >= 0 && row <= 7);
    assert(col >= 0 && col <= 7);
    return b[row*8 + col];
}
Piece * & Board::operator[](std::string inp) {
    char col_ = inp[0];
    char row_ = inp[1];

    int c = tolower(col_) - 'a'; // [0, 7]
    int r = row_ - '0'; // [0, 7]

    return (*this)(r, c);
}
//REQUIRES: ptr should be a 
Board & Board::add(std::string inp, Piece * ptr) {
    if (!(*this)[inp]) {
        (*this)[inp] = ptr;
    } else {
        delete ptr;
    }
    return (*this);
}

Board::~Board() {
    for (int i = 0; i < 8*8; ++i) {
        if (b[i]) {
            delete b[i];
        }
    }
}