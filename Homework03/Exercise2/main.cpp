/*
* Author: Cole Barbes
* Creation Date: 02/28/23
* Last update: 03/02/23
* Description: This main program implements two classes the die class and the 2d array class.
* The goal of this program is to find the sums of 2 d6 dice a user selected amount of times for a user selected amount of trials.
* User Interface: simple input output
* Notes: this file is the main code for this project, as the classes are snipped from other projects
*/
#include <iostream>
#include <cstdlib>    
#include <ctime>      // import to set the seed 

#include "Die.h"
#include "Array2D.h"

using namespace std; 

//below are prototypes and a short description

bool rollCheck(Array2D &, int, int, int); // a recursive checker for the array, just for fun :)
void diceRoller(Array2D &, int, int); // dice roller to roll the dice

//

int main() 
{
    srand(time(0));// set the seed

    Array2D Simulation; // create the Array 

    int trials = 0; // hold the user input for the trial num
    int rolls = 0; // hold the user input for the rolls num
    int count = 0; // count the occurences of a matching roll
    bool checker = false; // boolean for the checker to be sent into

    //take the input
    cout<<"Please enter the number of trials: "<<endl; 
    cin>>trials;
    cout<<"Please enter the number of rolls per trial: "<<endl;
    cin>>rolls;
    //
    
    // while loop to make sure the input is not invalid
    while(trials < 1 && rolls < 1){
        cout<<"You cannot do 0 trials or 0 rolls"<<endl;
        cout<<"Please enter the number of trials: "<<endl;
        cin>>trials;
        cout<<"Please enter the number of rolls per trial: "<<endl;
        cin>>rolls;
    }
    //

    Simulation.resize(trials, rolls); // call the resize function to form the new array

    diceRoller(Simulation, trials, rolls); // roll the dice

    // for loop to check each row if so print for debug purposes
    for(int i = 0; i<trials; i++){
        checker = rollCheck(Simulation, i, 0, Simulation.get(i, 0));
        if(checker){ 
            count++;
            Simulation.rowPrint(i);
        }
    }
    //

    cout<<"Number of trials resulting in the same roll value was "<<count<<"."<<endl;

    return 0;
}

/*
* Return Type: Boolean
* Parameters: Referance to an array2D in memory, integer for row num and int for cols, and the starting value
* Description: This recursive function checks a trial for matching results
* The purpose of this function was to practice recursion.
*/
bool rollCheck(Array2D &Arr, int t, int y, int value)
{
    // if equal and not end case loop back through the function
    if(Arr.get(t, y)==value&& y<(Arr.getCols()-1)){
        return rollCheck(Arr, t, y+1, value);
    }
    // if equal and the last case return true;
    else if(Arr.get(t, y)==value&&y==(Arr.getCols()-1)){
        return true;
    }
    //if not just return false
    else{
        return false;
    }
}

/*
* Return Type: void no return
* Parameters: Reference to an array2D in memory, integers for rows and cols
*/
void diceRoller(Array2D & S, int trials, int rolls)
{
    Die d1;// variable for the first die
    Die d2;// variable for the second die

    // loop through the array and set the summed rolls into it
    for(int i = 0; i<trials; i++)
    {
        for(int j = 0; j<rolls; j++)
        {
            d1.roll();
            d2.roll();
            S.set(i, j, (d1.getValue()+d2.getValue()));
        }
    }
}