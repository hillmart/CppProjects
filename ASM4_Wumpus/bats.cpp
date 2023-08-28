/*********************************************************************
** Program Filename: bats.cpp
** Author: Martin Hill
** Date: 11/20/22
** Description: Bats functions
** Input: postion, bats_move counter
** Output: member variables
*********************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>

#include "bats.h"

using namespace std;

//constructor
Bats::Bats() : Event(){
    //cout << "inside event constructor..." << endl;
    this->room_assignment = room_assignment;
    this->letter = "b";
}

void Bats::precept(){
    cout << "You hear wings flapping." << endl;
};

void Bats::encounter(int* player_x, int* player_y, int* turns, int* gold, int row, int col, int* bats_move){
    cout << "You got picked up and moved by the super bats!" << endl;
    *player_x = rand()%row;
    *player_y = rand()%col;
    *bats_move = 1;
};