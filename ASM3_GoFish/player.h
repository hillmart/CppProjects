/*********************************************************************
** Program Filename: player.cpp
** Author: Martin Hill
** Date: 11/06/22
** Description: player functions
** Input: books and hands
** Output: hand and books
Big three needed because of book dynamic array
*********************************************************************/

#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <string>
#include <cstdlib>

#include "hand.h"
using namespace std;

class Player{
    private:
        Hand hand;
        int* books; // Array with ranks for which the player has books.
        int n_books;
    public:
        Player(); //Player constructor
        ~Player(); //Player destructor
        Player& operator=(const Player&); //Assignment operator overload (AOO) 
        Player(const Player&); //Copy constructor
        void set_hand(Hand);
        Hand get_hand();
        void set_books(int);
        int* get_books();
        void set_n_books(int);
        int get_n_books();
        void place_a_card(Card&);
        int request_rank();
        int match_rank(int);
        Card& remove_rank(int, Card&, int);
        int computer_request_rank();
        void check_for_books();
        void bubble_sort_hand();
};

#endif