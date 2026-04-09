#include "Map.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

Map::Map(int value) : Card(Card::CardType::Map, value) {}

std::string Map::str() const {
    return "Map(" + std::to_string(get_value()) + ")";
}

void Map::play(Game& game, Player& player) {
    if (game.get_deck().empty()) {
        std::cout << "No cards in the deck. Play continues.";

    }
    else {
        std::cout << ""
    }
}