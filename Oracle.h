#pragma once
#include "Card.h"

class Oracle : public Card
{
    std::string str() const override;

    void play(Game& game, Player& player) override;
};

