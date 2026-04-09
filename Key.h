#pragma once
#include "Card.h"
class Key : public Card
{
public:
    Key(int value);
    std::string str() const override;

    void play(Game& game, Player& player) override;

};

