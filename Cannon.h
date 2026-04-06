#pragma once
#include "Card.h"

class Cannon : public Card      
{
public:

    Cannon(int value);

    std::string str() const override;

    void play(Game& game, Player& player) override;


};

