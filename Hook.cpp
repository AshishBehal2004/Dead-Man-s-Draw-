#include "Hook.h"

Hook::Hook(int value) : Card(Card::CardType::Cannon, value) {}

std::string Hook::str() const {
    return "";
}

void Hook::play(Game& game, Player& player) {

}