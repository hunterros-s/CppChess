#include <string>

struct Piece
{
    static bool can_move(std::string, std::string) {
        return false;
    }
};

struct Pawn : Piece
{
    static bool can_move(std::string A, std::string B) {
        
    }
};