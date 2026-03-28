#pragma once
#include <string>

#include "Player.h"
#include "Game.h"

#include <vector>

class Card
{
public:
    enum CardType {
        Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken
    };
    const CardType& type() const;

    virtual std::string str() const = 0;

    virtual void play(Game &game, Player &player) = 0;

    virtual void willAddToBank(Game& game, Player& player) {}

    typedef std::vector<Card*> CardCollection;


};

