#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    std::cout << "Starting Chess Game\n";

    auto window = sf::RenderWindow{ { 1220u, 1080u }, "Chess Game"};
    window.setFramerateLimit(144);

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

        window.clear();
        window.display();
    }
    return 0;
}