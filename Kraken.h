#pragma once
#include "Card.h"

class Kraken : public Card
{
    Kraken(int value);
    std::string str() const override;

    void play(Game& game, Player& player) override;
};

