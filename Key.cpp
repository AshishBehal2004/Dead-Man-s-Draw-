#include "Key.h"
#include <iostream>
Key::Key(int value) : Card(Card::CardType::Key, value) {}


std::string Key::str() const {
    return "Key(" + std::to_string(get_value()) + ")";
}

void Key::play(Game& game, Player& player) {
    std::cout << "No immediate effect. If banked with a Key card, draw as many bonus cards from the Discard pile as you moved into your Bank.";

}
