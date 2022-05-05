#include <iostream>
#include "game.h"
#include "piece.h"

using namespace std;

int main() {
    Game g;

    g.populate();

    cout << g << endl;

    string input;

    while (cin >> input) {
        g.move_piece(
            Position(input.substr(0,2)), 
            Position(input.substr(2, 2))
        );

        cout << g << endl;
    }

    return 0;
}