#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics.hpp>
#include "piece.hpp"

namespace chess_game {
class Square {
public :
    Square();
    int x;
    int y;
    bool is_selected;
    sf::RectangleShape square;
    Piece* piece;
private :

};
}

#endif // SQUARE_HPP