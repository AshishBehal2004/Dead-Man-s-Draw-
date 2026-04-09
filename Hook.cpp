#include "Hook.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <map>

Hook::Hook(int value) : Card(Card::CardType::Hook, value) {}

std::string Hook::str() const {
    return "Hook(" + std::to_string(get_value()) + ")";
}

void Hook::play(Game& game, Player& player) {

    
    std::map<int, Card*> bank_cards;

    if (player.get_bank().empty()) {
        std::cout << "   No cards in your Bank. Play continues.";
    }
    else {
        std::cout << "Select a highest-value card from any of the suits in your Bank:\n";
        int options = 1;
        int userChoice;
        for (Card* card : player.get_bank()) {
            std::cout << "(" << options << ") " << card->str() + "\n";
            bank_cards.insert({ options, card });
            options++;
        }

        std::cout << "Which card do you pick? ";
        std::cin >> userChoice;
        if (userChoice >= 1 && userChoice <= options) {
            player.add_card(bank_cards[userChoice]);
            player.removeCard_fromBank(bank_cards[userChoice]);
        }
    }
}


