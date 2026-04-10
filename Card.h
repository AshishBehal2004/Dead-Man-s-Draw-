#pragma once
#include <string>
#include <vector>

class Game;
class Player;
class Card
{
public:

    enum CardType {
        Cannon, Chest, Key, Sword, Hook, Oracle, Map, Mermaid, Kraken
    };
    Card(CardType _cardType, int _value);
  
    //str() is responsible for returnig teh Card name along with the value
    virtual std::string str() const = 0;

    const CardType& type() const;

    virtual void play(Game &game, Player &player) = 0;

    /*!
        virtual method which gets overriden by its child classes , only chest overrides it
        since it checks for whether the the key and the chest card exist in the player area
    */
    virtual void willAddToBank(Game& game, Player& player) {}

    typedef std::vector<Card*> CardCollection;
    
    /*!
        getter for the private attribute _value (below at line 34)
    */
    int get_value() const;
private:
    CardType _cardType;
    int _value;

};

