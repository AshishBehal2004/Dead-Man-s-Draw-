#include "Mermaid.h"

Mermaid::Mermaid(int value) : Card(Card::CardType::Cannon, value) {}

std::string Mermaid::str() const {
    return "";
}

void Mermaid::play(Game& game, Player& player) {

}