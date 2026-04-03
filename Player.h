#pragma once
#include "Card.h"
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

    int get_current_total_score() const;
    std::string get_player_name() const;
    const Card::CardCollection& get_bank() const;  // reference
    const Card::CardCollection& get_play_Area() const;  //reference

    void manage_cards();
    void add_card(Card* card);
    void move_cards();

    bool playCard(Card* card, Game& game);
    bool is_bust();
    std::string print_playArea_Bank();

    

};


