#include <SFML/Graphics.hpp>
#include "rook.hpp"
#include <iostream>

namespace chess_game {
    Rook::Rook(bool is_light) {
        if (is_light) {
            std::cout << "Entering light pawn constructor\n";
            Piece::is_light = true;
            if (!rook_texture.loadFromFile("../../src/assets/white_rook.png")) {
                std::cout << "Error loading light pawn texture\n";
            }    
        } else {
                std::cout << "Entering dark pawn constructor\n";
                Piece::is_light = false;
                if (!rook_texture.loadFromFile("../../src/assets/black_rook.png")) {
                std::cout << "Error loading dark pawn texture\n";
            }
        }
        std::cout << "Creating class";
        piece.setTexture(rook_texture);
    }

    std::vector<std::pair<int, int>> Rook::get_moves(Square board[8][8], int x, int y)  {
        std::vector<std::pair<int, int>> moves = std::vector<std::pair<int, int>>();
        int x_dirs[8] = {0, 1, 0, -1};
        int y_dirs[8] = {1, 0, -1, 0};

            for (int i = 0; i < 8; i++) {
                int a = x + x_dirs[i];
                int b = y + y_dirs[i];

                
                while (a >= 0 && a <= 7 && b >= 0 && b <= 7) {
                    if (board[a][b].piece) {
                        if(board[a][b].piece->is_light != is_light) {
                            moves.push_back(std::make_pair(a, b));
                        }
                        break;
                    } else {
                        moves.push_back(std::make_pair(a, b));
                    }
                    a += (1 * x_dirs[i]);
                    b += (1 * y_dirs[i]);
                }
            }
        return moves;
    }

    
}