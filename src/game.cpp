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
        is_light_turn = false;

        // initiate light pawns on board
        for (int i = 0; i < 8; ++i) {
            chess_board[i][1].piece = std::make_unique<Pawn>(true);
        }
        chess_board[0][2].piece = std::make_unique<Pawn>(false);

        //initiate dark pawns on board
        for (int i = 0; i < 8; ++i) {
            chess_board[i][3].piece = std::make_unique<Pawn>(false);  // Assign the 
        }
    }

    bool Game::is_click_on_board(const sf::Event& event) const {
        // this statement checks if the click is inside the board: 1. check click inside right border 2. check click inside left border 3. check above bottom border 4. check bellow top border
        return event.mouseButton.x <= X_OFFSET_DRAW + (SQUARE_LENGTH * 8) 
        && event.mouseButton.x >= X_OFFSET_DRAW 
        && event.mouseButton.y <= Y_OFFSET_DRAW + (SQUARE_LENGTH * 8) 
        && event.mouseButton.y >= Y_OFFSET_DRAW;
    }

    void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        // std::cout << "drawing\n";
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

     


        target.draw(turn_text);

        
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
        int x_square = (x_cord - X_OFFSET_DRAW) / SQUARE_LENGTH;
        int y_square = (y_cord - Y_OFFSET_DRAW) / SQUARE_LENGTH;

        std::cout << "x cord: " << x_square << ", y cord: " << y_square << "\n";
        // selected->is_selected = true;
        possible_moves.clear();
         for (int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                chess_board[i][j].is_selected = false;
            }
         }  
        Square& chosen_square = chess_board[x_square][y_square];
        if (chosen_square.piece && chosen_square.piece->is_light == is_light_turn) {
            chess_board[x_square][y_square].is_selected = true;
            
                    std::cout<< "this is possible \n";
                    // Game::possible_moves.push_back(std::make_pair(x_square, y_square));
                
            possible_moves = chess_board[x_square][y_square].piece->get_moves(chess_board, x_square, y_square);
        }   
    }
}