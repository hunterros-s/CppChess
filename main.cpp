#include <iostream>
#include "game.h"

using namespace std;

int main() {
    Game g;

    //need better ways to add pieces
    g["A1"] = new Pawn(0);
    g["B2"] = new King(1);

    cout << g << endl;
    return 0;
}