#include "Sword.h"
#include <iostream>
#include "Game.h"
#include <map>
#include "Card.h"
#include "Player.h"

Sword::Sword(int value) : Card(Card::CardType::Sword, value) {}

std::string Sword::str() const {

    return "Sword(" + std::to_string(get_value()) + ")";
}

void Sword::play(Game& game, Player& player) {

    std::map<int, Card*> bank_cards;
    
    Player* other_player = game.get_other_player();
    if (other_player->get_bank().empty()) {
        std::cout << "   No cards in other player's Bank. Play continues.";
    }
    else {
        std::cout << "Steal the top card of any suit from the other player's Bank into your Play Area:\n";
        int options = 1;
        int userChoice;
        for (Card* card : other_player->get_bank()) {
            std::cout << "(" << options << ") " << card->str() + "\n";
            bank_cards.insert({ options, card });
            options++;
        }

        std::cout << "Which card do you pick? ";
        std::cin >> userChoice;
        if (userChoice >= 1 && userChoice <= options) {
            player.add_card(bank_cards[userChoice]);
            other_player->removeCard_fromBank(bank_cards[userChoice]);
        }
    }
}