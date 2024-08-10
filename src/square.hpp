#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics.hpp>
#include "piece.hpp"

namespace chess_game {
class Square {
public :
    Square();
    // not sure if these delete constructors are necessary
    Square(const Square&) = delete;  // Delete copy constructor
    Square& operator=(const Square&) = delete; 

    int x;
    int y;
    bool is_selected;
    sf::RectangleShape square;
    std::unique_ptr<Piece> piece;
private :

};
}

#endif // SQUARE_HPP