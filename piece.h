struct Piece {
    int team;
    char icon;

    Piece(char c, int t) : team(t), icon(c) { }
};

enum class Pieces {
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King
};

struct Pawn : Piece {
    Pawn(int t) : Piece('p', t) {
        if (t == 1) { icon = toupper(icon); }
    };
};

struct Bishop : Piece {
    Bishop(int t) : Piece('b', t) {
        if (t == 1) { icon = toupper(icon); }
    };
};

struct Knight : Piece {
    Knight(int t) : Piece('n', t) {
        if (t == 1) { icon = toupper(icon); }
    };
};

struct Rook : Piece {
    Rook(int t) : Piece('r', t) {
        if (t == 1) { icon = toupper(icon); }
    };
};

struct Queen : Piece {
    Queen(int t) : Piece('q', t) {
        if (t == 1) { icon = toupper(icon); }
    };
};

struct King : Piece {
    King(int t) : Piece('k', t) {
        if (t == 1) { icon = toupper(icon); }
    };
};