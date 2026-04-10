#pragma once
#include "Card.h"

class Cannon : public Card      
{
public:

    Cannon(int value);

    std::string str() const override;

    /*!
        play() is incharge of playing the Cannon Card which overrides the abstract class Card's play method.
        it discard the highest value of any suit type from the other player’s Bank to the Discard Pile.
    */
    void play(Game& game, Player& player) override;


};

