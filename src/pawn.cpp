#include <SFML/Graphics.hpp>
#include "pawn.hpp"
#include <iostream>

namespace chess_game {
    Pawn::Pawn(bool is_light) : first_move(true) {
        if (is_light) {
            std::cout << "Entering lightPawn constructor\n";
            Piece::is_light = true;
            if (!rook_texture.loadFromFile("../../src/assets/white_pawn.png")) {
                std::cout << "Error loading light pawn texture\n";
            }    
        } else {
                std::cout << "Entering dark Pawn constructor\n";
                Piece::is_light = false;
                if (!rook_texture.loadFromFile("../../src/assets/black_pawn.png")) {
                std::cout << "Error loading dark pawn texture\n";
            }
        }
        std::cout << "Creating class";
        // rook_texture.loadFromFile("../../src/assets/white_pawn.png");
        piece.setTexture(rook_texture);
    }

    std::vector<std::pair<int, int>> Pawn::get_moves(Square board[8][8], int x, int y)  {
        std::vector<std::pair<int, int>> moves = std::vector<std::pair<int, int>>();
        if (is_light) {
            if (first_move) {
                //TODO:
                 moves.push_back(std::make_pair(x, y+2));
            }
            std::cout<< "loading moves\n";
            
            moves.push_back(std::make_pair(x, y+1));
        } else {
            if (first_move) {
                //TODO:
                 moves.push_back(std::make_pair(x, y-2));
            }
            std::cout<< "loading moves\n";
            
            moves.push_back(std::make_pair(x, y-1));
        }
        return moves;
    }

    
}