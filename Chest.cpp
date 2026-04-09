#include "Chest.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
Chest::Chest(int value) : Card(Card::CardType::Chest, value) {}


std::string Chest::str() const {
    return "Chest(" + std::to_string(get_value()) + ")";
}

void Chest::play(Game& game, Player& player) {
    std::cout << "No immediate effect. If banked with a Key card, draw as many bonus cards from the Discard pile as you moved into your Bank.";
}

void Chest::willAddToBank(Game& game, Player& player) {
    Player& current_player = player;
    
    
    Card::CardCollection player_playArea = player.get_play_Area();
    std::string cardsadded;
    for (Card* card : player_playArea) {

        if (card->type() == Card::CardType::Key) {
            int totalCards =  player_playArea.size();
            Card::CardCollection& discardPile = game.get_discard_pile();
            
            for (int i = 0; i < totalCards; i++) {
                if (discardPile.empty()) {
                    std::cout << "No cards in the discard pile. Play continues";
                }
                else {
                    player.add_card(discardPile.front());
                    cardsadded += discardPile.front()->str() + ", ";
                    discardPile.erase(discardPile.begin());
                }     
            }
        std::cout << "Chest and Key activated. Added " << cardsadded << " to your bank.";
        }
    }
}