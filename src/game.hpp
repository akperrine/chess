#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>


namespace chess_game {

class Game : public sf::Drawable{
public :
    Game(sf::Color color_one, sf::Color color_two);
    bool load();
   
private :
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Color color_one;
    sf::Color color_two;
    sf::RectangleShape squares[8][8];
};

} // chess_game

#endif // GAME_HPP