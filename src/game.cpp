#include <SFML/Graphics.hpp>
#include "game.hpp"
#include <iostream>
#include <memory>

namespace chess_game {
    Game::Game(sf::Color color_one, sf::Color color_two) : color_one(color_one), color_two(color_two), selected(std::make_unique<Piece>()) {}

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

         for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                target.draw(chess_board[i][j]);
            }
        }
        if (selected->x != -1 && selected->y != -1) {
            sf::RectangleShape selected_square;
            selected_square.setPosition(sf::Vector2f((selected->x * SQUARE_LENGTH) + X_OFFSET_DRAW, (selected->y * SQUARE_LENGTH) + Y_OFFSET_DRAW));
            selected_square.setSize(sf::Vector2f(SQUARE_LENGTH, SQUARE_LENGTH));
            selected_square.setFillColor(sf::Color::Transparent);
            selected_square.setOutlineThickness(4);
            selected_square.setOutlineColor(sf::Color::Red);
            target.draw(selected_square);
        }
    }
    

    bool Game::load()
    {
        std::cout << "loading\n";
        for (int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                chess_board[i][j].setPosition(sf::Vector2f((i * SQUARE_LENGTH) + X_OFFSET_DRAW, (j * SQUARE_LENGTH) + Y_OFFSET_DRAW));
                chess_board[i][j].setSize(sf::Vector2f(SQUARE_LENGTH, SQUARE_LENGTH));
                chess_board[i][j].setFillColor((i + j) % 2 ? color_one : color_two);
            }
        }
        return true;
    }

    void Game::select_piece(int x_cord, int y_cord) {
        int x_square = (x_cord - X_OFFSET_DRAW) / SQUARE_LENGTH;
        int y_square = (y_cord - Y_OFFSET_DRAW) / SQUARE_LENGTH;

        std::cout << "x cord: " << x_square << ", y cord: " << y_square << "\n";
        selected->is_selected = true;
        selected->x = x_square;
        selected->y = y_square;
        selected->is_selected = false;
    }
}