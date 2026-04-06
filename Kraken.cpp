#include "Kraken.h"


Kraken::Kraken(int value) : Card(Card::CardType::Cannon, value) {}

std::string Kraken::str() const {
    return "Kraken(" + std::to_string(get_value()) + ")";
}

void Kraken::play(Game& game, Player& player) {

}