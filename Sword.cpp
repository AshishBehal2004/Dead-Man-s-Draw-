#include "Sword.h"


Sword::Sword(int value) : Card(Card::CardType::Cannon, value) {}

std::string Sword::str() const {
    return "";
}

void Sword::play(Game& game, Player& player) {

}