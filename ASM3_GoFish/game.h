/*********************************************************************
** Program Filename: game.h
** Author: Martin Hill
** Date: 11/06/22
** Description: game functions
** Input: deck and players
** Output: deck and players
*********************************************************************/

#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <string>
#include <cstdlib>

#include "deck.h"
#include "player.h"

using namespace std;

class Game{
    private:
        Deck d;
        Player players[2];
    public:
        Game(); //Desk constructor
        ~Game(); //Deck destructor
        void set_d(Deck);
        Deck get_d();
        void set_players(Player, int);
        Player* get_players();
        void shuffle_d();
        void draw_cards(int);
        void user_turn();
        void computer_turn();
        void check_for_books();
        void bubble_sort_player(int);
        void find_card(int);
        void go_fishing(int);
        void if_match(int);
        void else_match(int);
};

#endif