/*********************************************************************
** Program Filename: driver.cpp
** Author: Martin Hill
** Date: 11/20/22
** Description: Calls functions in order to run hunt the wumpus
** Input: room class and event class
** Output: gameplay for user
*********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"
#include "empty.h"

using namespace std;

//moves wumpus 75% of time to random new room thats empty
template <class P>
void swap_wumpus(int row, int col, P rooms, int i, int j){
    //cout << "wumpus will change rooms" << endl;
    int r = rand()%row;
    int c = rand()%col;
    if ((*rooms)[r][c].get_event()->get_letter() == " "){
        swap((*rooms)[i][j],(*rooms)[r][c]);
        //cout << "Wumpus moved rooms" << endl;
    }
    else {
        swap_wumpus(row, col, rooms, i, j);
    }
}

//loops through the arrow movement based on the entry
template <class T>
int arrow_eval(string action, int player_x, int player_y, int row, int col, int* wumpus_dead, T *rooms, Event* empty_1, int* wumpus_x, int* wumpus_y, int* arrow_counter){
    int arrow = 0;

    //runs if still has arrows left
    if (*arrow_counter < 3){

        //up direction
        if (action == " w"){

            //moves three rooms
            for (int i = 1; i < 4; i++){
                if (player_x - i > -1){
                    if ((*rooms)[player_x - i][player_y].get_event()->get_letter() == "w"){
                        cout << "You killed the wumpus." << endl;
                        (*rooms)[player_x - i][player_y].set_event(empty_1);
                        *wumpus_x = player_x - i;
                        *wumpus_y = player_y;
                        *wumpus_dead = 1;
                    }
                }
            }

            //gives wumpus chance to move if you miss
            if (*wumpus_dead == 0){
                cout << "You missed the wumpus." << endl;
                for (int i = 0; i < row; i++){
                    for (int j = 0; j < col; j++){
                        if ((*rooms)[i][j].get_event()->get_letter() == "w"){
                            if(rand()%3>0){
                                swap_wumpus(row, col, rooms, i, j);
                            }
                        }
                    }
                } 
            }
            //cout << "You shot an arrow upwards." << endl;
            arrow = 1;
            *arrow_counter = *arrow_counter + 1;
        }

        //down direction
        if (action == " s"){
            for (int i = 1; i < 4; i++){
                if (player_x + i < row){
                    if ((*rooms)[player_x + i][player_y].get_event()->get_letter() == "w"){
                        cout << "You killed the wumpus." << endl;
                        (*rooms)[player_x + i][player_y].set_event(empty_1);
                        *wumpus_x = player_x + i;
                        *wumpus_y = player_y;
                        *wumpus_dead = 1;
                    }
                }
            }
            if (*wumpus_dead == 0){
                cout << "You missed the wumpus." << endl;
                for (int i = 0; i < row; i++){
                    for (int j = 0; j < col; j++){
                        if ((*rooms)[i][j].get_event()->get_letter() == "w"){
                            if(rand()%3>0){
                                swap_wumpus(row, col, rooms, i, j);
                            }
                        }
                    }
                } 
            }
            arrow = 1;
            *arrow_counter = *arrow_counter + 1;
        }

        //left direction
        if (action == " a"){
            for (int i = 1; i < 4; i++){
                if (player_y - i > -1){
                    if ((*rooms)[player_x][player_y - i].get_event()->get_letter() == "w"){
                        cout << "You killed the wumpus." << endl;
                        (*rooms)[player_x][player_y - i].set_event(empty_1);
                        *wumpus_x = player_x;
                        *wumpus_y = player_y - i;
                        *wumpus_dead = 1;
                    }
                }
            }
            if (*wumpus_dead == 0){
                cout << "You missed the wumpus." << endl;
                for (int i = 0; i < row; i++){
                    for (int j = 0; j < col; j++){
                        if ((*rooms)[i][j].get_event()->get_letter() == "w"){
                            if(rand()%3>0){
                                swap_wumpus(row, col, rooms, i, j);
                            }
                        }
                    }
                } 
            }
            arrow = 1;
            *arrow_counter = *arrow_counter + 1;
        }

        //right direction
        if (action == " d"){
            for (int i = 1; i < 4; i++){
                if (player_y + i < row){
                    if ((*rooms)[player_x][player_y + i].get_event()->get_letter() == "w"){
                        cout << "You killed the wumpus." << endl;
                        (*rooms)[player_x][player_y + i].set_event(empty_1);
                        *wumpus_x = player_x;
                        *wumpus_y = player_y + i;
                        *wumpus_dead = 1;
                    }
                }
            }
            if (*wumpus_dead == 0){
                cout << "You missed the wumpus." << endl;
                for (int i = 0; i < row; i++){
                    for (int j = 0; j < col; j++){
                        if ((*rooms)[i][j].get_event()->get_letter() == "w"){
                            if(rand()%3>0){
                                swap_wumpus(row, col, rooms, i, j);
                            }
                        }
                    }
                } 
            }
            arrow = 1;
            *arrow_counter = *arrow_counter + 1;
        }
    }

    //prints if you run out of arrows
    else if (action == " w" || action == " a" || action == " s" || action == " d"){
        cout << "You ran out of arrows." << endl;
    }
    return arrow;
}

//conditionals that move the player based on action entry
void action_eval(string action, int* player_x, int* player_y, int row, int col){
    //cout << player_x << endl;

    //up
    if (action == "w"){
        if (*player_x > 0){
            *player_x = *player_x - 1;
        }
        //makes sure not at top of cave
        else {
            cout << "invalid move. please enter a different move: ";
            cin >> action;
            action_eval(action, player_x, player_y, row, col);
            action = "w";
        }
    }

    //down
    if (action == "s"){
        if (*player_x != row - 1){
            *player_x = *player_x + 1;
        }
        //makes sure not on bottom side of cave
        else {
            cout << "invalid move. please enter a different move: ";
            cin >> action;
            action_eval(action, player_x, player_y, row, col);
            action = "s";
        }
    }

    //left
    if (action == "a"){
        if (*player_y > 0){
            *player_y = *player_y - 1;
        }
        //makes sure player isnt on left side of cave
        else {
            cout << "invalid move. please enter a different move: ";
            cin >> action;
            action_eval(action, player_x, player_y, row, col);
            action = "a";
        }
    }

    //right 
    if (action == "d"){
        if (*player_y != col - 1){
            *player_y = *player_y + 1;
        }
        //makes sure player isnt on right side of cave
        else {
            cout << "invalid move. please enter a different move: ";
            cin >> action;
            action_eval(action, player_x, player_y, row, col);
        }
    }
}

//shuffles rooms
template <class T>
void shuffle_vector(T* rooms, int row, int col){
    //shuffle vector
    for (int i = 0; i < 100; i++){
        int index_1 = rand()%row;
        int index_2 = rand()%col;
        Room temp = (*rooms)[index_1][index_2];
        int index_3 = rand()%row;
        int index_4 = rand()%col;
        (*rooms)[index_1][index_2] = (*rooms)[index_3][index_4];
        (*rooms)[index_3][index_4] = temp;
    }
}

int main()
{
    //seed random number
    srand(time(NULL));

    cout << "How many rooms would you like along the length of the grid? ";
    int num_rooms;
    cin >> num_rooms;

    //initialize events
    Event *wumpy = new Wumpus();
    Event *treasure = new Gold();
    Event *pit_1 = new Pit();
    Event *pit_2 = new Pit();
    Event *bat_1 = new Bats();
    Event *bat_2 = new Bats();
    Event *empty_1 = new Empty();


    //create vector
    int row = num_rooms;
    int col = num_rooms;
    vector <vector<Room> > rooms;
    for (int i = 0; i < row; i++){
        vector<Room> room_vec;
        for (int j = 0; j < col; j++){
            Room cave_room(i * j);
            room_vec.push_back(cave_room);
            cave_room.set_event(empty_1);
        }
        rooms.push_back(room_vec);
    } 

    //fill vector
    (rooms)[0][0].set_event(wumpy);
    (rooms)[0][1].set_event(treasure);
    (rooms)[0][2].set_event(pit_1);
    (rooms)[0][3].set_event(pit_2);
    (rooms)[1][0].set_event(bat_1);
    (rooms)[1][1].set_event(bat_2);

    shuffle_vector(&rooms, row, col);

    //play loop
    int play_again = 1;
    while (play_again){

        //intialize
        int debug;
        int player_x = rand()%row;
        int player_y = rand()%col;
        int rope_x = player_x;
        int rope_y = player_y;
        int turns = 1;
        int gold = 1;
        int bats_move = 0;
        int arrow = 0;
        int wumpus_dead = 0;
        int rope = 0;
        int wumpus_x;
        int wumpus_y;
        int arrow_counter = 0;

        //debug prompt
        cout << "Play in debug mode? (1 = Yes, 0 = No) ";
        cin >> debug;

        cout << "Enter wasd to move or ' ' + wasd to shoot an arrow (ex. ' s')" << endl;
        cin.ignore();

        //turn while loop
        while (turns){
            bats_move = 0;

            //debug print
            if (debug){
                for (int i = 0; i < row; i++){
                    for (int j = 0; j < col; j++){
                        if (player_x == i && player_y == j){
                            cout << "| x ";
                        }
                        else {
                            cout << "| " << (rooms)[i][j].get_event()->get_letter() << " ";
                        }
                    }
                    cout << "|" << endl;
                } 
            }
            //regular print
            else{
                for (int i = 0; i < row; i++){
                    for (int j = 0; j < col; j++){
                        if (player_x == i && player_y == j){
                            cout << "| x ";
                        }
                        else {
                            cout << "|   ";
                        }
                    }
                    cout << "|" << endl;
                } 
            }
            //cout << turns << bats_move << endl;

            //check precepts
            if (player_x>0){
                (rooms)[player_x - 1][player_y].get_event()->precept();
            }
            if (player_x<row-1){
                (rooms)[player_x + 1][player_y].get_event()->precept();
            }
            if (player_y > 0){
                (rooms)[player_x][player_y - 1].get_event()->precept();
            }
            if (player_y<row-1){
                (rooms)[player_x][player_y + 1].get_event()->precept();
            }

            //check event triggers
            (rooms)[player_x][player_y].get_event()->encounter(&player_x, &player_y, &turns, &gold, row, col, &bats_move);

            //cout << bats_move << endl;

            //takes in player action
            if (turns == 1 && bats_move == 0){
                //cout << "Evaluating Actions" << endl;

                //action intake
                string action;
                getline(cin, action);
                
                //action evaluation
                arrow = arrow_eval(action, player_x, player_y, row, col, &wumpus_dead, &rooms, empty_1, &wumpus_x, &wumpus_y, &arrow_counter);
                if (arrow == 0){
                    action_eval(action, &player_x, &player_y, row, col);
                }
            }

            // cout << "player_x: " << player_x << " " << "player_y: " << player_y << endl;
            // cout << "rope_x: " << rope_x << " " << "rope_y: " << rope_y << endl;
            // cout << "gold: " << gold << " " << "wumpus_dead: " << wumpus_dead << endl;

            //checks to end loop if player killed wumpus, has gold, and on starting square
            if (player_x == rope_x && player_y == rope_y && gold == 0 && wumpus_dead == 1){
                turns = 0;
                rope = 1;
            }
        }

        //checks if player won or lost
        if (gold == 0 && wumpus_dead == 1 && rope){
            cout << "you won." << endl;
        }
        if (gold == 1 || wumpus_dead == 0){
            cout << "you lost." << endl;
        }

        //asks to play again
        cout << "Would you like to play again (2 for same map, 1 for yes, 0 for no)? ";
        cin >> play_again;
        if (play_again == 2){
            (rooms)[wumpus_x][wumpus_y].set_event(wumpy);
        }
        else{
            (rooms)[wumpus_x][wumpus_y].set_event(wumpy);
            shuffle_vector(&rooms, row, col);
        }
    }

    //free memory
    for (int i = 0; i < rooms.size(); i++){
        for (int j = 0; j < rooms.size(); j++){
            (rooms)[i][j].delete_event();
            //(rooms)[i][j] = NULL;
        }
    }

    cout << "Thanks for playing" << endl;
}
