#pragma once
#include "Card.h"

class Mermaid : public Card
{
    std::string str() const override;

    void play(Game& game, Player& player) override;
};

