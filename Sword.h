#pragma once
#include "Card.h"

class Sword : public Card
{
public:
    Sword(int value);
    std::string str() const override;
    /*!
        Steal the highest value card of any suit from  the other player’s Bank into current Play Area. prompts the user to select one card 
        using a map to insert the card from other player's bank
        Steals the highest value card from the other player's bank into the current player's play area.
        using a map (where int would be the key which the user can select to add that card and key as obviously the card with its value)
        to associate numbered menu options with cards to easily lookup based on the user input.
    */
    void play(Game& game, Player& player) override;
};

