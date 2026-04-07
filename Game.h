#pragma once

#include "Card.h"
#include "Player.h"

class Game
{
public:
    
    Game();
    void initialise_game();
    void start_game();
    std::string end_game();
    std::string print_final_scores();
    void create_card_deck();
    void shuffleDeck(Card::CardCollection& cards);
    void initialise_players();
    void control_turn();
    

    int get_current_turn() const;
    int get_current_round() const;
    const Player* get_current_player() const;
    const Card::CardCollection get_deck() const;
    const Card::CardCollection get_discard_pile() const;
    void moveCards_to_discard_pile();
    void switch_player();
    Card* draw_card();

private:
    int _current_turn;
    int _current_round;
    Player* _current_player;
    Player* _player1;
    Player* _player2;
    Card::CardCollection _deck;
    Card::CardCollection _discardPile;


};

