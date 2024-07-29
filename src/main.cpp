#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    std::cout << "Starting Chess Game\n";
    std::vector<int> dimensions = {100, 200};
    // label: 
        sf::RenderWindow(sf::VideoMode(sf::Vector2u(800, 600)), "Chess Game");
    // sf::RenderWindow window(sf::Vector2u(800, 600)), "my window");
    return 0;
}