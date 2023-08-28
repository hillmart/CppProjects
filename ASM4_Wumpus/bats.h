/*********************************************************************
** Program Filename: bats.h
** Author: Martin Hill
** Date: 11/20/22
** Description: bats header
** Input: event class
** Output: bat class
*********************************************************************/


#ifndef BATS_H
#define BATS_H


#include <iostream>
#include <string>
#include <cstdlib>
#include "event.h"

using namespace std;

class Bats : public Event{
    private:
        //Event room_event;
    public:
        Bats(); //Room constructor
        void precept();
        void encounter(int*, int*, int*, int*, int, int, int*);
};

#endif