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