#pragma once
#include "Card.h"

class Hook : public Card
{
    std::string str() const override;

    void play(Game& game, Player& player) override;
};

