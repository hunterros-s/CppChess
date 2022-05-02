#include <iostream>
#include "game.h"

using namespace std;

int main() {
    Game g;

    g.populate();

    cout << g << endl;

    g.move_piece("E2", "E4");

    cout << g << endl;

    g.move_piece("G8", "F6");

    cout << g << endl;

    return 0;
}