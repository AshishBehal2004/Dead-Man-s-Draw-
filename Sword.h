#pragma once
#include "Card.h"

class Sword : public Card
{
    std::string str() const override;
    
    void play(Game& game, Player& player) override;
};

