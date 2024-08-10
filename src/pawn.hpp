#ifndef PAWN_HPP
#define PAWN_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "piece.hpp"

namespace chess_game {

class Pawn : public Piece {
public :
    Pawn();
    // void set_sprite();
    
    sf::Texture dark_rook_texture;
    sf::Texture light_rook_texture;
private :

};
}

#endif // PAWN_HPP