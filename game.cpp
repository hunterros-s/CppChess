#include "game.h"
#include "piece.h"

//private
Piece * & Game::find(int row, int col) {
    assert(row >= 0 && row <= 7);
    assert(col >= 0 && col <= 7);
    return Board[row*8 + col];
}

//public
Piece * & Game::at(Position pos) {
    return find(pos.y(), pos.x());
}


Piece * & Game::operator[](Position pos) {
    return at(pos);
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

void Game::add(Position pos, Pieces p, Color team) {
    del(pos);
    switch (p)
    {
    case Pieces::Pawn:
        (*this)[pos] = new Pawn(team, this, pos);
        break;
    case Pieces::Bishop:
        (*this)[pos] = new Bishop(team, this, pos);
        break;
    case Pieces::Knight:
        (*this)[pos] = new Knight(team, this, pos);
        break;
    case Pieces::Rook:
        (*this)[pos] = new Rook(team, this, pos);
        break;
    case Pieces::Queen:
        (*this)[pos] = new Queen(team, this, pos);
        break;
    case Pieces::King:
        (*this)[pos] = new King(team, this, pos);
        break;
    default:
        assert(false);
        break;
    }
    //add to each team pieces.
    switch(team)
    {
    case Color::White:
        white_pieces.push_back((*this)[pos]);
        break;
    case Color::Black:
        black_pieces.push_back((*this)[pos]);
        break;
    default:
        assert(false);
        break;
    }
}
void Game::del(Position pos) {
    if ((*this)[pos]) {

        //delete from white or black piece vector
        switch ((*this)[pos]->team)
        {
        case Color::Black:
            for (auto it = black_pieces.begin(); it != black_pieces.end(); ++it)
            {
                if ((*this)[pos] == *it)
                {
                    black_pieces.erase(it);
                }
            }
            break;
        case Color::White:
            for (auto it = white_pieces.begin(); it != white_pieces.end(); ++it)
            {
                if ((*this)[pos] == *it)
                {
                    white_pieces.erase(it);
                }
            }
            break;
        default:
            assert(false);
            break;
        }
        delete ((*this)[pos]);
        (*this)[pos] = nullptr;
    }
}

void Game::clear_board() {
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            del(Position(c, r));
        }
    }
    white_pieces.clear();
    black_pieces.clear();
}

void Game::move_piece(Position from, Position to) {
    assert((*this)[from]);
    del(to);
    (*this)[to] = (*this)[from];
    (*this)[to]->pos = to;
    (*this)[from] = nullptr;
}

void Game::populate() {
    clear_board();

    //white side
    add(Position("A2"), Pieces::Pawn, Color::White);
    add(Position("B2"), Pieces::Pawn, Color::White);
    add(Position("C2"), Pieces::Pawn, Color::White);
    add(Position("D2"), Pieces::Pawn, Color::White);
    add(Position("E2"), Pieces::Pawn, Color::White);
    add(Position("F2"), Pieces::Pawn, Color::White);
    add(Position("G2"), Pieces::Pawn, Color::White);
    add(Position("H2"), Pieces::Pawn, Color::White);

    add(Position("A1"), Pieces::Rook, Color::White);
    add(Position("B1"), Pieces::Knight, Color::White);
    add(Position("C1"), Pieces::Bishop, Color::White);
    add(Position("D1"), Pieces::Queen, Color::White);
    add(Position("E1"), Pieces::King, Color::White);
    add(Position("F1"), Pieces::Bishop, Color::White);
    add(Position("G1"), Pieces::Knight, Color::White);
    add(Position("H1"), Pieces::Rook, Color::White);


    //black side
    add(Position("A7"), Pieces::Pawn, Color::Black);
    add(Position("B7"), Pieces::Pawn, Color::Black);
    add(Position("C7"), Pieces::Pawn, Color::Black);
    add(Position("D7"), Pieces::Pawn, Color::Black);
    add(Position("E7"), Pieces::Pawn, Color::Black);
    add(Position("F7"), Pieces::Pawn, Color::Black);
    add(Position("G7"), Pieces::Pawn, Color::Black);
    add(Position("H7"), Pieces::Pawn, Color::Black);

    add(Position("A8"), Pieces::Rook, Color::Black);
    add(Position("B8"), Pieces::Knight, Color::Black);
    add(Position("C8"), Pieces::Bishop, Color::Black);
    add(Position("D8"), Pieces::Queen, Color::Black);
    add(Position("E8"), Pieces::King, Color::Black);
    add(Position("F8"), Pieces::Bishop, Color::Black);
    add(Position("G8"), Pieces::Knight, Color::Black);
    add(Position("H8"), Pieces::Rook, Color::Black);
}