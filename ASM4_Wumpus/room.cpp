/*********************************************************************
** Program Filename: room.cpp
** Author: Martin Hill
** Date: 11/20/22
** Description: Room functions
** Input: Event* and room_assignment
** Output: room functions
*********************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>

#include "room.h"

using namespace std;

//non-default constructor
Room::Room(int room_assignment){
    //cout << "inside event constructor..." << endl;
    this->room_assignment = room_assignment;
    //this->room_event;
}

void Room::set_event(Event* n){
    this->room_event = n;
}

void Room::print_room_assignment(){
    cout << "room assignment " << this->room_assignment << endl;
}

//getter
Event* Room::get_event(){
    return this->room_event;
}

void Room::delete_event(){
    delete this->room_event;
    this->room_event = NULL;
}