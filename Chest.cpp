#include "Chest.h"

Chest::Chest(int value) : Card(Card::CardType::Cannon, value) {}


std::string Chest::str() const {
    return "Chest(" + std::to_string(get_value()) + ")";
}

void Chest::play(Game& game, Player& player) {

}

void Chest::willAddToBank(Game& game, Player& player) {

}