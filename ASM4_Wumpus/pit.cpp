/*********************************************************************
** Program Filename: pit.cpp
** Author: Martin Hill
** Date: 11/20/22
** Description: Pit functions
** Input: Event
** Output: Pit functions
*********************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>

#include "pit.h"

using namespace std;

//constructor
Pit::Pit() : Event(){
    //cout << "inside event constructor..." << endl;
    this->room_assignment = room_assignment;
    this->letter = "p";
}

void Pit::precept(){
    cout << "You feel a breeze." << endl;
};

void Pit::encounter(int* player_x, int* player_y, int* turns, int* gold, int r, int c, int* bats_move){
    cout << "You fell in a bottomless pit." << endl;
    *turns = 0;
};