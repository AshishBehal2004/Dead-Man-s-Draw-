#include "Mermaid.h"

Mermaid::Mermaid(int value) : Card(Card::CardType::Cannon, value) {}

std::string Mermaid::str() const {
    return "Mermaid(" + std::to_string(get_value()) + ")";
}

void Mermaid::play(Game& game, Player& player) {

}