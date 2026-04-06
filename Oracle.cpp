#include "Oracle.h"


Oracle::Oracle(int value) : Card(Card::CardType::Cannon, value) {}

std::string Oracle::str() const {
    return "";
}

void Oracle::play(Game& game, Player& player) {

}