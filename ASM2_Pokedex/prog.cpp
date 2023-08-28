/*********************************************************************
** Program Filename: prop.cpp
** Author: Martin Hill
** Date: 10/23/22
** Description: File I/O of pokemon database
** Input: dex.txt
** Output: Searches printed to command line or user chosen file
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream> //file stream
#include <cstdlib>

#include "pokemon.h"

using namespace std;

int main()
{
    //string file_name;
    ifstream file;

    //trainer name entry
    string trainer_name;
    trainer_name = trainer(trainer_name);
       
    //cin >> file_name;
    string file_name;
    cout << "Enter the file name of the pokemon list" << endl;
    cin >> file_name;

    //input file object
    file.open(file_name.c_str());

    //check if the file is successfully open
    if (!file.is_open())
    {
        cout << "Error opening the file..." << endl;
    }
    else
    {
        //create pokedex
        Pokedex Gameboy;
        initialize_gameboy(Gameboy, file, trainer_name);

        //loop through options
        int quit = 0;
        while (quit == 0)
        {
            quit = option(Gameboy, file, file_name);
        }

        //free memory
        delete_info(Gameboy);
    }
}
