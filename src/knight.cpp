#include <SFML/Graphics.hpp>
#include "knight.hpp"
#include <iostream>

namespace chess_game {
    Knight::Knight(bool is_light) {
        if (is_light) {
            std::cout << "Entering light pawn constructor\n";
            Piece::is_light = true;
            if (!knight_texture.loadFromFile("../../src/assets/white_knight.png")) {
                std::cout << "Error loading light pawn texture\n";
            }    
        } else {
                std::cout << "Entering dark pawn constructor\n";
                Piece::is_light = false;
                if (!knight_texture.loadFromFile("../../src/assets/black_knight.png")) {
                std::cout << "Error loading dark pawn texture\n";
            }
        }
        std::cout << "Creating class";
        piece.setTexture(knight_texture);
    }

    std::vector<std::pair<int, int>> Knight::get_moves(Square board[8][8], int x, int y)  {
        std::vector<std::pair<int, int>> moves = std::vector<std::pair<int, int>>();
        
        return moves;
    }
}