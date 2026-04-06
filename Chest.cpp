#include "Chest.h"

Chest::Chest(int value) : Card(Card::CardType::Cannon, value) {}


std::string Chest::str() const {
    return "";
}

void Chest::play(Game& game, Player& player) {

}

void Chest::willAddToBank(Game& game, Player& player) {

}