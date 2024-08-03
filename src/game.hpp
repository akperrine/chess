#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>


namespace chess_game {

class Game : public sf::Drawable{
public :
    Game(sf::Color color_one, sf::Color color_two);
    bool load();
    bool is_click_on_board(const sf::Event& event) const;
    //TODO: Draw selected piece
   
    const int X_OFFSET_DRAW = 80;
    const int Y_OFFSET_DRAW = 80;
    float const SQUARE_LENGTH = 80.0f;
private :
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    bool selected;
    sf::Color color_one;
    sf::Color color_two;
    sf::RectangleShape chess_board[8][8];
};
} // chess_game

#endif // GAME_HPP