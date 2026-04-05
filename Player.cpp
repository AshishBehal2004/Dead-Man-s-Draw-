#include "Player.h"
#include "Card.h"
#include "Game.h"
#include <unordered_set>
#include <iostream>

Player::Player() : _current_total_score(0), _player_name("") {
    std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue",
"Sasha", "Tina", "Marge" };
    _player_name = names[rand() % 10];
}

int Player::get_current_total_score() const {
    return _current_total_score;
}

std::string Player::get_player_name() const {
    return _player_name;
}

const Card::CardCollection& Player::get_bank() const {  // reference
    return _bank;
}

const Card::CardCollection& Player::get_play_Area() const{  //reference
    return _playArea;
}

bool Player::playCard(Card* card, Game& game) {
    _playArea.push_back(card);
    if (is_bust()) {
        return true;
    }
    else {
        card->play(game, *this);
        return false;
    }
}

void Player::manage_cards() {

}

void Player::add_card(Card* card) {
    _playArea.push_back(card);
}

// Is responsible for knowing if the player’s current play area is bust(i.e.there are two
//   of the same type of card in the play area).
bool Player::is_bust() {
    std::unordered_set<Card::CardType> cardType;

    for (Card* card : _playArea) {
        if (cardType.find(card->type()) != cardType.end()) { //when the set finds a duplciate
            return true;
        }
        else {
            cardType.insert(card->type());
        }
    }
    return false;
}

std::string Player::printBank() {
    std::string result;
    result += _player_name + "'s Bank: \n";
    for (Card* card : _bank) {
        result += card->str() + " ";
    }
    std::string stringScore = std::to_string(_current_total_score);
    result += "\n| Score: " + stringScore;
    return result;
}

std::string Player::print_playArea() {
    std::string result;
    result += _player_name + "'s Play Area: \n";
    for (Card* card : _playArea) {
        result += " " + card->str() + "\n";
    }
    return result;
}

void Player::move_cards() {
    for (Card* card : _playArea) {
        _bank.push_back(card);
    }
    _playArea.clear();
}