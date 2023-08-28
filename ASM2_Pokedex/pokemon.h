/*********************************************************************
** Program Filename: pokemon.h
** Author: Martin Hill
** Date: 10/23/22
** Description: Header file with functions
** Input: dex.txt
** Output: Searches printed to command line or user chose file
*********************************************************************/


#include <iostream>
#include <string>
#include <fstream> //file stream
#include <cstdlib>

using namespace std;

struct Pokemon 
{
    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;
};

struct Pokedex 
{
    string trainer;
    int num_pokemon;
    Pokemon* dex;
};

//Required functions

Pokemon* create_pokemons(int size);

void populate_pokedex_data(Pokedex & Gameboy, ifstream & file);

string* create_moves(int num_moves);

void populate_pokemon(Pokemon & buddy, ifstream & file);

void delete_info(Pokedex & Pokedex_object);

//option functions

int option(Pokedex & Gameboy, ifstream & file, string file_name);

void output_to_file(Pokedex & Gameboy, ifstream & file, string file_name);

void output_to_command(Pokedex & Gameboy, ifstream & file);

void option_one(Pokedex & Gameboy, ifstream & file);

void option_two(Pokedex & Gameboy, ifstream & file);

void option_three(Pokedex & Gameboy, ifstream & file);

void option_four(Pokedex & Gameboy, ifstream & file, string file_name);

//refactored main functions

string trainer(string trainer_name);

void initialize_gameboy(Pokedex & Gameboy, ifstream & file, string trainer_name);

//refactored option functions

void new_poke_file(Pokedex & Gameboy_two, ifstream & file, string file_name);

void new_poke_entry(Pokedex & Gameboy_two);

void type_file_out(Pokemon & buddy, ifstream & file);

int options_conditional(Pokedex & Gameboy, ifstream & file, string file_name, int key, int quit);

void print_options();