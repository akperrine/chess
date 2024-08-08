#include <SFML/Graphics.hpp>
#include "game.hpp"
#include <iostream>
#include <memory>

namespace chess_game {
    Game::Game(sf::Color color_one, sf::Color color_two) : color_one(color_one), color_two(color_two) {
    //  selected(std::make_unique<Square>())
        font.loadFromFile("../../assets/SwanseaBold-D0ox.ttf");
        turn.setFont(font);
        turn.setCharacterSize(30);
        turn.setStyle(sf::Text::Regular);
        turn.setFillColor(sf::Color::White);
        turn.setPosition(275.f, 30.f);
    }

    bool Game::is_click_on_board(const sf::Event& event) const {
        // this statement checks if the click is inside the board: 1. check click inside right border 2. check click inside left border 3. check above bottom border 4. check bellow top border
        return event.mouseButton.x <= X_OFFSET_DRAW + (SQUARE_LENGTH * 8) 
        && event.mouseButton.x >= X_OFFSET_DRAW 
        && event.mouseButton.y <= Y_OFFSET_DRAW + (SQUARE_LENGTH * 8) 
        && event.mouseButton.y >= Y_OFFSET_DRAW;
    }

    void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // std::cout << "drawing\n";
        target.clear();
        sf::RectangleShape selected_square;
        int x_pos, y_pos;
         for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                Square currSquare = chess_board[i][j];
                target.draw(currSquare.square);
                
                if (currSquare.is_selected) {
                    x_pos = i;
                    y_pos = j;
                }

            }
        }

        selected_square.setPosition(sf::Vector2f((x_pos * SQUARE_LENGTH) + X_OFFSET_DRAW, (y_pos * SQUARE_LENGTH) + Y_OFFSET_DRAW));
        selected_square.setSize(sf::Vector2f(SQUARE_LENGTH, SQUARE_LENGTH));
        selected_square.setFillColor(sf::Color::Transparent);
        selected_square.setOutlineThickness(4);
        selected_square.setOutlineColor(sf::Color::Red);
        target.draw(selected_square);
        
        target.draw(turn);

        
    }
    

    bool Game::load()
    {
        std::cout << "loading\n";
        turn.setString("Turn: White");
        for (int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                chess_board[i][j].square.setPosition(sf::Vector2f((i * SQUARE_LENGTH) + X_OFFSET_DRAW, (j * SQUARE_LENGTH) + Y_OFFSET_DRAW));
                chess_board[i][j].square.setSize(sf::Vector2f(SQUARE_LENGTH, SQUARE_LENGTH));
                chess_board[i][j].square.setFillColor((i + j) % 2 ? color_one : color_two);
            }
        }
        return true;
    }

    void Game::select_piece(int x_cord, int y_cord) {
        int x_square = (x_cord - X_OFFSET_DRAW) / SQUARE_LENGTH;
        int y_square = (y_cord - Y_OFFSET_DRAW) / SQUARE_LENGTH;

        std::cout << "x cord: " << x_square << ", y cord: " << y_square << "\n";
        // selected->is_selected = true;

         for (int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                chess_board[i][j].is_selected = false;
            }
         }  
           
        chess_board[x_square][y_square].is_selected = true;
        std::cout << chess_board[x_square][y_square].is_selected << '\n';
        for (int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if (chess_board[x_square][y_square].is_selected == true) {
                    std::cout << x_square << " " << y_square << '\n';
                };
            }
         }  
        // selected->x = x_square;
        // selected->y = y_square;
        // selected->is_selected = false;
    }
}