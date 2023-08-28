/*********************************************************************
** Program Filename: event.h
** Author: Martin Hill
** Date: 11/20/22
** Description: Event header
** Input: Base event class
** Output: None
*********************************************************************/


#ifndef EVENT_H
#define EVENT_H


#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;

class Event{
    protected:
        int room_assignment;
        string letter;
    public:
        Event(); //Event constructor
        virtual void precept() = 0;
        virtual void encounter(int*, int*, int*, int*, int, int, int*) = 0;
        virtual string get_letter();
        virtual void set_letter(string);
};

#endif