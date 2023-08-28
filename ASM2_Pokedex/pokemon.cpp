/*********************************************************************
** Program Filename: pokemon.cpp
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


/*********************************************************************
** Function: create_pokemons
** Description: creates array of Pokemon ptrs
** Parameters: num_pokemon
** Pre-Conditions: called to initialize Gameboy.dex
** Post-Conditions: dex needs to be populated
*********************************************************************/ 


Pokemon* create_pokemons(int num_pokemon)
{
    Pokemon* dex_array = new Pokemon [num_pokemon];

    return dex_array;
}


/*********************************************************************
** Function: populate_pokedex_data
** Description: loops through Gameboy.dex and calls populate_pokemon
** Parameters: Gameboy and file
** Pre-Conditions: create_pokemon must have been called
** Post-Conditions: ready for options to be called
*********************************************************************/


void populate_pokedex_data(Pokedex & Gameboy, ifstream & file)
{
    for(int i = 0; i < Gameboy.num_pokemon; i++)
    {
        populate_pokemon(Gameboy.dex[i], file);
    }
}


/*********************************************************************
** Function: create_moves
** Description: creates array of moves within pokemon object
** Parameters: num_moves
** Pre-Conditions: called from populate_pokemon
** Post-Conditions: needs to be populated with moves from file
*********************************************************************/


string* create_moves(int num_moves)
{
    string* moves = new string [num_moves];
    return moves;
}


/*********************************************************************
** Function: populate_pokemon
** Description: fills in individual pokemon objects by reading in file
** Parameters: pokemon object pointer
** Pre-Conditions: called to initialize Gameboy.dex
** Post-Conditions: dex needs to be populated
*********************************************************************/


void populate_pokemon(Pokemon & buddy, ifstream & file)
{
    file >> buddy.dex_num >> buddy.name >> buddy.type >> buddy.num_moves;
    buddy.moves = create_moves(buddy.num_moves);

    for (int i = 0; i < buddy.num_moves; i++)
    {
		    file >> buddy.moves[i];
	}
}


/*********************************************************************
** Function: delete_info
** Description: deletes dex indexes and dex and sets to NULL
** Parameters: Pokdex object
** Pre-Conditions: Pokedex object is populated
** Post-Conditions: Pokedex is set to NULL
*********************************************************************/


void delete_info(Pokedex& Pokedex_object)
{
    //free the mem
	for (int i = 0; i < Pokedex_object.num_pokemon; i++)
	{
        delete [] Pokedex_object.dex[i].moves;
		Pokedex_object.dex[i].moves = NULL;
	}

	//free the poke array
	delete [] Pokedex_object.dex;
	Pokedex_object.dex = NULL;
}


/*********************************************************************
** Function: options_conditional
** Description: determines which option function to call
** Parameters: Pokedex object, file, file_name
** Pre-Conditions: called within while loop, must have populated pokedex
** Post-Conditions: pokedex memory must be freed
*********************************************************************/

int options_conditional(Pokedex & Gameboy, ifstream & file, string file_name, int key, int quit)
{
    //call option function based on input

    if (key == 1)
    {
        option_one(Gameboy, file);
    }
    if (key == 2)
    {
        option_two(Gameboy, file);
    }
    if (key == 3)
    {
        option_three(Gameboy, file);
    }
    if (key == 4)
    {
        option_four(Gameboy, file, file_name);
    }
    if (key == 5)
    {
        quit = 1;
    }

    return quit;
}


/*********************************************************************
** Function: print_options
** Description: prints options user can choose
** Parameters: None
** Pre-Conditions: called at start of options
** Post-Conditions: user enters choice
*********************************************************************/


void print_options()
{
    cout << "---- Pick an option ----" << endl;
    cout << "[1] Search by dex number" << endl;
    cout << "[2] Search by name" << endl;
    cout << "[3] Search by type" << endl;
    cout << "[4] Add new Pokemon" << endl;
    cout << "[5] Quit" << endl;
}


/*********************************************************************
** Function: option
** Description: has user pick otion to execute
** Parameters: Pokedex object, file, file_name
** Pre-Conditions: called within while loop, must have populated pokedex
** Post-Conditions: pokedex memory must be freed
*********************************************************************/


int option(Pokedex & Gameboy, ifstream & file, string file_name)
{
    print_options();

    //initialize variables
    int key; 
    int j = 0;
    int quit = 0;

    //use while loop and get line to check
    while(j == 0)
    {
      cin >> key;  
      if (key <= 5 && key >= 1)
      {
         j = 1;
      }
      else 
      {
         cout << "Please only enter a choice 1-5" << endl;
      } 
    }

    quit = options_conditional(Gameboy, file, file_name, key, quit);

    return quit;
}


/*********************************************************************
** Function: output_to_file
** Description: outputs search result to file
** Parameters: pokemon object and file
** Pre-Conditions: called from search option
** Post-Conditions: outputs file based on users entry
*********************************************************************/


void output_to_file(Pokemon & buddy, ifstream & file)
{
    //open output file
    ofstream file_out;
    cout << "Enter file name: " << endl;
    string file_name;
    cin >> file_name;
    file_out.open(file_name.c_str(), ios::app);

    //print to file
    file_out << "Dex number: " << buddy.dex_num << endl;
    file_out << "Name: " << buddy.name << endl;
    file_out << "Type: " << buddy.type << endl;
    file_out << "Number of moves: " << buddy.num_moves << endl;
    file_out << "Moves: ";

    //print moves
    for (int i = 0; i < buddy.num_moves; i++)
    {
		    file_out << buddy.moves[i] << ", ";
	}
    file_out << endl;
}


/*********************************************************************
** Function: output_to_command
** Description: outputs search result to command line
** Parameters: pokemon object and file
** Pre-Conditions: called from search option
** Post-Conditions: outputs to command line based on users entry
*********************************************************************/


void output_to_command(Pokemon & buddy, ifstream & file)
{
    //print to command line
    cout << "Dex number: " << buddy.dex_num << endl;
    cout << "Name: " << buddy.name << endl;
    cout << "Type: " << buddy.type << endl;
    cout << "Number of moves: " << buddy.num_moves << endl;
    cout << "Moves: ";
    for (int i=0; i<buddy.num_moves; i++)
    {
        cout << buddy.moves[i] << ", ";
    }
    cout << endl;
}


/*********************************************************************
** Function: option_one
** Description: allows the user to search by dex number
** Parameters: pokemon object and file
** Pre-Conditions: called from options
** Post-Conditions: calls output function
*********************************************************************/


void option_one(Pokedex & Gameboy, ifstream & file)
{
    //get user input
    cout << "What dex number would you like to search for? " << endl;
    int dex_number;
    cin >> dex_number;
    int result = 0;

    //loop through pokedex
    for (int i = 0; i < Gameboy.num_pokemon; i++)
	{
        //if it matches
        if (Gameboy.dex[i].dex_num == dex_number)
        {
            //figure out which print function to call
            cout << "Would you like to write the output to a new file [1] or the command window [2]? " << endl;
            int output_option;
            cin >> output_option;
            if (output_option == 1)
            {
                output_to_file(Gameboy.dex[i], file);
            }
            else if (output_option == 2)
            {
                output_to_command(Gameboy.dex[i], file);
            }
            result = 1;
        }
	}
    if (result == 0)
    {
        cout << "Pokemon not found" << endl;
    }
}


/*********************************************************************
** Function: option_two
** Description: allows the user to search by name
** Parameters: pokemon object and file
** Pre-Conditions: called from options
** Post-Conditions: calls output function
*********************************************************************/


void option_two(Pokedex & Gameboy, ifstream & file)
{
    //get user input
    cout << "What name would you like to search for? " << endl;
    string name;
    cin >> name;
    int result = 0;

    //look for match
    for (int i = 0; i < Gameboy.num_pokemon; i++)
	{
        if (Gameboy.dex[i].name == name)
        {
            //figure out which print function to call
            cout << "Would you like to write the output to a new file [1] or the command window [2]? " << endl;
            int output_option;
            cin >> output_option;
            if (output_option == 1)
            {
                output_to_file(Gameboy.dex[i], file);
            }
            else if (output_option == 2)
            {
                output_to_command(Gameboy.dex[i], file);
            }
            result = 1;
        }
	}

    if (result == 0)
    {
        cout << "Pokemon not found" << endl;
    }
}


/*********************************************************************
** Function: type_file_out
** Description: outputs the type search results pokemon to a file
** Parameters: pokemon object and file
** Pre-Conditions: called from option 3
** Post-Conditions: loop type search continues or ends
*********************************************************************/

void type_file_out(Pokemon & buddy, ifstream & file)
{
    cout << "Enter file name: " << endl;
    string file_name;
    cin >> file_name;
    ofstream file_out;
    file_out.open(file_name.c_str(), ios::app);

    file_out << "Dex number: " << buddy.dex_num << endl;
    file_out << "Name: " << buddy.name << endl;
    file_out << "Type: " << buddy.type << endl;
    file_out << "Number of moves: " << buddy.num_moves << endl;
    file_out << "Moves: ";
    for (int i = 0; i < buddy.num_moves; i++)
    {
        file_out << buddy.moves[i] << ", ";
    }
    file_out << endl;
}

/*********************************************************************
** Function: option_three
** Description: allows the user to search by type
** Parameters: pokemon object and file
** Pre-Conditions: called from options
** Post-Conditions: calls output function
*********************************************************************/


void option_three(Pokedex & Gameboy, ifstream & file)
{
    //get user input
    cout << "What type would you like to search for? " << endl;
    string type;
    cin >> type;
    int result = 0;

    //look for match
    for (int i = 0; i < Gameboy.num_pokemon; i++)
	{
        if (Gameboy.dex[i].type == type)
        {
            //figure out which print function to call
            cout << "Would you like to write the output to a new file [1] or the command window [2]? " << endl;
            int output_option;
            cin >> output_option;

            if (output_option == 1)
            {
                type_file_out(Gameboy.dex[i], file);
            }
            else if (output_option == 2)
            {
                output_to_command(Gameboy.dex[i], file);
            }
            result = 1;
        }
	}

    if (result == 0)
    {
        cout << "Pokemon not found" << endl;
    }
}


/*********************************************************************
** Function: new_poke_entry
** Description: takes in user input about new pokemon
** Parameters: pokedex object
** Pre-Conditions: called from option four
** Post-Conditions: temporary pokedex must be output to file and switched to original pokedex
*********************************************************************/


void new_poke_entry(Pokedex & Gameboy_two)
{
    //get input from user
    cout <<  "Dex number: ";
    cin >>Gameboy_two.dex[Gameboy_two.num_pokemon -1].dex_num;
    cout << "Name: ";
    cin >> Gameboy_two.dex[Gameboy_two.num_pokemon -1].name;
    cout << "Type: ";
    cin >> Gameboy_two.dex[Gameboy_two.num_pokemon -1].type;
    cout << "Number of moves: ";
    cin >> Gameboy_two.dex[Gameboy_two.num_pokemon -1].num_moves;
    Gameboy_two.dex[Gameboy_two.num_pokemon-1].moves = create_moves(Gameboy_two.dex[Gameboy_two.num_pokemon-1].num_moves);

    for (int i = 0; i < Gameboy_two.dex[Gameboy_two.num_pokemon -1].num_moves; i++)
    {
        cout <<  "Move: ";
        cin >> Gameboy_two.dex[Gameboy_two.num_pokemon -1].moves[i];
    }

}


/*********************************************************************
** Function: new_poke_file
** Description: outputs file with added pokemon
** Parameters: pokedex object, file, and file_name
** Pre-Conditions: called from option four
** Post-Conditions: outputs new file 
*********************************************************************/

void new_poke_file(Pokedex & Gameboy_two, ifstream & file, string file_name)
{
    //open file
    ofstream file_out;
    file_out << endl;
    file_out.open(file_name.c_str() );
    file_out << Gameboy_two.num_pokemon << endl;

    //print each pokemon to file
    for (int i = 0; i < Gameboy_two.num_pokemon; i ++)
    {
        file_out << Gameboy_two.dex[i].dex_num << " " << Gameboy_two.dex[i].name << " " << Gameboy_two.dex[i].type << " " << Gameboy_two.dex[i].num_moves << endl;
        for (int j = 0; j < Gameboy_two.dex[i].num_moves; j++)
        {
            file_out << Gameboy_two.dex[i].moves[j] << " ";
        }
        file_out << endl;
    }
}


/*********************************************************************
** Function: option_four
** Description: allows the user to add a pokemon
** Parameters: pokemon object, file, and file_name
** Pre-Conditions: called from options
** Post-Conditions: outputs new file and updated pokedex object
*********************************************************************/


void option_four(Pokedex & Gameboy, ifstream & file, string file_name)
{
    //initialize temp dex
    Pokedex Gameboy_two;
    Gameboy_two.num_pokemon = Gameboy.num_pokemon + 1;
    Gameboy_two.dex = create_pokemons(Gameboy_two.num_pokemon);
    for (int i = 0; i < Gameboy.num_pokemon; i++)
    {
        Gameboy_two.dex[i] = Gameboy.dex[i];
    }

    //get new entry from user
    new_poke_entry(Gameboy_two);

    //print to file
    new_poke_file(Gameboy_two, file, file_name);

    //free memory and redo original dex
    delete_info(Gameboy);
    Gameboy.dex = Gameboy_two.dex;
    Gameboy.num_pokemon = Gameboy_two.num_pokemon;
}


/*********************************************************************
** Function: trainer
** Description: creates trainer name string
** Parameters: trainer_name
** Pre-Conditions: trainer_name intialized
** Post-Conditions: trainer name gets assigned to pokedex object
*********************************************************************/


string trainer(string trainer_name)
{
    // welcome and read in file name
    cout << "Welcome to the pokedex" << endl;
    cout << "What is the name of the trainer?" << endl;
    cin >> trainer_name;
    return trainer_name;
}


/*********************************************************************
** Function: initialize_gameboy
** Description: creates gameboy pokedex
** Parameters: Pokedex object, file, trainer_name
** Pre-Conditions: file must be open
** Post-Conditions: outputs populated pokedex
*********************************************************************/


void initialize_gameboy(Pokedex & Gameboy, ifstream & file, string trainer_name)
{
    //dyn array of pokemon
    file >> Gameboy.num_pokemon;
    Gameboy.trainer = trainer_name;
    Gameboy.dex = create_pokemons(Gameboy.num_pokemon);

    populate_pokedex_data(Gameboy, file);
}
