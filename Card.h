#pragma once
#include <string>
#include <vector>

class Game;
class Player;
class Card
{
public:
    enum CardType {
        Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken
    };

    virtual std::string str() const = 0;

    const CardType& type() const;

    virtual void play(Game &game, Player &player) = 0;

    virtual void willAddToBank(Game& game, Player& player) {}

    typedef std::vector<Card*> CardCollection;
private:
    CardType _cardType;

};

