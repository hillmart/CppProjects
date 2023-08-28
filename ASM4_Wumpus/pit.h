/*********************************************************************
** Program Filename: pit.h
** Author: Martin Hill
** Date: 11/20/22
** Description: Pit header
** Input: Event
** Output: Pit functions
*********************************************************************/


#ifndef PIT_H
#define PIT_H


#include <iostream>
#include <string>
#include <cstdlib>
#include "event.h"

using namespace std;

class Pit : public Event{
    private:
    public:
        Pit(); //Pit constructor
        void precept();
        void encounter(int*, int*, int*, int*, int, int, int*);
};

#endif