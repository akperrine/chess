#include <SFML/Graphics.hpp>
#include "pawn.hpp"
#include <iostream>

namespace chess_game {
    Pawn::Pawn() {
        std::cout << "Entering Pawn constructor\n";
        if (!dark_rook_texture.loadFromFile("../../src/assets/white_pawn.png")) {
    std::cout << "Error loading texture\n";
    }
        std::cout << "Creating class";
        // dark_rook_texture.loadFromFile("../../src/assets/white_pawn.png");
        piece.setTexture(dark_rook_texture);
    };
}