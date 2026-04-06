#pragma once
#include "Card.h"

class Oracle : public Card
{
public:

    Oracle(int value);
    std::string str() const override;

    void play(Game& game, Player& player) override;
};

