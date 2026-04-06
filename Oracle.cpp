#include "Oracle.h"


Oracle::Oracle(int value) : Card(Card::CardType::Cannon, value) {}

std::string Oracle::str() const {
    return "Oracle(" + std::to_string(get_value()) + ")";
}

void Oracle::play(Game& game, Player& player) {

}