#include "Kraken.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

Kraken::Kraken(int value) : Card(Card::CardType::Kraken, value) {}

std::string Kraken::str() const {
    return "Kraken(" + std::to_string(get_value()) + ")";
}

void Kraken::play(Game& game, Player& player) {
    std::cout << "Draw 3 cards from the deck and play each: \n\n";
    if (game.get_deck().empty()) {
        std::cout << "No cards in the deck. Play continues.";
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (game.get_deck().empty()) {
                std::cout << "   No cards in the deck. Play continues.";
                break;
            }
            Card* drawnCard = game.draw_card();
            if (player.playCard(drawnCard, game)) {
                break;
            }     
        }
    }   
}