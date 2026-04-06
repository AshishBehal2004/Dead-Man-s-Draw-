#pragma once
#include "Card.h"

class Hook : public Card
{
public:

    Hook(int value);
    std::string str() const override;

    void play(Game& game, Player& player) override;
};

