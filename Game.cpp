#include "Game.h"
#include "Cannon.h"
#include "Chest.h"
#include "Key.h"
#include "Sword.h"
#include "Hook.h"
#include "Oracle.h"
#include "Map.h"
#include "Mermaid.h"
#include "Kraken.h"
#include <algorithm>
#include <random>

#include <iostream>
#include "game_title.h"

Game::Game() {}


int Game::get_current_turn()const {
    return _current_turn;
}
int Game::get_current_round() const {
    return _current_round;
}
const Player* Game::get_current_player() const {
    return _current_player;
}

const Card::CardCollection Game::get_deck() const {
    return _deck;
}
const Card::CardCollection Game::get_discard_pile() const {
    return _discardPile;
}

void Game::initialise_players() {
   
    _player1 = new Player();
    _player2 = new Player();
}

void Game::create_card_deck() {
    
    for (int i = 0; i < 9; i++) {

        if (i == 7) {
            switch (i) {
            case(7):
                for (int k = 4; k <= 9; k++) {
                    _deck.push_back(new Mermaid(k));
                }
                break;
            }
        }
        else {
            for (int j = 2; j <= 7; j++) {
                switch (i) {

                case(0):
                    // create 
                    _deck.push_back(new Cannon(j));
                    break;
                case(1):
                    _deck.push_back(new Chest(j));
                    break;
                case(2):
                    _deck.push_back(new Key(j));
                    break;
                case(3):
                    _deck.push_back(new Sword(j));
                    break;
                case(4):
                    _deck.push_back(new Hook(j));
                    break;
                case(5):
                    _deck.push_back(new Oracle(j));
                    break;
                case(6):
                    _deck.push_back(new Map(j));
                    break;
                case(8):
                    _deck.push_back(new Kraken(j));
                    break;
                }
            }
        }
    }
}


void Game::shuffleDeck(Card::CardCollection& cards) {
    Card::CardCollection shuffleDeck{ cards.begin(), cards.end() };
    std::shuffle(shuffleDeck.begin(), shuffleDeck.end(), std::mt19937{ std::random_device{}() });
    std::copy(shuffleDeck.begin(), shuffleDeck.end(), cards.begin());
}

void Game::start_game() {
    std::cout << GAME_TITLE;
    initialise_game();
    std::cout << "Starting DeadMan's Draw++!\n";
    control_turn();
    print_final_scores();
}

void Game::initialise_game() {
    initialise_players();
    create_card_deck();
    shuffleDeck(_deck);
}

std::string Game::print_final_scores() {
    std::string final_score;

    final_score =  "--- Game Over ---\n";
    final_score += _player1->printBank() + "\n";
    final_score += _player2->printBank() + "\n";
    final_score += end_game();
    return final_score;
}

void Game::switch_player() {
    if (_current_player == _player1) {
        _current_player = _player2;
    }
    else {
        _current_player = _player1;
    }
}
void Game::control_turn() {
    _current_player = _player1;
    while ( !_deck.empty() && _current_turn < 20) {
        std::cout << "--- Round " << _current_round << ", Turn " << _current_turn << " ---";
        std::cout << _current_player->get_player_name() << "'s turn.";
        std::cout << _current_player->printBank();
        Card* drawnCard = draw_card();
        _current_player->playCard(drawnCard, *this);
        
        if (_current_player->is_bust() ) {
            moveCards_to_discard_pile();
            switch_player();
        }
        else {
            std::string userInput;
            std::cout << "Draw again? (y/n):";
            std::cin >> userInput;
            while (userInput == "y") {
                Card* drawnCard = draw_card();
                _current_player->playCard(drawnCard, *this);
                if (_current_player->is_bust()) {
                    moveCards_to_discard_pile();
                    switch_player();
                    break;
                }
                std::cout << "Draw again? (y/n):";
                std::cin >> userInput;
            }
            if (userInput == "n") {
                _current_player->move_cards();
                switch_player();
            }
        }
        _current_turn++;
    }
}

void Game::moveCards_to_discard_pile() {
    for (Card* cards : _current_player->get_play_Area()) {
        _discardPile.push_back(cards);
    }
    _current_player->clear_playArea();
}


Card* Game::draw_card(){
    Card* card = _deck.front();
    _deck.erase(_deck.begin());
    return card;
}

std::string Game::end_game() {
    _player1->calculate_score();
    _player2->calculate_score();

    int player1Score = _player1->get_current_total_score();
    int player2Score = _player2->get_current_total_score();
    std::string win_result;
    if (player1Score < player2Score) {
        win_result = _player2->get_player_name() + "wins!";
    }
    else {
        win_result =  _player1->get_player_name() + "wins!";
    }
    return win_result;
}
