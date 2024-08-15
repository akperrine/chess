#include <SFML/Graphics.hpp>
#include "king.hpp"
#include <iostream>

namespace chess_game {
    King::King(bool is_light) {
        if (is_light) {
            std::cout << "Entering light king constructor\n";
            Piece::is_light = true;
            if (!king_texture.loadFromFile("../../src/assets/white_king.png")) {
                std::cout << "Error loading light king texture\n";
            }    
        } else {
                std::cout << "Entering dark King constructor\n";
                Piece::is_light = false;
                if (!king_texture.loadFromFile("../../src/assets/black_king.png")) {
                std::cout << "Error loading dark pawn texture\n";
            }
        }
        std::cout << "Creating class";
        // pawn_texture.loadFromFile("../../src/assets/white_pawn.png");
        piece.setTexture(king_texture);
    }

    std::vector<std::pair<int, int>> King::get_moves(Square board[8][8], int x, int y)  {
        std::vector<std::pair<int, int>> moves = std::vector<std::pair<int, int>>();
        if (is_light) {
            
        } else {
            
        }
        return moves;
    }

    
}