/*********************************************************************
** Program Filename: deck.h
** Author: Martin Hill
** Date: 11/06/22
** Description: Deck functions
** Input: cards
** Output: shuffled deck
*********************************************************************/


#ifndef DECK_H
#define DECK_H


#include <iostream>
#include <string>
#include <cstdlib>

#include "card.h"

using namespace std;

class Deck{
    private:
        Card cards[52]; //A full deck of cards
        int n_cards; // Number of cards remaining in the deck.
    public:
        Deck(); //default constructor
        //Deck(int n_cards); //non-default constructor
        ~Deck(); //Deck destructor
        void set_n_cards(int);
        void set_card(Card, int);
        int get_n_cards();
        Card get_card(int);
        Card& remove_card();
};

#endif