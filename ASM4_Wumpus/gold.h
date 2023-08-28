/*********************************************************************
** Program Filename: gold.h
** Author: Martin Hill
** Date: 11/20/22
** Description: Gold header
** Input: Event
** Output: Gold functions
*********************************************************************/


#ifndef GOLD_H
#define GOLD_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "event.h"

using namespace std;

class Gold : public Event{
    private:
    public:
        Gold(); //Gold constructor
        void precept();
        void encounter(int*, int*, int*, int*, int, int, int*);
};

#endif