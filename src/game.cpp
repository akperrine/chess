#include <SFML/Graphics.hpp>
#include "game.hpp"
#include <iostream>
#include <memory>


namespace chess_game {
    Game::Game(sf::Color color_one, sf::Color color_two) : color_one(color_one), color_two(color_two) {
    //  selected(std::make_unique<Square>())
        font.loadFromFile("../../src/assets/SwanseaBold-D0ox.ttf");
        turn_text.setFont(font);
        turn_text.setCharacterSize(30);
        turn_text.setStyle(sf::Text::Regular);
        turn_text.setFillColor(sf::Color::White);
        turn_text.setPosition(275.f, 30.f);
        game_over_text.setFont(font);
        game_over_text.setCharacterSize(30);
        game_over_text.setStyle(sf::Text::Regular);
        game_over_text.setFillColor(sf::Color::White);
        game_over_text.setPosition(275.f, 30.f);
        is_light_turn = false;
        light_left_castle = true;
        light_right_castle = true;
        dark_left_castle = true;
        dark_right_castle = true;
        is_game_over = false;
        is_light_won = true;

        // initialize light pawns on board
        // for (int i = 0; i < 8; ++i) {
        //     chess_board[i][1].piece = std::make_unique<Pawn>(true);
        // }

        //initialize dark pawns on board
        // for (int i = 0; i < 8; ++i) {
        //     chess_board[i][6].piece = std::make_unique<Pawn>(false);  
        // }
        // testing pawns
        chess_board[1][6].piece = std::make_unique<Pawn>(true);
        chess_board[6][2].piece = std::make_unique<Pawn>(false);
        chess_board[3][2].piece = std::make_unique<Queen>(false);
        chess_board[7][1].piece = std::make_unique<Queen>(false);

        // initialize rooks on board
        chess_board[0][0].piece = std::make_unique<Rook>(true);
        chess_board[7][0].piece = std::make_unique<Rook>(true);
        chess_board[0][7].piece = std::make_unique<Rook>(false);
        chess_board[7][7].piece = std::make_unique<Rook>(false);

        // initialize bishops on board
        chess_board[2][0].piece = std::make_unique<Bishop>(true);
        chess_board[5][0].piece = std::make_unique<Bishop>(true);
        chess_board[2][7].piece = std::make_unique<Bishop>(false);
        chess_board[5][7].piece = std::make_unique<Bishop>(false);

        // initialize knights on board
        chess_board[1][0].piece = std::make_unique<Knight>(true);
        chess_board[6][0].piece = std::make_unique<Knight>(true);
        chess_board[1][7].piece = std::make_unique<Knight>(false);
        chess_board[6][7].piece = std::make_unique<Knight>(false);

        // initialize kings on board
        chess_board[4][0].piece = std::make_unique<King>(true);
        chess_board[4][7].piece = std::make_unique<King>(false);

        // initialize queens on board
        chess_board[3][0].piece = std::make_unique<Queen>(true);
        chess_board[3][7].piece = std::make_unique<Queen>(false);
    }

    bool Game::is_click_on_board(const sf::Event& event) const {
        // this statement checks if the click is inside the board: 1. check click inside right border 2. check click inside left border 3. check above bottom border 4. check bellow top border
        return event.mouseButton.x <= X_OFFSET_DRAW + (SQUARE_LENGTH * 8) 
        && event.mouseButton.x >= X_OFFSET_DRAW 
        && event.mouseButton.y <= Y_OFFSET_DRAW + (SQUARE_LENGTH * 8) 
        && event.mouseButton.y >= Y_OFFSET_DRAW;
    }

    void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.clear();
        sf::RectangleShape selected_square;
        int x_pos, y_pos;
         for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                const Square& currSquare = chess_board[i][j];
                target.draw(currSquare.square);
                
                if (currSquare.is_selected) {
                    x_pos = i;
                    y_pos = j;
                }

                if (currSquare.piece) {
                target.draw(currSquare.piece->piece);  // Draw the piece if it exists
                }
            }
        }

        for (std::pair<int, int> pair : possible_moves) {
            sf::RectangleShape  temp_rec;
            temp_rec.setPosition(sf::Vector2f((pair.first * SQUARE_LENGTH) + X_OFFSET_DRAW, (pair.second * SQUARE_LENGTH) + Y_OFFSET_DRAW));
            temp_rec.setSize(sf::Vector2f(SQUARE_LENGTH, SQUARE_LENGTH));
            temp_rec.setFillColor(sf::Color(67, 17, 43, 128));
            target.draw(temp_rec);
        }

        selected_square.setPosition(sf::Vector2f((x_pos * SQUARE_LENGTH) + X_OFFSET_DRAW, (y_pos * SQUARE_LENGTH) + Y_OFFSET_DRAW));
        selected_square.setSize(sf::Vector2f(SQUARE_LENGTH, SQUARE_LENGTH));
        selected_square.setFillColor(sf::Color::Transparent);
        selected_square.setOutlineThickness(4);
        selected_square.setOutlineColor(sf::Color::Red);
        target.draw(selected_square);

     

        if(is_game_over) {
           
            target.draw(game_over_text);
        } else {
            target.draw(turn_text);
        }
    }
    

    bool Game::load()
    {
        std::cout << "loading\n";
        if (is_light_turn) {
            turn_text.setString("Turn: Light");
        } else {
            turn_text.setString("Turn: Dark");
        }

        for (int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                chess_board[i][j].square.setPosition(sf::Vector2f((i * SQUARE_LENGTH) + X_OFFSET_DRAW, (j * SQUARE_LENGTH) + Y_OFFSET_DRAW));
                chess_board[i][j].square.setSize(sf::Vector2f(SQUARE_LENGTH, SQUARE_LENGTH));
                chess_board[i][j].square.setFillColor((i + j) % 2 ? color_one : color_two);
                chess_board[i][j].x = i;
                chess_board[i][j].y = j;
                // draw chess pieces if piece present
                if (chess_board[i][j].piece) {
                    chess_board[i][j].piece->piece.setPosition(sf::Vector2f((i * SQUARE_LENGTH) + X_OFFSET_DRAW, (j * SQUARE_LENGTH) + Y_OFFSET_DRAW));
                    chess_board[i][j].piece->piece.setScale(1.0, 1.0);
                }
            }

        } 
            
        return true;
    }

    void Game::select_piece(int x_cord, int y_cord) {
        if (!is_game_over) {

            int x_square = (x_cord - X_OFFSET_DRAW) / SQUARE_LENGTH;
            int y_square = (y_cord - Y_OFFSET_DRAW) / SQUARE_LENGTH;

            std::cout << "x cord: " << x_square << ", y cord: " << y_square << "\n";
            
            // needs to be refactored
            std::pair<int,int> selected;
            for (int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {  
                    if(chess_board[i][j].is_selected) {
                        selected.first = i;
                        selected.second = j;
                    }
                }
            }  
            
            std::pair<int, int> target_move = {x_square, y_square};
            auto movable_square = std::find(possible_moves.begin(), possible_moves.end(), target_move);
            if(movable_square != possible_moves.end()) {
                // std::cout<< "found move\n";
                move_piece(selected, target_move);

                possible_moves.clear();
            for (int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    chess_board[i][j].is_selected = false;
                }
            }  
            }
            //  else {

            possible_moves.clear();
            for (int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    chess_board[i][j].is_selected = false;
                }
            }  

            std::vector<std::pair<int,int>> castle_moves = check_for_castle(target_move);


            Square& chosen_square = chess_board[x_square][y_square];
            if (chosen_square.piece && chosen_square.piece->is_light == is_light_turn) {
                chess_board[x_square][y_square].is_selected = true;
                
                        // std::cout<< "this is possible \n";
                        // Game::possible_moves.push_back(std::make_pair(x_square, y_square));
                    
                possible_moves = chess_board[x_square][y_square].piece->get_moves(chess_board, x_square, y_square);

                // add moves for castle
                for (auto coords : castle_moves) {
                    possible_moves.push_back(coords);
                }
            }   
        }
    }

    void Game::move_piece(std::pair<int,int> from_coords, std::pair<int,int> to_coords) {
        // std::cout<< "moving from "<< from_coords.first << " " << from_coords.second << " to " <<to_coords.first << " " << to_coords.second << "\n";
        
        if(!move_castle(from_coords, to_coords)) {

        Square& start_square = chess_board[from_coords.first][from_coords.second];
        Square& desitination_square = chess_board[to_coords.first][to_coords.second];

        std::unique_ptr<Piece> backupPiece = std::move(desitination_square.piece);
        // std::cout<< start_square.piece->is_light <<'\n';
        desitination_square.piece = std::move(start_square.piece);
        // move_piece_to_square(start_square, desitination_square);

        // std::cout<< desitination_square.x << " " << desitination_square.y << "\n";
        // start_square.piece.reset();
        bool is_check = check_if_check();
        if(is_check) {
            start_square.piece = std::move(desitination_square.piece);
            desitination_square.piece = std::move(backupPiece);
            
            return;
        } else {
            check_moved_castle_pieces(from_coords);
        }
        pawn_to_queen(to_coords);
        


        desitination_square.piece->piece.setPosition(sf::Vector2f((desitination_square.x * SQUARE_LENGTH) + X_OFFSET_DRAW, (desitination_square.y * SQUARE_LENGTH) + Y_OFFSET_DRAW));
        }

        is_light_turn = !is_light_turn;
        if (is_light_turn) {
            turn_text.setString("Turn: Light");
        } else {
            turn_text.setString("Turn: Dark");
        }

        is_game_over = check_if_check_mate(); 

        if (is_light_won) {
                game_over_text.setString("Light WINS!!!!!");
            } else {
                game_over_text.setString("DARK WINs!!!!");
            }
    }

    void Game::move_piece_to_square(Square& from_square, Square& to_square) {
         if (from_square.piece) {
            to_square.piece = std::move(from_square.piece);

            to_square.piece->piece.setPosition(sf::Vector2f(
            (to_square.x * SQUARE_LENGTH) + X_OFFSET_DRAW, 
            (to_square.y * SQUARE_LENGTH) + Y_OFFSET_DRAW
            ));
        }
    };

    bool Game::check_if_check() {
        std::pair<int,int> king_coords = get_turns_king_coords();
        possible_moves.clear();

        // for (int i = 0; i < 8; i++) {
        //     for(int j = 0; j < 8; j++) {
        //         if (chess_board[i][j].piece && chess_board[i][j].piece->is_light == is_light_turn && dynamic_cast<King*>(chess_board[i][j].piece.get())){
        //             king_coords.first = i;
        //             king_coords.second = j;
        //             // std::cout<<"found the king "<<king_coords.first<<" "<<king_coords.second<<"\n";
        //         }
        //     }
        // }

        return is_square_attacked(king_coords);
    }

    bool Game::check_if_check_mate() {
        if (check_if_check()) {
            std::pair<int,int> king_coords = get_turns_king_coords();
            if (chess_board[king_coords.first][king_coords.second].piece) {
                std::vector<std::pair<int,int>> possible_opponent_moves = get_possible_moves(false);

                std::vector<std::pair<int,int>> possible_king_moves = chess_board[king_coords.first][king_coords.second].piece->get_moves(chess_board, king_coords.first, king_coords.second);
                for (auto move : possible_king_moves) {
                    // std::cout<<"found the king options "<<move.first<<" "<<move.second<<"\n"; 
                    
                    std::unique_ptr<Piece> tempPiece = std::move(chess_board[move.first][move.second].piece);
                     chess_board[move.first][move.second].piece = std::move(chess_board[king_coords.first][king_coords.second].piece);
                    bool king_move_attacked = is_square_attacked(move);
                    
                        chess_board[king_coords.first][king_coords.second].piece = std::move(chess_board[move.first][move.second].piece);
                        chess_board[move.first][move.second].piece = std::move(tempPiece);
                    if (!king_move_attacked) {
                        std::cout<<" not attack, check mate proven in king moves = false ***** "<<move.first<<" "<<move.second<<"\n"; 
                        return false;
                    } 
        // move_piece_to_square(start_square, desitination_square);
                }

                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        if(chess_board[i][j].piece && chess_board[i][j].piece->is_light == is_light_turn) {
                            std::cout<<" coords of checking piece "<< i<<j<<"\n";
                            std::vector<std::pair<int,int>> piece_moves = chess_board[i][j].piece->get_moves(chess_board, i, j);

                            for (auto move : piece_moves) {
                                   std::unique_ptr<Piece> tempPiece = std::move(chess_board[move.first][move.second].piece);
                                    chess_board[move.first][move.second].piece = std::move(chess_board[i][j].piece);
                                    // bool piece_attacked = is_square_attacked(king_coords);
                                    bool piece_attacked = check_if_check();
                                    std::cout<<"is king still attacked "<<piece_attacked<<"\n";
                                        chess_board[i][j].piece = std::move(chess_board[move.first][move.second].piece);
                                        chess_board[move.first][move.second].piece = std::move(tempPiece);
                                    if (!piece_attacked) {
                                        std::cout<<" not attack, check mate = false ***** "<<move.first<<" "<<move.second<<"\n"; 
                                        return false;
                                    } 
                            }
                          

                        }
                        // is_square_attacked(king_coords);
                    }
                }

                return true;
            }

            std::cout<< "is in check. Could be check mate\n";
            
            for (int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    if (chess_board[i][j].piece && chess_board[i][j].piece->is_light == is_light_turn && dynamic_cast<King*>(chess_board[i][j].piece.get())){
                    king_coords.first = i;
                    king_coords.second = j;
                        // std::cout<<"found the king "<<king_coords.first<<" "<<king_coords.second<<"\n";
                    }
                }
            }
        } 

        return false;
    }

    std::pair<int,int> Game::get_turns_king_coords() {
        std::pair<int,int> king_coords;
        possible_moves.clear();

        for (int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if (chess_board[i][j].piece && chess_board[i][j].piece->is_light == is_light_turn && dynamic_cast<King*>(chess_board[i][j].piece.get())){
                    king_coords.first = i;
                    king_coords.second = j;
                    // std::cout<<"found the king "<<king_coords.first<<" "<<king_coords.second<<"\n";
                }
            }
        }
        return king_coords;
    }

    bool Game::is_square_attacked(std::pair<int,int> attacked_coords) {
        
         possible_moves = get_possible_moves(false);
        //  
        //   for (int i = 0; i < 8; i++) {
        //     for(int j = 0; j < 8; j++) {
        //         if (chess_board[i][j].piece && chess_board[i][j].piece->is_light != is_light_turn) {
        //             auto piece_moves = chess_board[i][j].piece->get_moves(chess_board, i, j);
        //             possible_moves.insert(possible_moves.end(), piece_moves.begin(),piece_moves.end());
        //         }
        //     }
        // }  
        std::cout<< "attccked coords "<<attacked_coords.first<< " " << attacked_coords.second<< "\n";
        for (auto i : possible_moves) {
            // std::cout<< "x move" <<i.first <<" y move" << i.second<< '\n';
            // std::cout<<"king coords "<<attacked_coords.first<<" "<<attacked_coords.second<<"\n";
            if(i == attacked_coords) {
                // std::cout<< "check\n";
                possible_moves.clear();
                return true;
            }
        }

        // std::cout<< "not check\n";
        possible_moves.clear();
         return false;
    }

    std::vector<std::pair<int,int>> Game::get_possible_moves(bool same_color) {
        std::vector<std::pair<int,int>> moves_to_return;
        for (int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if (chess_board[i][j].piece && (same_color == (chess_board[i][j].piece->is_light == is_light_turn))) {
                    auto piece_moves = chess_board[i][j].piece->get_moves(chess_board, i, j);
                    moves_to_return.insert(moves_to_return.end(), piece_moves.begin(),piece_moves.end());
                }
            }
        } 
        return moves_to_return;
    }


    void Game::pawn_to_queen(std::pair<int,int> new_coords) {
        Square& curr_square = chess_board[new_coords.first][new_coords.second];
        //check if pawn 
        if (curr_square.piece && dynamic_cast<Pawn*>(curr_square.piece.get())) {
            //check dark pawn reach end
            if (new_coords.second == 0 && !curr_square.piece->is_light) {
                // std::cout<<"this is a DARK piece to be queened\n";
                curr_square.piece = std::make_unique<Queen>(false);

                //check dark pawn reach end
            } else if (new_coords.second == 7 && curr_square.piece->is_light) {
                // std::cout<<"this is a LIGHT piece to be queened\n";
                curr_square.piece = std::make_unique<Queen>(true);
            }
        }  
    }

    bool Game::move_castle(std::pair<int,int> first_coords, std::pair<int,int> second_coords) {
        Square& first_square = chess_board[first_coords.first][first_coords.second];
        Square& second_square = chess_board[second_coords.first][second_coords.second];
        // all other castle moves checked during select move phase
        if (is_light_turn) {
            if (second_square.piece && second_square.piece->is_light && second_coords.first == 0) {
                // std::cout<<"hit castle";
                move_piece_to_square(first_square, chess_board[1][0]);
                move_piece_to_square(second_square, chess_board[2][0]);

                // chess_board[1][0].piece = std::move(first_square.piece);
                // chess_board[2][0].piece = std::move(second_square.piece); 

                // // refactor this to it's own 
                // chess_board[1][0].piece->piece.setPosition(sf::Vector2f((chess_board[1][0].x * SQUARE_LENGTH) + X_OFFSET_DRAW, (chess_board[1][0].y * SQUARE_LENGTH) + Y_OFFSET_DRAW));

                // chess_board[2][0].piece->piece.setPosition(sf::Vector2f((chess_board[2][0].x * SQUARE_LENGTH) + X_OFFSET_DRAW, (chess_board[2][0].y * SQUARE_LENGTH) + Y_OFFSET_DRAW));
                return true;
            } else if (second_square.piece && second_square.piece->is_light && second_coords.first == 7) {
                move_piece_to_square(first_square, chess_board[6][0]);
                move_piece_to_square(second_square, chess_board[5][0]);

                return true;
            }
        } else {
            if (second_square.piece && !second_square.piece->is_light && second_coords.first == 0) {
                // std::cout<<"hit castle";
                move_piece_to_square(first_square, chess_board[1][7]);
                move_piece_to_square(second_square, chess_board[2][7]);

                return true;
            } else if (second_square.piece && !second_square.piece->is_light && second_coords.first == 7) {
                move_piece_to_square(first_square, chess_board[6][7]);
                move_piece_to_square(second_square, chess_board[5][7]);

                return true;
            }
        }

         return false;
    }

    std::vector<std::pair<int, int>>  Game::check_for_castle(std::pair<int,int> selected_piece) {
        // std::cout<<"check castle\n";
        std::vector<std::pair<int, int>> castle_positions;
        Square& selected_square = chess_board[selected_piece.first][selected_piece.second];
        
        // check if king in selected square
        if (selected_square.piece && dynamic_cast<King*>(selected_square.piece.get())) {
            if (selected_square.piece->is_light && light_left_castle) {
            std::cout<<"is King\n";
                if(chess_board[3][0].piece || is_square_attacked(std::make_pair(3,0))) {
                } else if (!chess_board[2][0].piece && is_square_attacked(std::make_pair(2,0))){
                } else if (!chess_board[1][0].piece && is_square_attacked(std::make_pair(1,0))) {
                } else {
                    std::cout<< "viable light left castle\n";
                    castle_positions.push_back(std::make_pair(0,0));
                }
            }
            if (selected_square.piece->is_light && light_right_castle) {
                if (!chess_board[5][0].piece && is_square_attacked(std::make_pair(5,0))){
                } else if (!chess_board[6][0].piece && is_square_attacked(std::make_pair(6,0))) {
                } else {
                    std::cout<< "viable light left castle\n";
                    castle_positions.push_back(std::make_pair(7,0));
                }
            }
            if (!selected_square.piece->is_light && dark_left_castle) {
                 if(chess_board[3][7].piece || is_square_attacked(std::make_pair(3,7))) {
                } else if (!chess_board[2][7].piece && is_square_attacked(std::make_pair(2,7))){
                } else if (!chess_board[1][7].piece && is_square_attacked(std::make_pair(1,7))) {
                } else {
                    std::cout<< "viable light left castle\n";
                    castle_positions.push_back(std::make_pair(0,7));
                }
            }
            if (!selected_square.piece->is_light && dark_right_castle) {
                if (!chess_board[5][7].piece && is_square_attacked(std::make_pair(5,7))){
                } else if (!chess_board[6][7].piece && is_square_attacked(std::make_pair(6,7))) {
                } else {
                    castle_positions.push_back(std::make_pair(7,7));
                }
            }
        }
        return castle_positions;
    }

    void Game::check_moved_castle_pieces(std::pair<int,int> from_coords) {
        if (from_coords.second == 0) {
            if(from_coords.first == 4) {
                light_left_castle = false;
                light_right_castle = false;
            } else if (from_coords.first == 0) {
                light_left_castle = false;
            } else if (from_coords.first == 7) {
                light_right_castle = false;
            }
        } else if (from_coords.second == 7) {
            if(from_coords.first == 4) {
                dark_left_castle = false;
                dark_right_castle = false;
            } else if (from_coords.first == 0) {
                dark_left_castle = false;
            } else if (from_coords.first == 7) {
                dark_right_castle = false;
            }
        }
    }

    void Game::set_board_draw_position(sf::Transformable& transformable, int x, int y) {
        transformable.setPosition(sf::Vector2f((x * SQUARE_LENGTH) + X_OFFSET_DRAW, (y * SQUARE_LENGTH) + Y_OFFSET_DRAW));
    }
}