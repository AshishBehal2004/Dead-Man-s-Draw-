#pragma once
#include "Card.h"
class Key : public Card
{

    Key(int value);
    std::string str() const override;

    void play(Game& game, Player& player) override;

    void willAddToBank(Game& game, Player& player) override;
};

