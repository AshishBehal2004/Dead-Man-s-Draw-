#pragma once
#include "Card.h"

class Hook : public Card
{
public:

    Hook(int value);
    std::string str() const override;

    /*!
        pulls a card from the player's own bank and adds it back into play area
        using map which stores numbered options so user can pick by number
        removes chosen card from bank and plays it into play area
        also handling valid case where user picks the number options displayed in the output
    */
    void play(Game& game, Player& player) override;
};

