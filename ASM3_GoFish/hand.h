/*********************************************************************
** Program Filename: hand.h
** Author: Martin Hill
** Date: 11/06/22
** Description: hand functions
** Input: cards
** Output: hand with cards
*********************************************************************/

#ifndef HAND_H
#define HAND_H


#include <iostream>
#include <string>
#include <cstdlib>

#include "card.h"

using namespace std;

class Hand{
    private:
        Card* cards; // An array of cards in hand
        int n_cards; // Number of cards in the hand.
        int current_rank_ask; // Index computer is asking for
    public:
        Hand(); //Card constructor
        ~Hand(); //Deck destructor
        Hand& operator=(const Hand&); //Assignment operator overload (AOO) 
        Hand(const Hand&); //Copy constructor
        void set_cards(int, Card);
        Card* get_cards();
        void set_n_cards(int);
        int get_n_cards();
        void insert_card(Card&);
        int print_hand();
        int match_rank(int);
        Card& remove_rank(int, Card&, int);
        int computer_request();
        int remove_books(int);
        void bubble_sort();
        void eater(int, int);
};

#endif