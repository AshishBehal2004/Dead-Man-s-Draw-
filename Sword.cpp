#include "Sword.h"
#include <iostream>

Sword::Sword(int value) : Card(Card::CardType::Sword, value) {}

std::string Sword::str() const {

    return "Sword(" + std::to_string(get_value()) + ")";
}

void Sword::play(Game& game, Player& player) {

}