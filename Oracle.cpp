#include "Oracle.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

Oracle::Oracle(int value) : Card(Card::CardType::Oracle, value) {}

std::string Oracle::str() const {
    return "Oracle(" + std::to_string(get_value()) + ")";
}

void Oracle::play(Game& game, Player& player) {

    if (game.get_deck().empty()) {
        std::cout << "   No cards in the deck. Play continues.";

    }
    else {
        std::cout << "\nThe Oracle sees a " << game.get_deck().front()->str() << "\n";
        std::cout << player.print_playArea();
        std::cout << "\nDraw again? (y/n): ";
        std::string userChoice;
        std::cin >> userChoice;

        if (userChoice == "y") {

            Card* topCardDrawn_fromDeck = game.draw_card();
            player.playCard(topCardDrawn_fromDeck, game);
        }
    }
    
}