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
            std::cout<<"checking king "<< is_light<< "\n";
            // found this idea that was way more clever than my switch statement
            int x_dirs[8] = {0, 1, 1, 1, 0, -1, -1, -1};
            int y_dirs[8] = {1, 1, 0, -1, -1, -1, 0, 1};

            for (int i = 0; i < 8; i++) {
                if (x + x_dirs[i] < 0 || x + x_dirs[i] > 7 ) {
                    continue;
                } else if (y + y_dirs[i] < 0 || y + y_dirs[i] > 7) {
                    continue;
                } else if ((board[x + x_dirs[i]][y + y_dirs[i]].piece && board[x+x_dirs[i]][y+y_dirs[i]].piece->is_light == is_light)) {
                    continue;
                } else {
                    moves.push_back(std::make_pair(x + x_dirs[i], y + y_dirs[i]));
                }

            }
            

            // if(x > 0 && !(board[x-1][y].piece && board[x-1][y].piece->is_light == is_light)) {
            //     moves.push_back(std::make_pair(x-1,y));
            // }
            // if(x < 7 && !(board[x+1][y].piece && board[x+1][y].piece->is_light == is_light)) {
            //     moves.push_back(std::make_pair(x+1,y));
            // }
            // if(y > 0 && !(board[x][y-1].piece && board[x][y-1].piece->is_light == is_light)) {
            //     moves.push_back(std::make_pair(x,y-1));
            // }
            // if(x < 7 && !(board[x][y+1].piece && board[x][y+1].piece->is_light == is_light)) {
            //     moves.push_back(std::make_pair(x,y+1));
            // }

            // // diaganol moves
            // if(x > 0 && y > 0 && !(board[x-1][y-1].piece && board[x-1][y-1].piece->is_light == is_light)) {
            //     moves.push_back(std::make_pair(x-1,y));
            // }
            // if(x < 7 && !(board[x+1][y].piece && board[x+1][y].piece->is_light == is_light)) {
            //     moves.push_back(std::make_pair(x+1,y));
            // }
            // if(y > 0 && !(board[x][y-1].piece && board[x][y-1].piece->is_light == is_light)) {
            //     moves.push_back(std::make_pair(x,y-1));
            // }
            // if(x < 7 && !(board[x][y+1].piece && board[x][y+1].piece->is_light == is_light)) {
            //     moves.push_back(std::make_pair(x,y+1));
            // }
        
        return moves;
    }

    
}