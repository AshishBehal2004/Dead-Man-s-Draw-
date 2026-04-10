#pragma once
#include "Card.h"

class Mermaid : public Card
{
public:
    Mermaid(int value);
    std::string str() const override;
    /*!
        does nothing apart from printing the message 
    */
    void play(Game& game, Player& player) override;
};

