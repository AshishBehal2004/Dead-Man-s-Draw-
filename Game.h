#pragma once

#include "Card.h"
#include "Player.h"

class Game
{
public:
    
    /*!
        initialised default constructor 
    */
    Game();

    /*!
        does 3 jobs: 
        1. sets up 2 player object (by calling initialise_players()
        2. then it calls the create_card_card() (which obviously creates the whole card deck)
        3. and shuffles the deck which is just been created 
    */
    void initialise_game();

    /*!
        calls the macro which is defined in game_title for printing and outputing the game title
        then it calls the initialise_game()
        and it prints the message saying: Starting DeadMan's Draw C++
        and then it calls the control_turn which handles the most of the game loop
        and at last prints the final scores which happpens wwhen game is finished 
    */
    void start_game();

    /*!
        it first calculate both the players scores by calling calculate_score() on each of them
        then compares their total_score 
        and assigns the name of whosoever's score is greatest to the win_result(variable of type string ) along with string saying Wins!
        and then returns the win_result string
    */
    std::string end_game();

    /*!
        it first calulcates both players score by calling calculate_score()
        then appends the game over string, and both the player's bank (which also include score) 
        to the final_score string, and also assigns the end_game()(which decides who won)
        then returns the string
    */
    std::string print_final_scores();

    /*!
       creates the cards of 9 different suits (hence looping over 9 times) 
       the rest explaination is in Game.cpp under the same method.
    */
    void create_card_deck();

    /*!
       shuffles the cards present in the deck
       logic was provided in the spec so pretty much copy/paste (lol)
       shuffles the card randomly using random_device and random number generator based on a certain algorithm
    */
    void shuffleDeck(Card::CardCollection& cards);

    /*!
        creates 2 player objects dynamically (using new)
    */
    void initialise_players();

    /*!
        the main game loop logic
        explaination is in Game.cpp above control_turn()
    */
    void control_turn();

    /*!
        getters for private attribute 
    */
    int get_current_turn() const;
    int get_current_round() const;
    const Player* get_current_player() const;
    Player* get_other_player() ;
    const Card::CardCollection get_deck() const;
    Card::CardCollection& get_discard_pile();

    /*!
        loops over every card in the current player area and adds them to the discard pile, after that it empties player area
    */
    void moveCards_to_discard_pile();

    /*!
        swicthes the current player based which player player is assigned to currentplayer 
    */
    void switch_player();

    /*!
        draws the top card from the deck and stores in card type attribute and then removes it from the deck and returns the card
    */
    Card* draw_card();

/*! 
    private attributes with getters made for some of them    
*/
private:
    int _current_turn = 1;
    int _current_round = 1;
    Player* _current_player;
    Player* _player1;
    Player* _player2;
    Card::CardCollection _deck;
    Card::CardCollection _discardPile;


};

