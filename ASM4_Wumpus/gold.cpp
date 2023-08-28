/*********************************************************************
** Program Filename: gold.cpp
** Author: Martin Hill
** Date: 11/20/22
** Description: gold functions
** Input: event
** Output: gold functions
*********************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>

#include "gold.h"

using namespace std;

//constructor
Gold::Gold() : Event(){
    //cout << "inside event constructor..." << endl;
    this->room_assignment = room_assignment;
    this->letter = "g";
}

void Gold::precept(){
    cout << "You see a glimmer nearby." << endl;
};

void Gold::encounter(int* player_x, int* player_y, int* turns, int* gold, int r, int c, int* bats_move){
    cout << "You found the Wumpus' treasure!" << endl;
    *gold = 0;
};