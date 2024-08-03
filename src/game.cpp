#include <SFML/Graphics.hpp>
#include "game.hpp"
#include <iostream>

namespace chess_game {
    Game::Game(sf::Color color_one, sf::Color color_two) : color_one(color_one), color_two(color_two) {};

    void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // apply the transform
        std::cout << "drawing\n";
        target.clear();

         for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                target.draw(squares[i][j]);
            }
        }
    }
    

    bool Game::load()
    {
        std::cout << "loading\n";
        for (int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                squares[i][j].setPosition(sf::Vector2f((i * 80.0f) + 80, (j * 80.0f) + 80));
                squares[i][j].setSize(sf::Vector2f(80.f, 80.f));
                squares[i][j].setFillColor((i + j) % 2 ? color_one : color_two);

            }
        }
        return true;
    }
}