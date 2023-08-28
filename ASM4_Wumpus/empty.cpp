/*********************************************************************
** Program Filename: empty.cpp
** Author: Martin Hill
** Date: 11/20/22
** Description: Empty event
** Input: Event
** Output: nothing
*********************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>

#include "empty.h"

using namespace std;

//constructor
Empty::Empty() : Event() {
    //cout << "inside wumpusd constructor..." << endl;
    //this->room_assignment = room_assignment;
    this->letter = " ";
}

void Empty::precept(){};

void Empty::encounter(int* player_x, int* player_y, int* turns, int* gold, int r, int c, int* bats_move){};