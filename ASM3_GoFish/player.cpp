/*********************************************************************
** Program Filename: player.cpp
** Author: Martin Hill
** Date: 11/06/22
** Description: player functions
** Input: books and hands
** Output: hand and books
Needs big 3 bc of heap usage
Needs accessor and mutators to access from game class
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
Player::Player(){
    //cout << "inside default Player constructor..." << endl;
    this->books = NULL;
    this->n_books = 0;
}

//destructor
Player::~Player(){
    //cout << "inside Player destructor..." << endl;
	if (this->books != NULL){
		delete [] this->books;
		this->books = NULL;
	}
}

//AOO
Player& Player::operator=(const Player& c){
	cout << "inside our Player AOO..." << endl;
	//member-wise copy
	this->n_books = c.n_books;

	//free the memory first 
	if (this->books != NULL)
		delete [] this->books;

	//deep copy
	this->books = new int [this->n_books];
	for (int i = 0; i < this->n_books; ++i)
	{
		this->books[i] = c.books[i];
	}

	return *this;
}

//Copy Constructor 
Player::Player(const Player& c){
	cout << "inside our Player CC..." << endl;
	//member-wise copy
	this->n_books = c.n_books;

	//deep copy
	this->books = new int [this->n_books];
	for (int i = 0; i < this->n_books; ++i)
	{
		this->books[i] = c.books[i];
	}
}

//getters
Hand Player::get_hand () {
    return this->hand;
}

int* Player::get_books() {
    return this->books;
}

int Player::get_n_books() {
    return this->n_books;
}

//setters
void Player::set_books (int new_book){
    this->books[new_book] = new_book;
}

void Player::set_hand (Hand new_hand){
    this->hand = new_hand;
}

void Player::set_n_books (int new_n_book){
    this->n_books = new_n_book;
}

void Player::place_a_card(Card& c){
    this->hand.insert_card(c);
}

int Player::request_rank(){
    int chosen_rank = this->hand.print_hand();
    return chosen_rank;
}

int Player::computer_request_rank(){
    int chosen_rank = this->hand.computer_request();
    return chosen_rank;
}

int Player::match_rank(int chosen_rank){
    int match_rank = this->hand.match_rank(chosen_rank);
    return match_rank; 
}

/*********************************************************************
** Function: remove_rank
** Description: calls hand remove rank and returned card
** Parameters: chose rank and card c
** Pre-Conditions: rank to remove chosen
** Post-Conditions: outputs card that got removed
*********************************************************************/
Card& Player::remove_rank(int chosen_rank, Card& c, int i){
    Card removed_rank;
    c = this->hand.remove_rank(chosen_rank, removed_rank, i);
    return c;
}

/*********************************************************************
** Function: check_for_books
** Description: loops through players hand and looks for books
** Parameters: none
** Pre-Conditions: hand populated and turns done
** Post-Conditions: ranks in book removed from hand
*********************************************************************/
void Player::check_for_books(){
    for (int i = 0; i < this->hand.get_n_cards(); i++){
        int rank_to_add = this->hand.remove_books(i);
        if (rank_to_add != -1){
            int* temp = new int [this->n_books + 1];

            for (int i = 0; i < this->n_books; i++){
                temp[i] = this->books[i];
            }

            temp[this->n_books] = rank_to_add;

            if (this->books != NULL)
                delete [] this->books;

            this->books = temp;

            this->n_books++; 
            cout << rank_to_add << " book earned." << endl;
        }
    }
}

//calls bubble sort function in hand
void Player::bubble_sort_hand(){
    this->hand.bubble_sort();
}