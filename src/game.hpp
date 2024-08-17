#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "piece.hpp"
#include "square.hpp"
#include "pawn.hpp"
#include "king.hpp"
#include "queen.hpp"


namespace chess_game {

class Game : public sf::Drawable{
public :
    Game(sf::Color color_one, sf::Color color_two);
    bool load();
    bool is_click_on_board(const sf::Event& event) const;
    void select_piece(int x, int y);

    
    const int X_OFFSET_DRAW = 70;
    const int Y_OFFSET_DRAW = 90;
    float const SQUARE_LENGTH = 65.0f;
private :
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void move_piece(std::pair<int,int> from_square, std::pair<int,int> to_square);
    void undo_move();
    bool check_if_check();

    sf::Color color_one;
    sf::Color color_two;
    Square chess_board[8][8];
    sf::Font font;
    sf::Text turn_text;
    bool is_light_turn;
    std::vector<std::pair<int, int>> possible_moves;
    std::vector<std::unique_ptr<Pawn>> pawns;
    bool is_light_check;
    bool is_dark_check;
    bool is_game_over;
    std::pair<int,int> selected_piece;
};
} // chess_game

#endif // GAME_HPP