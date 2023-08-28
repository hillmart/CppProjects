/*********************************************************************
** Program Filename: card.h
** Author: Martin Hill
** Date: 11/06/22
** Description: Card header
** Input: card rank and suits
** Output: card with rank and suit
*********************************************************************/


#ifndef CARD_H
#define CARD_H


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Card{
    private:
        int rank; // Should be in the range 0-12.
        int suit; // Should be in the range 0-3.
    public:
        Card(int, int); //Card constructor
        Card(); //default, not needed.
        void set_rank(int);
        int get_rank();
        void set_suit(int);
        int get_suit();
        string map_suit(); //convert the int suit to corresponding string
        string map_rank(); //convert the int rank to corresponding string
        void print_card(); //print the card out
        string refactoring(string);
};

#endif