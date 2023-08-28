/*********************************************************************
** Program Filename: hand.cpp
** Author: Martin Hill
** Date: 11/06/22
** Description: hand functions
** Input: cards
** Output: hand with cards
Needs big 3 bc of heap usage
Needs accessor and mutators to access from player class
*********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

#include "deck.h"
#include "card.h"
#include "game.h"
#include "player.h"
#include "hand.h"

using namespace std;

//constructor
Hand::Hand(){
    //cout << "inside default Hand constructor..." << endl;
    this->n_cards = 0;
	this->cards = NULL;
    this->current_rank_ask = 0;

}

//destructor
Hand::~Hand(){
    //cout << "inside Hand destructor..." << endl;
	if (this->cards != NULL){
		delete [] this->cards;
		this->cards = NULL;
	}
}

//getters
Card* Hand::get_cards () {
    return this->cards;
}

int Hand::get_n_cards() {
    return this->n_cards;
}

//AOO
Hand& Hand::operator=(const Hand& c){
	cout << "inside our Hand AOO..." << endl;
	//member-wise copy
	this->n_cards = c.n_cards;

	//free the memory first 
	if (this->cards != NULL)
		delete [] this->cards;

	//deep copy
	this->cards = new Card [this->n_cards];
	for (int i = 0; i < this->n_cards; ++i)
	{
		this->cards[i] = c.cards[i];
	}

	return *this;
}

//Copy Constructor 
Hand::Hand(const Hand& c){
	//cout << "inside our Hand CC..." << endl;
	//member-wise copy
	this->n_cards = c.n_cards;

	//deep copy
	this->cards = new Card [this->n_cards];
	for (int i = 0; i < this->n_cards; ++i)
	{
		this->cards[i] = c.cards[i];
	}
}


//setters
void Hand::set_cards (int card_index, Card new_card){
    this->cards[card_index] = new_card;
}

void Hand::set_n_cards (int new_n){
    this->n_cards = new_n;
}

/*********************************************************************
** Function: insert_card
** Description: resize array, based off Roger's in class demo
** Parameters: card
** Pre-Conditions: hand intialized
** Post-Conditions: hand has c and n_cards++
*********************************************************************/
void Hand::insert_card(Card& c){
    Card* temp = new Card [this->n_cards + 1];

    for (int i = 0; i < this->n_cards; i++){
        temp[i] = this->cards[i];
    }

    temp[this->n_cards] = c;

    if (this->cards != NULL)
        delete [] this->cards;

    this->cards = temp;

    this->n_cards++;
}

/*********************************************************************
** Function: print hand
** Description: prints hand ranks, gets request
** Parameters: none
** Pre-Conditions: hands drawn
** Post-Conditions: outputs int rank request
*********************************************************************/
int Hand::print_hand(){
    //loop through hand and print options
    for (int i = 0; i < this->n_cards; i++){
        cout << "User Rank: " << this->cards[i].get_rank() << endl;
    }
    //prompt for rank entry
    cout << "Please enter the rank you would like to request: ";
    int rank_request_int;
    int j =0;
    //error check entry
    while(j == 0){
        cin >> rank_request_int;
        if(cin.fail()){
            cin.clear();
            cin.ignore(100000,'\n');
            cout << "Please only enter a rank in your hand: ";
        } 
        else if (match_rank(rank_request_int)){
            j = 1;
        }
        else {
            cout << "Please only enter a rank in your hand: ";
        } 
    }
    return rank_request_int;
}

/*********************************************************************
** Function: match_rank
** Description: loops through hand to see if rank matches
** Parameters: chosen_rank
** Pre-Conditions: hands drawn
** Post-Conditions: outputs bool
*********************************************************************/
int Hand::match_rank(int chosen_rank){
    int matching = 0;
    //loop through hand and see if any cards match
    for (int i = 0; i < this->n_cards; i++){
        if (chosen_rank == this->cards[i].get_rank())
            matching = 1;
    }
    return matching;
}

/*********************************************************************
** Function: remove_rank
** Description: takes rank out of hand and outputs it
** Parameters: rank and card
** Pre-Conditions: rank chosen
** Post-Conditions: card removed and returned
*********************************************************************/
Card& Hand::remove_rank(int chosen_rank, Card& removed_rank, int i){
    //if match, move to back of hand and reduce n_cards
    if (chosen_rank == this->cards[i].get_rank()){
        removed_rank = this->cards[i];
        this->cards[i] = this->cards[n_cards - 1];
        this->n_cards = this->n_cards - 1;  
        i--;
    }
    return removed_rank;
}

/*********************************************************************
** Function: computer_request
** Description: picks request
** Parameters: none
** Pre-Conditions: hand has cards
** Post-Conditions: rank to request outputted
*********************************************************************/
int Hand::computer_request(){
    int output_ask = -1;
    //loop through computer hand to find duplicates, ask for those first
    for (int i=0; i<this->n_cards - 1; i++){
        if (this->cards[i].get_rank() == this->cards[i+1].get_rank()){
            output_ask = this->cards[i].get_rank();
        }
    }
    //if no duplicates ask for random number
    if (output_ask == -1) {
        output_ask = this->cards[rand() % this->n_cards - 1].get_rank();
    }
    return output_ask;
}

/********************************************************************* 
** Function: remove_books
** Description: loops through hand and takes out a book of ranks
** Parameters: i
** Pre-Conditions: inside loop for cards
** Post-Conditions: rank outputted
*********************************************************************/
int Hand::remove_books(int i){
    int rank_to_add = -1;
    int match = 0;

    //loop through hand
    for (int j = 0; j < this->n_cards; j++){
        if (this->cards[i].get_rank() == this->cards[j].get_rank()){
            match = match + 1;
        }
        //if 4 cards match eachother, call remove rank
        if (match == 4){
            rank_to_add = this->cards[i].get_rank();
            int count = this->n_cards;
            for (int k = 0; k < count; k++){
                Card removed_rank;
                removed_rank = remove_rank(rank_to_add, removed_rank, k);
            }
            match = 0;
        }
    }
    return rank_to_add;
}

/********************************************************************* 
** Function: bubble_sort
** Description: sorts hand into ascending order
** Parameters: none
** Pre-Conditions: populated hand
** Post-Conditions: hand is sortet lowest [0] to highest [n_cards -1]
*********************************************************************/
void Hand::bubble_sort(){
    for (int k = 0; k < this->n_cards - 1; k++){    
        for (int j = 0; j < this->n_cards - k - 1; j++){
            if  (this->cards[j].get_rank() > this->cards[j+1].get_rank()){
                //cout << "problem" << endl;
                Card temp = this->cards[j];
                this->cards[j] = this->cards[j+1];
                this->cards[j+1] = temp;
            }
        }
    }
}