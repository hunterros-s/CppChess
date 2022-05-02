#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#include "piece.h"

class Game {
private:

    Piece * Board[8*8] = {nullptr};
    /////



    Piece * & find(int, int);
public:
    Piece * & operator[](std::string);
    friend std::ostream & operator<<(std::ostream &, Game &);

    ~Game();
    //normal constructor
    Game() {};
    //disable copy constructor
    Game(const Game &) = delete;
    //disable assignment operator
    Game & operator=(const Game &) = delete;
};