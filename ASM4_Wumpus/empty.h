/*********************************************************************
** Program Filename: empty.h
** Author: Martin Hill
** Date: 11/20/22
** Description: Empty event
** Input: Event
** Output: nothing
*********************************************************************/


#ifndef EMPTY_H
#define EMPTY_H


#include <iostream>
#include <string>
#include <cstdlib>

#include "event.h"

using namespace std;

class Empty : public Event {
    private:
    public:
        Empty(); //Empty constructor
        void precept();
        void encounter(int*, int*, int*, int*, int, int, int*);
};

#endif