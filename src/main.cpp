#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
using namespace chess_game;

int main() {
    std::cout << "Starting Chess Game\n";

    auto window = sf::RenderWindow{ { 1220u, 1080u }, "Chess Game"};
    window.setFramerateLimit(144);
    chess_game::Game chess_game = chess_game::Game();
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

            sf::CircleShape shape(50.f);
            shape.setFillColor(sf::Color(150, 50, 250));
        }

        // window.clear();
        window.draw(chess_game);
        window.display();
    }
    return 0;
}
