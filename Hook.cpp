#include "Hook.h"

Hook::Hook(int value) : Card(Card::CardType::Cannon, value) {}

std::string Hook::str() const {
    return "Hook(" + std::to_string(get_value()) + ")";
}

void Hook::play(Game& game, Player& player) {

}