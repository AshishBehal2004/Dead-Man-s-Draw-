#pragma once
#include "Card.h"

class Hook : public Card
{
    Hook(int value);
    std::string str() const override;

    void play(Game& game, Player& player) override;
};

