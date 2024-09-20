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
        if (y + 2 <= 7) {
            if (x + 1 <= 7 && !(board[x+1][y+2].piece && board[x+1][y+2].piece->is_light == is_light)) {
                moves.push_back(std::make_pair(x + 1, y + 2));
            }
            if (x - 1 >= 0 && !(board[x-1][y+2].piece && board[x-1][y+2].piece->is_light == is_light)) {
                moves.push_back(std::make_pair(x - 1, y + 2));
            }
        }
        if (y - 2 >= 0) {
            if (x + 1 <= 7 && !(board[x+1][y-2].piece && board[x+1][y-2].piece->is_light == is_light)) {
                moves.push_back(std::make_pair(x + 1, y - 2));
            }
            if (x - 1 >= 0 && !(board[x-1][y-2].piece && board[x-1][y-2].piece->is_light == is_light)) {
                moves.push_back(std::make_pair(x - 1, y - 2));
            }
        }
        if (x + 2 <= 7) {
            if (y + 1 <= 7 && !(board[x+2][y+1].piece && board[x+2][y+1].piece->is_light == is_light)) {
                moves.push_back(std::make_pair(x + 2, y + 1));
            }
            if (y - 1 >= 0 && !(board[x+2][y-1].piece && board[x+2][y-1].piece->is_light == is_light)) {
                moves.push_back(std::make_pair(x + 2, y - 1));
            }
        }
        if (x - 2 >= 0) {
            if (y + 1 <= 7 && !(board[x-2][y+1].piece && board[x-2][y+1].piece->is_light == is_light)) {
                moves.push_back(std::make_pair(x - 2 , y + 1));
            }
            if (y - 1 >= 0 && !(board[x-2][y-1].piece && board[x-2][y-1].piece->is_light == is_light)) {
                moves.push_back(std::make_pair(x - 2, y - 1));
            }
        }
        
        return moves;
    }
}