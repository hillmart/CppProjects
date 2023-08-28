/*********************************************************************
** Program Filename: card.cpp
** Author: Martin Hill
** Date: 11/06/22
** Description: Card functions
** Input: card rank and suits
** Output: card with rank and suit
Doesn't need big 3 bc no heap usage
Needs accessor and mutators to access from hand class
*********************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>

#include "card.h"

using namespace std;

//constructor
Card::Card(){
    //cout << "inside constructor..." << endl;
    this->rank = -1;
    this->suit = -1;
}

//constructor
Card::Card(int new_rank, int new_suit){
    //cout << "inside constructor..." << endl;
    this->rank = new_rank;
    this->suit = new_suit;
}

//getters
int Card::get_rank () {
    return this->rank;
}

int Card::get_suit() {
    return this->suit;
}


//setters
void Card::set_rank (int new_rank){
    this->rank = new_rank;
}

void Card::set_suit (int new_suit){
    this->suit = new_suit;
}


//mappers
string Card::map_suit(){
    string suit_string;
    //suit conditional
    if (suit == 0){
        suit_string = "Hearts";
    }
    if (suit == 1){
        suit_string = "Diamonds";
    }
    if (suit == 2){
        suit_string = "Clubs";
    }
    if (suit == 3){
        suit_string = "Spades";
    }
    return suit_string;
}

//maps rank to card name
string Card::map_rank(){
    string rank_string;
    //rank conditional
    if (rank == 0){
        rank_string = "Ace";
    }
    if (rank == 1){
        rank_string = "Two";
    }
    if (rank == 2){
        rank_string = "Three";
    }
    if (rank == 3){
        rank_string = "Four";
    }
    if (rank == 4){
        rank_string = "Five";
    }
    if (rank == 5){
        rank_string = "Six";
    }
    else{
        rank_string = refactoring(rank_string);
    }
    return rank_string;
}

//conditional to get under function line limit, same as map card function
string Card::refactoring(string rank_string){
    if (rank == 6){
        rank_string = "Seven";
    }
    if (rank == 7){
        rank_string = "Eight";
    }
    if (rank == 8){
        rank_string = "Nine";
    }
    if (rank == 9){
        rank_string = "Ten";
    }
    if (rank == 10){
        rank_string = "Jack";
    }
    if (rank == 11){
        rank_string = "Queen";
    }
    if (rank == 12){
        rank_string = "King";
    }
    return rank_string;
}


//printer
void Card::print_card(){
    cout << map_rank() << " of " << map_suit() << endl;
}
