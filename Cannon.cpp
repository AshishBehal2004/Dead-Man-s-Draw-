#include "Cannon.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <algorithm>
Cannon::Cannon( int value) : Card(Card::CardType::Cannon, value) {}


std::string Cannon::str() const {
    return "Cannon(" + std::to_string(get_value()) + ")";
}

void Cannon::play(Game& game, Player& player) {
    
    Player* other_player = game.get_other_player();
    const Card::CardCollection& otherPlayer_Bank = other_player->get_bank();
    Card::CardCollection& game_DiscardPile = game.get_discard_pile();

    if (otherPlayer_Bank.empty()) {
        std::cout << "   No cards in the other player's bank. Play continues";
      
    }
    else {
        Card* max_cardValue = otherPlayer_Bank.front();

        for (Card* card : otherPlayer_Bank) {
            if (card->get_value() > max_cardValue->get_value()) {
                max_cardValue = card;
            }
        }
        game_DiscardPile.push_back(max_cardValue);
        other_player->removeCard_fromBank(max_cardValue);

    }
}
