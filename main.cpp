#include <iostream>
#include "chess.h"

using namespace std;



int main() {
    Board b;

    b.add("A4", new Pawn()).add("A5", new Pawn());

    b.add("A4", new Pawn());
    return 0;
}