#ifndef KING_HPP
#define KING_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "piece.hpp"
#include "square.hpp"

namespace chess_game {

class King : public Piece {
public :
    King(bool is_light);
    std::vector<std::pair<int, int>> get_moves(Square board[8][8], int x, int y) ;
     std::vector<std::pair<int, int>> possible_moves;

    
    sf::Texture king_texture;
private :

};
}

#endif // KING_HPP