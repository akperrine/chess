#ifndef PAWN_HPP
#define PAWN_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "piece.hpp"
#include "square.hpp"

namespace chess_game {

class Pawn : public Piece {
public :
    Pawn(bool is_light);
    std::vector<std::pair<int, int>> get_moves(Square board[8][8], int x, int y) const;
  
    sf::Texture rook_texture;
    bool first_move;
private :

};
}

#endif // PAWN_HPP