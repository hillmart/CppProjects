/*********************************************************************
** Program Filename: wumpus.h
** Author: Martin Hill
** Date: 11/20/22
** Description: Wumpus header
** Input: room_assignment
** Output: wumpus functions
*********************************************************************/


#ifndef WUMPUS_H
#define WUMPUS_H


#include <iostream>
#include <string>
#include <cstdlib>

#include "event.h"

using namespace std;

class Wumpus : public Event {
    private:
    public:
        Wumpus(); //Room constructor
        void precept();
        void encounter(int*, int*, int*, int*, int, int, int*);
};

#endif