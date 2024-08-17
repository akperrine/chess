#ifndef ROOK_HPP
#define ROOK_HPP

#include <string>
#include "piece.hpp"
#include "square.hpp"

namespace chess_game {

class Rook : public Piece {
public :
    Rook(bool is_light);
    std::vector<std::pair<int, int>> get_moves(Square board[8][8], int x, int y) ;
     std::vector<std::pair<int, int>> possible_moves;
    
    sf::Texture rook_texture;
private :

};
}

#endif // ROOK_HPP