#include "Card.h"
#include <string>
#include "Player.h"
#include "Game.h"



typedef std::vector<Card*> CardCollection;

Card::CardType cannon = Card::CardType::Cannon;
Card::CardType chest = Card::CardType::Chest;
Card::CardType anchor = Card::CardType::Anchor;
Card::CardType sword = Card::CardType::Sword;
Card::CardType hook = Card::CardType::Hook;
Card::CardType oracle = Card::CardType::Oracle;
Card::CardType map = Card::CardType::Map;
Card::CardType mermaid = Card::CardType::Mermaid;
Card::CardType kraken = Card::CardType::Kraken;

std::string str() {
    return "";
}

void play(Game& game, Player& player) {

}

void willAddToBank(Game& game, Player& player) {

}
