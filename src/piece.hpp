#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>
#include "square.hpp"


namespace chess_game {
class Square;

class Piece {
public :
    virtual ~Piece() = default;
    virtual std::vector<std::pair<int, int>> get_moves(Square board[8][8], int x, int y) = 0;

    // std::vector<std::pair<int, int>> possible_moves;
    bool is_light;
    sf::Sprite piece;
private :

};
}

#endif // PIECE_HPP