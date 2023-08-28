/*********************************************************************
** Program Filename: room.h
** Author: Martin Hill
** Date: 11/20/22
** Description: Room header
** Input: Event* and room_assignment
** Output: room functions
*********************************************************************/


#ifndef ROOM_H
#define ROOM_H


#include <iostream>
#include <string>
#include <cstdlib>

#include "event.h"

using namespace std;

class Room{
    private:
        int room_assignment;
        Event* room_event;
    public:
        Room(int); //Room constructor
        void set_event(Event*);
        void print_room_assignment();
        Event* get_event();
        void delete_event();
};

#endif