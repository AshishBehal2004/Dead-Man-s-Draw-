#pragma once
#include "Card.h"

class Kraken : public Card
{
public:
    Kraken(int value);
    std::string str() const override;

    /*!
        It forces the player to draw and play 3 cards consecutively from the deck.
        and stops early if the deck runs out or the player busts mid-draw.
    */
    void play(Game& game, Player& player) override;
};

