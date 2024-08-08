#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics.hpp>

namespace chess_game {
class Square {
public :
    Square();
    int x;
    int y;
    bool is_selected;
    sf::RectangleShape square;
private :

};
}

#endif // SQUARE_HPP