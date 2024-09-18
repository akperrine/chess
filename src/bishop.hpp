#ifndef BISHOP_HPP
#define BISHOP_HPP

#include <string>
#include "piece.hpp"
#include "square.hpp"

namespace chess_game {

class Bishop : public Piece {
public :
    Bishop(bool is_light);
    std::vector<std::pair<int, int>> get_moves(Square board[8][8], int x, int y) ;
     std::vector<std::pair<int, int>> possible_moves;
    
    sf::Texture bishop_texture;
private :

};
}

#endif // BISHOP_HPP