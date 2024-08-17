#ifndef QUEEN_HPP
#define QUEEN_HPP

#include <string>
#include "piece.hpp"
#include "square.hpp"

namespace chess_game {

class Queen : public Piece {
public :
    Queen(bool is_light);
    std::vector<std::pair<int, int>> get_moves(Square board[8][8], int x, int y) ;
     std::vector<std::pair<int, int>> possible_moves;
    
    sf::Texture queen_texture;
private :

};
}

#endif // QUEEN_HPP