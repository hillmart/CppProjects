/*********************************************************************
** Program Filename: assignment_1.cpp
** Author: Martin Hill
** Date: 10/8/22
** Description: Simulates bowling game for user
** Input: user name and enter key
** Output: bowling rolls and score
*********************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

/*********************************************************************
** Function: initialize
** Description: Greets user and takes in name
** Parameters: none
** Pre-Conditions: nothing, called at start
** Post-Conditions: must press enter to move on
*********************************************************************/ 
string initialize(){

   //seed random number
   srand(time(NULL));

   //initialize name
   string name;

   //greet user and take in name
   cout << "Welcome to bowling!\nWhat's your name? ";
   cin >> name ;
   cout << "Hello " << name << "\n";
   cin.ignore();

   return name;
   }



/*********************************************************************
** Function: enter_roll
** Description: Checks if user pressed enter to roll
** Parameters: none
** Pre-Conditions: srand must have been called
** Post-Conditions: type that comes out and reference
*********************************************************************/ 
void enter_roll(){
   
   //initialize
   int j = 0;
   string key; 

   //get user to press enter
   cout << "Press enter to roll.";
   
   //use while loop and get line to check
   while(j == 0){
      
      getline(cin, key);
      if (key.empty()){
         j = 1;
      }
      else {
         cout << "Please only press enter to roll.";
      } 
   }
}



/*********************************************************************
** Function: roll_one
** Description: Simulates the first roll
** Parameters: i, and first roll array
** Pre-Conditions: gets called at the start of each frame
** Post-Conditions: moves onto scoreboard
*********************************************************************/ 
int roll_one(int i, int first[]){
  
   //print frame number
   cout << "Frame " << i << "...\n";
  
   //get enter to roll
   enter_roll();

   //generate number
   int roll = rand() % 11;

   //assign to first array
   first[i - 1] = roll;

   return first[i-1];
}


/*********************************************************************
** Function: roll_two
** Description: Simulates the second roll
** Parameters: i, first roll array, and second roll array
** Pre-Conditions: first roll wasn't a strike
** Post-Conditions: goes back to scoreboard again
*********************************************************************/ 
int roll_two(int i, int second[], int first[], int score[]){

   //initialize roll holder
   int roll2 = 0;

   //get enter to roll
   enter_roll();
 
   //check if last frame or not, and roll the correct number of pins
   if (first[9] == 10){
      roll2 = rand() % 11;
      score[i-1] += roll2;
   }
   else {
      roll2 = rand() % (11 - first[i-1]);
   }

   //set roll to second array
   second[i-1] = roll2;

   return second[i-1];
}


/*********************************************************************
** Function: rolls
** Description: prints out the individual rolls
** Parameters: first and second roll arrays
** Pre-Conditions: called by scoreboard function
** Post-Conditions: checks tenth frame scoreboard
** Note: 19 lines because it makes more sense to keep them together
*********************************************************************/ 
void rolls(int first[], int second[]){
      
      //loop through scoreboard
      for (int j = 0; j<10; j++){
      
          //gutterball: -
          if (first[j] == 0){
             cout<< " | -";
          }

          //strike: X
          else if (first[j] == 10){
             cout<< " | X";
          }

          //hasn't been rolled yet, left blank
          else if (first[j] == -1){
             cout<< " | ";
          }

          //regular roll
          else {
             cout<< " | "<<first[j];
          }

          //gutterball: -
          if (second[j] == 0){
             cout<< " -";
          }

          //strike: X
          else if (second[j] == 10 && first[j] != 0){
             cout<< " X";
          }

          //spare: /
          else if (first[j]+second[j] == 10){
             cout<< " /";
          }

         //hasn't been rolled yet, left blank
          else if (second[j] == -1){
             cout<< "  ";
          }

         //regular roll
          else {
             cout<< " "<<second[j];
          }
      }
}

/*********************************************************************
** Function: tenth_score
** Description: prints out the third roll on the tenth frame
** Parameters: integer tenth
** Pre-Conditions: int that is either -1 or has a roll value
** Post-Conditions: goes to print total score
*********************************************************************/ 
void tenth_score(int tenth, int second[], int first[]){
      
      //if tenth frame third roll was used, print on scoreboard
      if (tenth != -1){

          //gutterball
          if (tenth == 0){
             cout<< "  -";
          }
 
          //strike
          else if (tenth == 10){
             cout<< "  X";
          }

          //spare
          else if (tenth + second[9] == 10 && second[9] !=10 && (second[9] + first[9] != 10)){
             cout<< "  /";
          }

          //regular roll
          else {
             cout<< "  "<<tenth;
          }
      }      
}


/*********************************************************************
** Function: scoreboard
** Description: prints out the scoreboard
** Parameters: name, i, scoring arrays and tenth frame third roll
** Pre-Conditions: used after rolls
** Post-Conditions: continues with roll or next frame
*********************************************************************/ 
void scoreboard(string name, int i, int score[], int first[], int second[],int tenth){

      //setup
      cout << "Name   |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  | 10  |Total" << endl;
      cout << "-----------------------------------------------------------------------------" << endl;
      cout << name;

      //print out rolls
      rolls(first, second);

      //check if tenth frame third roll used
      tenth_score(tenth, second, first);

      //print out total
      cout<<" | "<<score[i-1] << endl;
 
      //print frame scores     
      cout<< "      ";
      for (int j = 0; j<10; j++){

          if (tenth != -1 && j == 9){
             cout<< "|   "<<score[j];
          }
      
          else if (score[j] == -1){
             cout<< "|    ";
          }

          else {
             cout<< "|   "<<score[j];
          }
      }
      cout<<"|"<< endl;
} 


/*********************************************************************
** Function: tenth_frame
** Description: Simulates the third roll in the tenth frame
** Parameters: name, i, and scoring arrays
** Pre-Conditions: strike or spare in tenth frame
** Post-Conditions: outputs new tenth integer from 0-10
*********************************************************************/ 
int tenth_frame(int i, int tenth, int first[], int second[], string name, int score[]){

      //check if third roll needed
      if ((first[9] == 10)||(first[9] + second[9] == 10)) {

               //get enter to roll
               enter_roll();

               //firgure out how many pins and roll
               if (first[9] == 10){
                  tenth = rand() % (11 - second[9]);
               }

               else {
                  tenth = rand() % 11;
               }

               //print out result
               if (tenth == 0) {
                  cout << "Awe, you got a gutter ball, " << tenth << " pins." << endl;
                  
               }
               else if (tenth == 10) {
                  cout << "You got a strike, " << tenth << " pins." << endl;
               }
               else {
                  cout << "You knocked down " << tenth << " pins" << endl;
                  
               }

               //add to score
               score[i-1] += tenth;

               //print out scoreboard
               scoreboard(name, i, score, first, second, tenth); 
      }
      
      return tenth;
}


/*********************************************************************
** Function: adjust score
** Description: checks for strikes in order to score them correctly
** Parameters: strike pointer, first roll array, score array, and loop counter i
** Pre-Conditions: roll one done, going through conditionals
** Post-Conditions: updates score array
*********************************************************************/ 
void adjust_score(int* strike, int first[], int score[], int i){
  
         if (*strike == 1) {
            score[i-2] += first[i-1];
            if (first[i-3] == 10){
               score[i-3] += first[i-2];
               score[i-2] += first[i-1];
            }
      }
}


/*********************************************************************
** Function: Roll1_condtional
** Description: Simulates a frame of the game
** Parameters: counting pointers, scoring arrays
** Pre-Conditions: roll one of frame done
** Post-Conditions: prints out result
*********************************************************************/ 
void Roll1_conditional(int* strike, int* spare, int* next, int first[], int score[], int i){

         // adjust score if strike or spare
         
         adjust_score(strike, first, score, i);

         if (*spare == 1) {
            score[i - 2] += first[i-1];
            *spare = 0;
         }
 
  
         //prints out result of roll
         if (first[i-1] == 0) {
            cout << "Awe, you got a gutter ball, " << first[i-1] << " pins." << endl;
            *next = 1;
         }
         else if (first[i-1] == 10) {
            cout << "You got a strike, " << first[i-1] << " pins." << endl;
            *next = 0;
            *strike = 1;
            if (i == 10) {
               *next = 1;
            }
         }
         else {
            cout << "You knocked down " << first[i-1] << " pins" << endl;
            *next = 1;
         }
}



/*********************************************************************
** Function: Roll2_condtional
** Description: Simulates second roll of a frame
** Parameters: name, counting variable pointers, scoring arrays
** Pre-Conditions: roll one is not a strike
** Post-Conditions: moves onto next frame
** 17 lines because it didn't make sense to split up the conditional even though it is possible
*********************************************************************/ 
void Roll2_conditional(int* strike, int* spare, int* next, int first[], int score[], int second[], int i, string name, int tenth){

      //checks if roll2 needed
      if (*next == 1) {

         //assigns roll2 to second
         second[i-1] = roll_two(i, second, first, score);
   
         //adjusts counting variables     
         if (second[i-1] + first[i-1] == 10) {
            *spare = 1;
         }
  
         //updates score
         score[i-1] += second[i-1];
   
         //checks if strike and adjusts score
         if (*strike == 1) {
            score[i-2] += second[i-1];
            *strike = 0;
            score[i-1] += second[i-1];
         }
 
         //prints out results
         if (second[i-1] == 0) {
            cout << "Awe, you got a gutter ball, " << second[i-1] << " pins." << endl;
         
         }
         else if (first[i-1] + second[i-1] == 10) {
            cout << "You knocked down " << second[i-1] << " pins, spare!" << endl;
            *spare = 1;
         }
         else {
            cout << "You knocked down " << second[i-1] << " pins" << endl;
         }

         scoreboard(name, i, score, first, second, tenth); 

      }
}


/*********************************************************************
** Function: playagain
** Description: Asks user if they want to play again
** Parameters: None
** Pre-Conditions: Played through whole game
** Post-Conditions: Reruns game loop or end script
*********************************************************************/ 
int playagain(int play_again){

   //intialize variables
   string answer;
   int j = 0;

   //asks question and uses while loop for answer
   cout << "Thanks for playing, would you like to play again? (Y/N): ";
   while(j == 0){   
      getline(cin, answer);
      if (answer == "Y"){
         play_again = 1;
         j = 1;
      }
      else if (answer == "N"){
         play_again = 0;
         j = 1;
      }
      else {
         cout << "Please only type Y or N.";
         j = 0;
      } 
   }
   return play_again;

}


/*********************************************************************
** Function: game
** Description: runs the for loop that runs the game
** Parameters: name, counting variables, and scoring arrays
** Pre-Conditions: script starts or play again selected
** Post-Conditions: game goes to tenth frame
*********************************************************************/ 
void game(int first[], int score[], int second[], int next, int strike, int spare, int tenth, string name){

      //loop through ten frames
      for (int i = 1; i < 11; i++) {
      
         //first roll calls roll_one
         first[i-1] = roll_one(i, first);

         //set score index to roll
         score[i-1] = first[i-1];

         //print out roll result statement
         Roll1_conditional(&strike, &spare, &next, first, score, i);  

         //add up scores
         if (i > 1){
            score[i-1] = score[i-1] + score[i-2];
         } 
   
         //print out scoreboard 
         scoreboard(name, i, score, first, second, tenth);   

         //if roll2 is applicable (no strike) call second roll
         Roll2_conditional(&strike, &spare, &next, first, score, second, i, name, tenth); 

      }

}


/*********************************************************************
** Function: Main
** Description: Runs through the game and play again
** Parameters: none
** Pre-Conditions: #include statements
** Post-Conditions: script is done running after
*********************************************************************/ 
int main() {
   
   //initialize while loop variable
   int play_again = 1;

   //while loop to ask if player wants to play again
   while (play_again == 1){

      //initialize name
      string name = initialize();

      //initialize scoring arrays
      int first[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
      int second[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
      int score[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

      //initialize counting variables
      int next = 0;
      int strike = 0;
      int spare = 0;
      int tenth = -1;


      //call functions

      game(first, score, second, next, strike, spare, tenth, name);

      tenth = tenth_frame(10, tenth, first, second, name, score);

      play_again = playagain(play_again);      

   }

   return 0;


}


