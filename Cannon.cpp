#include "Cannon.h"



Cannon::Cannon( int value) : Card(Card::CardType::Cannon, value) {}


std::string Cannon::str() const {
    return "Cannon(" + std::to_string(get_value()) + ")";
}

void Cannon::play(Game& game, Player& player) {

}