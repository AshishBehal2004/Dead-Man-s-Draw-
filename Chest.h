#pragma once
#include "Card.h"
class Chest : public Card
{
    Chest(int value);
    std::string str() const override;

    void play(Game& game, Player& player) override;

    void willAddToBank(Game& game, Player& player) override;
};

