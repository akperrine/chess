#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include <string>
#include "piece.hpp"
#include "square.hpp"

namespace chess_game {

class Knight : public Piece {
public :
    Knight(bool is_light);
    std::vector<std::pair<int, int>> get_moves(Square board[8][8], int x, int y) ;
     std::vector<std::pair<int, int>> possible_moves;
    
    sf::Texture knight_texture;
private :

};
}

#endif // KNIGHT_HPP