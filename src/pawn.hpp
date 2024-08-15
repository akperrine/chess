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
    std::vector<std::pair<int, int>> get_moves(Square board[8][8], int x, int y) ;
     std::vector<std::pair<int, int>> possible_moves;

  
    sf::Texture rook_texture;
private :

};
}

#endif // PAWN_HPP