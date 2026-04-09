#include "Map.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

Map::Map(int value) : Card(Card::CardType::Map, value) {}

std::string Map::str() const {
    return "Map(" + std::to_string(get_value()) + ")";
}

void Map::play(Game& game, Player& player) {

    std::vector<Card*> cardsFrom_discardPile;
    int userChoice;
    if (game.get_discard_pile().empty()) {
        std::cout << "No cards in the deck. Play continues.";

    }
    else {
        std::cout << "Draw 3 cards from the discard and pick one to add to the play area: ";
        for (int i = 0; i < 3; i++) {
            if (game.get_discard_pile().empty()) {
                break;
            }
            cardsFrom_discardPile.push_back(game.get_discard_pile().front());
            game.get_discard_pile().erase(game.get_discard_pile().begin());
        }
        
        for (int i = 0; i < cardsFrom_discardPile.size(); i++) {
            
            std::cout << "(" << i+1 << ")" << cardsFrom_discardPile[i]->str() << "\n";
        }
        std::cout << "Which card do you pick? ";
        std::cin >> userChoice;
        if (userChoice >= 1 && userChoice <= cardsFrom_discardPile.size()) {
            Card* drawnCard = cardsFrom_discardPile[userChoice-1];
            player.playCard(drawnCard, game);
        }
    }
}