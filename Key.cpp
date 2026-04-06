#include "Key.h"

Key::Key(int value) : Card(Card::CardType::Cannon, value) {}


std::string Key::str() const {
    return "Key(" + std::to_string(get_value()) + ")";
}

void Key::play(Game& game, Player& player) {

}

void Key::willAddToBank(Game& game, Player& player) {

}
