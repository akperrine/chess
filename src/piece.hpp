#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>

namespace chess_game {

class Piece {
public :
    virtual ~Piece() = default;
    virtual std::vector<std::pair<int, int>> get_moves(int x, int y) const = 0;

    std::vector<std::pair<int, int>> possible_moves;
    bool is_light;
    sf::Sprite piece;
private :

};
}

#endif // PIECE_HPP