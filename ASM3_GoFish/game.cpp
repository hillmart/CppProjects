/*********************************************************************
** Program Filename: game.cpp
** Author: Martin Hill
** Date: 11/06/22
** Description: game functions
** Input: deck and players
** Output: deck and players
Doesn't need big 3 bc no heap usage
Needs accessor and mutators to access from driver
*********************************************************************/

#include <string>
#include <cstdlib>

#include "deck.h"
#include "card.h"
#include "game.h"
#include "player.h"
#include "hand.h"

using namespace std;

//constructor
Game::Game(){
    //cout << "inside default game constructor..." << endl;
    Deck d;
    Player players[2];
}

//destructor, no heap usage
Game::~Game(){}

//getters
Deck Game::get_d () {
    return this->d;
}

Player* Game::get_players() {
    return this->players;
}


//setters
void Game::set_d (Deck new_deck){
    this->d = new_deck;
}

void Game::set_players (Player new_player, int player_i){
    this->players[player_i] = new_player;
}

/*********************************************************************
** Function: shuffle_d
** Description: shuffles by swapping random indexes
** Parameters: none
** Pre-Conditions: deck initialized
** Post-Conditions: deck shuffled
*********************************************************************/
void Game::shuffle_d(){
    for (int i = 0; i < 100; i++){
        int index_1 = rand()%52;
        Card temp = d.get_card(index_1);
        int index_2 = rand()%52;
        this->d.set_card(d.get_card(index_2), index_1);
        this->d.set_card(temp, index_2);
    }
}

/*********************************************************************
** Function: draw_cards
** Description: removes card from deck, places card in hand
** Parameters: player index
** Pre-Conditions: deck initialized
** Post-Conditions: card placed in player hand
*********************************************************************/ 
void Game::draw_cards(int player_index){
    Card c = this->d.remove_card();

    this->players[player_index].place_a_card(c);
}

/*********************************************************************
** Function: go_fishing
** Description: draws from deck and checks card
** Parameters: chosen_rank
** Pre-Conditions: in find_card
** Post-Conditions: card drawn from deck
*********************************************************************/ 
void Game::go_fishing(int chosen_rank){
    cout << "Go fish" << endl;
    if (d.get_n_cards() != 0){
        draw_cards(0);
        cout << "You drew a " << this->players[0].get_hand().get_cards()[this->players[0].get_hand().get_n_cards() - 1].get_rank() << endl;
    }
    if (this->players[0].get_hand().get_cards()[this->players[0].get_hand().get_n_cards() - 1].get_rank() == chosen_rank && (this->d.get_n_cards() != 0)){
        user_turn();
    }
}

/*********************************************************************
** Function: find_card
** Description: using request, looks for match, adds match
** Parameters: chosen_rank
** Pre-Conditions: in players turn
** Post-Conditions: card moved from one to other
*********************************************************************/ 
void Game::find_card(int chosen_rank){
    if (this->players[1].match_rank(chosen_rank)){
        cout << "Match found" << endl;
        for (int i = 0; i < this->players[1].get_hand().get_n_cards(); i++){
            Card c;
            c = this->players[1].remove_rank(chosen_rank, c, i);
            if (c.get_rank() != -1){
                this->players[0].place_a_card(c);
            }
        }
        user_turn();
    }
    else{
        go_fishing(chosen_rank);
    }
}

/*********************************************************************
** Function: user_turn
** Description: gets request, looks for match, adds match or go fish
** Parameters: none
** Pre-Conditions: hands drawn
** Post-Conditions: card moved from one to other
*********************************************************************/ 
void Game::user_turn(){
    if (this->players[0].get_hand().get_n_cards() == 0){
        cout << "You ran out of cards and went fishing" << endl;
        if (d.get_n_cards() != 0){
            draw_cards(0);
        }
    }
    else {
        int chosen_rank = this->players[0].request_rank();
        find_card(chosen_rank);
    }
}

/*********************************************************************
** Function: if_match
** Description: gets card from users hand
** Parameters: chosen_rank
** Pre-Conditions: computer chose rank
** Post-Conditions: card moved from one to other
*********************************************************************/
void Game::if_match(int chosen_rank){
    cout << "Uh oh, the computer stole your "<< chosen_rank << "(s)" << endl;
    for (int i = 0; i < this->players[0].get_hand().get_n_cards(); i++){
        Card c;
        c = this->players[0].remove_rank(chosen_rank, c, i);
        if (c.get_rank() != -1){
            this->players[1].place_a_card(c);
        }
    }
    computer_turn();
}

/*********************************************************************
** Function: else_match
** Description: draws from deck
** Parameters: chosen_rank
** Pre-Conditions: computer chose rank
** Post-Conditions: card added to hand
*********************************************************************/
void Game::else_match(int chosen_rank){
    cout << "You told the computer to go fish" << endl;
    if (d.get_n_cards() != 0){
        draw_cards(1);
        if (this->players[1].get_hand().get_cards()[this->players[1].get_hand().get_n_cards() - 1].get_rank() == chosen_rank){
            cout << "The computer drew the rank it asked for and took another turn." << endl;
            computer_turn();
        }
    }
}

/*********************************************************************
** Function: computer_turn
** Description: gets request, looks for match, adds match or go fish
** Parameters: none
** Pre-Conditions: hands drawn
** Post-Conditions: card moved from one to other
*********************************************************************/
void Game::computer_turn(){
    if (this->players[1].get_hand().get_n_cards() == 0){
        cout << "The computer ran out of cards and went fishing" << endl;
        if (d.get_n_cards() != 0){
            draw_cards(1);
        }
    }
    else {
        int chosen_rank = this->players[1].computer_request_rank();
        if (this->players[0].match_rank(chosen_rank)){
            if_match(chosen_rank);
        }
        else { 
            else_match(chosen_rank);
        }
    }
}

/*********************************************************************
** Function: cehck for books
** Description: calls each player check for books function
** Parameters: none
** Pre-Conditions: hands drawn
** Post-Conditions: cards moved to book
*********************************************************************/
void Game::check_for_books(){
    this->players[0].check_for_books();
    this->players[1].check_for_books();   
}

//calls players bubble sort function
void Game::bubble_sort_player(int player_to_sort){
    this->players[player_to_sort].bubble_sort_hand();
}