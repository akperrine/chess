#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>


namespace chess_game {

class Game : public sf::Drawable {
public :
    Game();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const; 
private :
};

} // chess_game

#endif // GAME_HPP