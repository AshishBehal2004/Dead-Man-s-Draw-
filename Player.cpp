#include "Player.h"
#include "Card.h"
#include "Game.h"
#include <unordered_set>
#include <iostream>
#include <map>

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
    add_card(card);
    if (is_bust()) {
        return true;
    }
    else {
        card->play(game, *this);
        return false;
    }
}

void Player::clear_playArea() {
    _playArea.clear();
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
    result += "\n" + _player_name + "'s Bank: \n";
    for (Card* card : _bank) {
        result += card->str() + " ";
    }
    std::string stringScore = std::to_string(_current_total_score);
    result += "\n| Score: " + stringScore +"\n";
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

void Player::move_cards(Game& game) {
    for (Card* card : _playArea) {
        card->willAddToBank(game, *this);
        _bank.push_back(card);
    }
    _playArea.clear();
}

void Player::calculate_score() {

    std::map<Card::CardType, int > S;
    for (Card* card : _bank ) {
        Card::CardType t = card->type();

        if (S[t] < card->get_value()) {
            S[t] = card->get_value();
        }
    }
    int total = 0;
    for (auto eachPair : S) {
        total = total + eachPair.second;
    }
    _current_total_score = total;
}

void Player::removeCard_fromBank(Card* card) {
    auto card_index = find(_bank.begin(), _bank.end(), card);

    _bank.erase(card_index);
}

