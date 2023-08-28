/*********************************************************************
** Program Filename: deck.cpp
** Author: Martin Hill
** Date: 11/06/22
** Description: Deck functions
** Input: cards
** Output: deck of 52 cards
Doesn't need big 3 bc no heap usage
Needs accessor and mutators to access from game class
*********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

#include "deck.h"
#include "card.h"
#include "game.h"
#include "player.h"
#include "hand.h"

using namespace std;


//default constructor
Deck::Deck(){
    this->n_cards = 52;
    for(int i = 0; i < n_cards; i++){
        this->cards[i] = Card(i%13, i/13);
    }
}

//destructor, not needed, no heap
Deck::~Deck(){}

//getters
int Deck::get_n_cards () {
    return this->n_cards;
}

Card Deck::get_card (int card_index) {
    return this->cards[card_index];
}

//setters
void Deck::set_n_cards (int new_n_cards){
    this->n_cards = new_n_cards;
}

void Deck::set_card (Card new_card, int card_index){
    this->cards[card_index] = new_card;
}

/*********************************************************************
** Function: remove_card
** Description: decrements n_cards and returns smaller deck
** Parameters: none
** Pre-Conditions: n_cards > 0
** Post-Conditions: deck smaller
*********************************************************************/ 
Card& Deck::remove_card(){
    this->n_cards--;
    return this->cards[n_cards];
}