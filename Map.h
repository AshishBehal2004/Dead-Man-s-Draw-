#pragma once
#include "Card.h"

class Map : public Card
{
public:
    Map(int value);
    std::string str() const override;

    void play(Game& game, Player& player) override;
};

