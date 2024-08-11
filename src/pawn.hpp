#ifndef PAWN_HPP
#define PAWN_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "piece.hpp"

namespace chess_game {

class Pawn : public Piece {
public :
    Pawn(bool is_light);
    std::vector<std::pair<int, int>> get_moves(int x, int y) const override;
  
    sf::Texture rook_texture;
private :

};
}

#endif // PAWN_HPP