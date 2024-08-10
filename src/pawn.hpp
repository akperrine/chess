#ifndef PAWN_HPP
#define PAWN_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "piece.hpp"

namespace chess_game {

class Pawn : public Piece {
public :
    Pawn(bool is_light);
    // void set_sprite();
    
    bool is_light;
    sf::Texture rook_texture;
private :

};
}

#endif // PAWN_HPP