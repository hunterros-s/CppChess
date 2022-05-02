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
        std::cout << row + 1 << " ";
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
    std::cout << "  A B C D E F G H";
    return os;
}

Game::~Game() {
    clear_board();
}

void Game::add(std::string inp, Pieces p, int team) {
    del(inp);
    switch (p)
    {
    case Pieces::Pawn:
        (*this)[inp] = new Pawn(team);
        break;
    case Pieces::Bishop:
        (*this)[inp] = new Bishop(team);
        break;
    case Pieces::Knight:
        (*this)[inp] = new Knight(team);
        break;
    case Pieces::Rook:
        (*this)[inp] = new Rook(team);
        break;
    case Pieces::Queen:
        (*this)[inp] = new Queen(team);
        break;
    case Pieces::King:
        (*this)[inp] = new King(team);
        break;
    default:
        assert(false);
        break;
    }
}

void Game::del(std::string inp) {
    if ((*this)[inp]) {
        delete ((*this)[inp]);
        (*this)[inp] = nullptr;
    }
}
void Game::del(int row, int col) {
    if (find(row, col)) {
        delete find(row, col);
        find(row, col) = nullptr;
    }
}

void Game::clear_board() {
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            del(r, c);
        }
    }
}

void Game::move_piece(std::string from, std::string to) {
    assert((*this)[from]);
    del(to);
    (*this)[to] = (*this)[from];
    (*this)[from] = nullptr;

    std::cout << std::endl
        << (*this)[to]->icon << from
        << " -> " << to << std::endl << std::endl;
}

void Game::populate() {
    clear_board();

    //white side
    add("A2", Pieces::Pawn, 0);
    add("B2", Pieces::Pawn, 0);
    add("C2", Pieces::Pawn, 0);
    add("D2", Pieces::Pawn, 0);
    add("E2", Pieces::Pawn, 0);
    add("F2", Pieces::Pawn, 0);
    add("G2", Pieces::Pawn, 0);
    add("H2", Pieces::Pawn, 0);

    add("A1", Pieces::Rook, 0);
    add("B1", Pieces::Knight, 0);
    add("C1", Pieces::Bishop, 0);
    add("D1", Pieces::Queen, 0);
    add("E1", Pieces::King, 0);
    add("F1", Pieces::Bishop, 0);
    add("G1", Pieces::Knight, 0);
    add("H1", Pieces::Rook, 0);


    //black side
    add("A7", Pieces::Pawn, 1);
    add("B7", Pieces::Pawn, 1);
    add("C7", Pieces::Pawn, 1);
    add("D7", Pieces::Pawn, 1);
    add("E7", Pieces::Pawn, 1);
    add("F7", Pieces::Pawn, 1);
    add("G7", Pieces::Pawn, 1);
    add("H7", Pieces::Pawn, 1);

    add("A8", Pieces::Rook, 1);
    add("B8", Pieces::Knight, 1);
    add("C8", Pieces::Bishop, 1);
    add("D8", Pieces::Queen, 1);
    add("E8", Pieces::King, 1);
    add("F8", Pieces::Bishop, 1);
    add("G8", Pieces::Knight, 1);
    add("H8", Pieces::Rook, 1);
}