#include <SFML/Graphics.hpp>
#include "pawn.hpp"
#include <iostream>

namespace chess_game {
    Pawn::Pawn(bool is_light) {
        if (is_light) {
            std::cout << "Entering lightPawn constructor\n";
            Piece::is_light = true;
            if (!pawn_texture.loadFromFile("../../src/assets/white_pawn.png")) {
                std::cout << "Error loading light pawn texture\n";
            }    
        } else {
                std::cout << "Entering dark Pawn constructor\n";
                Piece::is_light = false;
                if (!pawn_texture.loadFromFile("../../src/assets/black_pawn.png")) {
                std::cout << "Error loading dark pawn texture\n";
            }
        }
        std::cout << "Creating class";
        // pawn_texture.loadFromFile("../../src/assets/white_pawn.png");
        piece.setTexture(pawn_texture);
    }

    std::vector<std::pair<int, int>> Pawn::get_moves(Square board[8][8], int x, int y)  {
        std::vector<std::pair<int, int>> moves = std::vector<std::pair<int, int>>();
        if (is_light && y != 7) {
            if (y == 1) {
                if(!board[x][y+2].piece && !board[x][y+1].piece) {
                 moves.push_back(std::make_pair(x, y+2));
                }
            }
            if(!board[x][y+1].piece) {
                moves.push_back(std::make_pair(x, y+1));
            }
            if(x+1 < 8 && board[x +1][y+1].piece && board[x +1][y+1].piece->is_light == false) {
                moves.push_back(std::make_pair(x+1, y+1));
            } 
            if(x-1 >= 0 && board[x -1][y+1].piece && board[x -1][y+1].piece->is_light == false) {
                moves.push_back(std::make_pair(x-1, y+1));
            } 
        } else if (y != 0) {
            if (y == 6) {
                if(!board[x][y-2].piece && !board[x][y-1].piece) {
                 moves.push_back(std::make_pair(x, y-2));
                }
            }
            if(!board[x][y-1].piece) {
                moves.push_back(std::make_pair(x, y-1));
            }
            if(x+1 < 8 && board[x +1][y-1].piece && board[x +1][y-1].piece->is_light == true) {
                moves.push_back(std::make_pair(x+1, y-1));
            } 
            if(x-1 >= 0 && board[x -1][y-1].piece && board[x -1][y-1].piece->is_light == true) {
                moves.push_back(std::make_pair(x-1, y-1));
            } 
        }
        return moves;
    }

    
}