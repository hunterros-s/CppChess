#include "game.h"

//private
Piece * & Game::find(int row, int col) {
    assert(row >= 0 && row <= 7);
    assert(col >= 0 && col <= 7);
    return Board[row*8 + col];
}

//public
Piece * & Game::operator[](std::string input) {
    char col_ = input[0];
    char row_ = input[1];

    int c = tolower(col_) - 'a';
    int r = row_ - '1';

    return find(r, c);
}

std::ostream & operator<<(std::ostream & os, Game & g) {
    for (int row = 7; row >= 0; --row) {
        for (int col = 0; col <= 7; ++col) {
            if (g.find(row, col)) {
                std::cout << g.find(row, col)->icon;
            } else {
                std::cout << "-";
            }
            std::cout << " ";
        }
        os << std::endl;
    }
    return os;
}

Game::~Game() {
    for (int i = 0; i < 8*8; ++i) {
        if (Board[i]) {
            delete Board[i];
        }
    }
}