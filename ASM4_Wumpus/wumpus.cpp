/*********************************************************************
** Program Filename: wumpus.cpp
** Author: Martin Hill
** Date: 11/20/22
** Description: Wumpus functions
** Input: room_assignment int
** Output: member variables
*********************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>

#include "wumpus.h"

using namespace std;

//constructor
Wumpus::Wumpus() : Event() {
    //cout << "inside wumpus constructor..." << endl;
    //this->room_assignment = room_assignment;
    this->letter = "w";
}

void Wumpus::precept(){
    cout << "You smell a terrible stench." << endl;
};

void Wumpus::encounter(int* player_x, int* player_y, int* turns, int* gold, int r, int c, int* bats_move){
    cout << "The Wumpus ate you." << endl;
    *turns = 0;
};