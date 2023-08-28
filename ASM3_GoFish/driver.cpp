/*********************************************************************
** Program Filename: driver.cpp
** Author: Martin Hill
** Date: 11/06/22
** Description: Calls functions in order to run go fish
** Input: game class
** Output: gameplay for user
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

/*********************************************************************
** Function: set_up
** Description: shuffle and deal
** Parameters: Game
** Pre-Conditions: Game initialized
** Post-Conditions: deck is shuffled and hands are dealt
*********************************************************************/
void set_up(Game& first){
    //shuffle deck
    first.shuffle_d();

    //deal hands
    for (int i = 0; i < 7; i++){
        first.draw_cards(0);
        first.draw_cards(1);
    }
}

/*********************************************************************
** Function: debug_print
** Description: prints game state if in debug mode
** Parameters: Game, debug
** Pre-Conditions: debug chosen, in turn loop
** Post-Conditions: print statements
*********************************************************************/
void debug_print(Game& first, int debug){
    if (debug){
    for (int i = 0; i < first.get_players()[1].get_hand().get_n_cards(); i++){
        cout << "Computer Rank: " << first.get_players()[1].get_hand().get_cards()[i].get_rank() << endl;
    }
    for (int i = 0; i < first.get_players()[0].get_n_books(); i++){
        cout << "User book: " << first.get_players()[0].get_books()[i] << endl;
    }
    for (int i = 0; i < first.get_players()[1].get_n_books(); i++){
        cout << "Computer book: " << first.get_players()[1].get_books()[i] << endl;
    }
    cout << "Number of cards left in deck: " << first.get_d().get_n_cards()<< endl;
    }
}


/*********************************************************************
** Function: turn_loop
** Description: loops through turn order until all books are found
** Parameters: Game, debug
** Pre-Conditions: deck shuffled, hand dealt, and debug chosen
** Post-Conditions: books full
*********************************************************************/
void turn_loop(Game& first, int debug){
    //loop until all books found
    while (first.get_players()[0].get_n_books() + first.get_players()[1].get_n_books() < 13){
        first.bubble_sort_player(0);
        first.bubble_sort_player(1);

        debug_print(first, debug);

        first.user_turn();

        first.bubble_sort_player(0);

        first.computer_turn();

        first.bubble_sort_player(0);
        first.bubble_sort_player(1);

        first.check_for_books();
    }
}

/*********************************************************************
** Function: announce_winner
** Description: prints out who won
** Parameters: game
** Pre-Conditions: turn loop done
** Post-Conditions: print statement
*********************************************************************/
void announce_winner(Game& first){
    //announce winner
    if (first.get_players()[0].get_n_books() > first.get_players()[1].get_n_books()){
        cout << "You win " << first.get_players()[0].get_n_books() << " to "<< first.get_players()[1].get_n_books() << endl;
    }
    else {
        cout << "The computer won "<< first.get_players()[1].get_n_books() << " to "<< first.get_players()[0].get_n_books() << endl;
    }
}

/*********************************************************************
** Function: main
** Description: loops through play and calls turn loop
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: ends program at end
*********************************************************************/
int main()
{
    //seed random number
    srand(time(NULL));

    //declare play again counter
    int play_again = 1;

    //start game
    while (play_again == 1){

        //prompt for debug mode
        cout << "Play in debug mode? Yes = 1, No = 0" << endl;
        int debug;
        cin >> debug;

        //declare game object
        Game first;

        //set_up game
        set_up(first);

        //loop through the turns
        turn_loop(first, debug);

        //calc and print out who won
        announce_winner(first);

        //prompt to play again or quit
        cout << "Play again? 1 = yes, 0 = no" << endl;
        cin >> play_again;

    }
   cout << "Thanks for playing!" << endl;
}
