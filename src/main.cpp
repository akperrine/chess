#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"
using namespace chess_game;

int main() {
    std::cout << "Starting Chess Game\n";

    auto window = sf::RenderWindow{ { 800u, 800u }, "Chess Game"};
    window.setFramerateLimit(144);
    chess_game::Game chess(sf::Color::Blue, sf::Color::White);
    chess.load();

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            switch (event.type) 
            {
                case sf::Event::Closed: {
                    window.close();
                    break;
                }
                case sf::Event::KeyPressed: {
                    std::cout << "Key Press\n";
                }
                case sf::Event::MouseButtonPressed: {
                    std::cout << "Clicked\n";
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        std::cout << "the Left button was pressed" << std::endl;
                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    }
                }
                default: {
                    break;
                }
            }
        }
        // std::cout << "about to draw\n";
        window.draw(chess);
        // std::cout << "drawn\n";
        window.display();
    }

    return 0;
}
