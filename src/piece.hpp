#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>

namespace chess_game {

class Piece {
public :
    virtual ~Piece() = default;

    bool is_light;
    sf::Sprite piece;
    // int x;
    // int y;

private :

};
}

#endif // PIECE_HPP