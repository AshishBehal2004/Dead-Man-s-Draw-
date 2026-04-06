#include "Map.h"


Map::Map(int value) : Card(Card::CardType::Cannon, value) {}

std::string Map::str() const {
    return "Map(" + std::to_string(get_value()) + ")";
}

void Map::play(Game& game, Player& player) {

}