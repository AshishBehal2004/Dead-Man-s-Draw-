#pragma once
#include "Card.h"
/*! allows to tell the Player that Game class exists*/
class Game;

class Player
{

private:
    int _current_total_score;
    std::string _player_name;
    Card::CardCollection _bank;
    Card::CardCollection _playArea;

public:
    
    Player();


    /*!
        getters for accesisnig the private attributes
    */
    int get_current_total_score() const;
    std::string get_player_name() const;
    const Card::CardCollection& get_bank() const;  
    const Card::CardCollection& get_play_Area() const;  

    /*!
        responsible for clearing the player area, does that by calling clear onto the playerArea
    */
    void clear_playArea();

    /*!
        adds the card to the player play area using push_back (since the playArea is of type CardCollection which is a vector)
    */
    void add_card(Card* card);

    /*!
       moves the card from present in player's playArea into the player's bank while doing so , on each card it calls willAddToBank
       the reason it does is to check whether a card is of type key(the logic executes inside willAddToBank does that) else it skips
       and push each card into the bank , and then calculates the score and clears the play area.
    */
    void move_cards(Game& game);

    /*!
        plays the card, it first adds the cards to the player's playArea and then check for whether the player is busted 
        meaning that the player has two cards of same suit, it returns true otherwise plays the card ability
    */
    bool playCard(Card* card, Game& game);

    /*!
        responsible for checking whether the player has two same cards of same suit
        i have done this using unordered_set, since it cannot store duplicates, if it does the duplicate then returns true 
        else it inserts the card into the set.
    */
    bool is_bust();

    /*!
        responsible for printing the cards present in the player bank as mentoined in the spec
        looping over the player's bank and the assigning each card string(using card's str()) to the string
        and returning the string 
    */
    std::string printBank();

    /*!
        does the similar job as printBank() only difference being that it does it from playArea
    */
    std::string print_playArea();

    /*!
        approached this using map as i followed the psuedcode given in spec as it is (hence the varibale name as S and t)
       it calculates the player's total score by summing the highest value card of each suit in the bank
       auto here is std::pair<Card::CardType, int> since i took an easy approach of using auto instead of writing this chunk
    */
    void calculate_score();

    /*!
        finds the card from the bank using bank's(since behind the scenes its a vector) built in methods, 
        used auto assign the card when found in order to let the compiler know its type automatically
        and erases that card from the bank
    */
    void removeCard_fromBank(Card* card);
    

};


