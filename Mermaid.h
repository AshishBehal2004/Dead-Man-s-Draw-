#pragma once
#include "Card.h"

class Mermaid : public Card
{
public:
    Mermaid(int value);
    std::string str() const override;

    void play(Game& game, Player& player) override;
};

