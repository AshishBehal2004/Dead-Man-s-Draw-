#pragma once
#include "Card.h"
class Chest : public Card
{
public:
    
    /*!
        parametrised constructor which have vvalue as the paramter
    */
    Chest(int value);
    
    
    std::string str() const override;

    /*!
        displays the message in the output saying the message as it was mentioned in the spec
    */
    void play(Game& game, Player& player) override;

     /*!
        responsible for checking whether key exists in the player area as well, if it does then
        it loops over till the total cards in the player area and draw that many cards from the discard pile and adds to the player's bank
    */
    void willAddToBank(Game& game, Player& player) override;
};

