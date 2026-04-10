#pragma once
#include "Card.h"

class Map : public Card
{
public:
    Map(int value);
    std::string str() const override;

    /*!
        Draws up to 3 cards from the discard pile and lets the player choose one to add to their play area.
        Using a vector to temporarily hold the drawn cards, allowing the player to select by numbered index.
        and also handling the case where if discardpile it should break
        and also checking for whether the user entered a valid choice or not 
    */  
    void play(Game& game, Player& player) override;
};

