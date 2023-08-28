/*********************************************************************
** Program Filename: event.cpp
** Author: Martin Hill
** Date: 11/20/22
** Description: Event functions
** Input: room_assignment int
** Output: member variables
*********************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>

#include "event.h"

using namespace std;

//constructor
Event::Event(){
    //cout << "inside event constructor..." << endl;
    //this->room_assignment = room_assignment;
}

//abstract
void Event::precept(){};

//abstract
void Event::encounter(int* player_x, int* player_y, int* turns, int* gold, int r, int c, int* bats_move){};

//getter
string Event::get_letter(){
    return this->letter;
}

//setter
void Event::set_letter(string new_letter){
    this->letter = new_letter;
}