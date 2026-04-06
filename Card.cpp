#include "Card.h"
#include <string>



Card::Card(CardType cardType, int value) : _cardType(cardType), _value(value) {}


const Card::CardType& Card::type() const {
    return _cardType;
}


int Card::get_value() const {
    return _value;
}

