#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>

namespace chess_game {
enum Color {
    Light,
    Dark
};

class Piece {
public :
    Color color;
    Piece();
    // int x;
    // int y;

private :

};
}

#endif // PIECE_HPP