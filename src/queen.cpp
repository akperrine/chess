#include <SFML/Graphics.hpp>
#include "queen.hpp"
#include <iostream>

namespace chess_game {
    Queen::Queen(bool is_light) {
        if (is_light) {
            std::cout << "Entering light queen constructor\n";
            Piece::is_light = true;
            if (!queen_texture.loadFromFile("../../src/assets/white_queen.png")) {
                std::cout << "Error loading light queen texture\n";
            }    
        } else {
                std::cout << "Entering dark queen constructor\n";
                Piece::is_light = false;
                if (!queen_texture.loadFromFile("../../src/assets/black_queen.png")) {
                std::cout << "Error loading dark pawn texture\n";
            }
        }
        std::cout << "Creating class";
        // pawn_texture.loadFromFile("../../src/assets/white_pawn.png");
        piece.setTexture(queen_texture);
    }

    std::vector<std::pair<int, int>> Queen::get_moves(Square board[8][8], int x, int y)  {
        std::vector<std::pair<int, int>> moves = std::vector<std::pair<int, int>>();

            // found this idea that was way more clever than my switch statement
            int x_dirs[8] = {0, 1, 1, 1, 0, -1, -1, -1};
            int y_dirs[8] = {1, 1, 0, -1, -1, -1, 0, 1};

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