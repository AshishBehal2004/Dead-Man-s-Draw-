#pragma once
#include "Card.h"

class Cannon : public Card      
{
    std::string str() const override;

    void play(Game& game, Player& player) override;
    
};

