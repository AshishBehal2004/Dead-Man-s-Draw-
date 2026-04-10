#pragma once
#include "Card.h"

class Oracle : public Card
{
public:

    Oracle(int value);
    std::string str() const override;

    /*!
        Peeks at the top card of the deck and lets the player decide whether to draw it or not.
        and checks whether the deck is not empty first, then reveals the top card and prompts the player for input.
    */
    void play(Game& game, Player& player) override;
};

