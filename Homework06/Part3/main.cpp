
#include "Vector2D.h"
#include "Array2D.h"
#include "Die.h"
#include <iostream>

using namespace std;

bool rollCheck(Vector2D<Die>&, int, int, Die);
bool rollCheck(Array2D<Die>&, int, int, Die);

int main()
{
    srand(time(0));
    int numTry = 0;
    int numRolls = 0;
    bool printer = false;
    bool checker = false;
    char checkPrint;
    int count = 0;
    bool vectOrArr = false;

    cout<<"Would you like to use a 2D vector or a 2D array of pointers? (0 for vector and 1 for array of pointers) ";
    cin>>vectOrArr;

    cout<<"Input the number of trials: ";
    cin>>numTry;

    cout<<"Input the number of dice for each trial: ";
    cin>>numRolls;

    cout<<"Do you want to display the array (Y/N): ";
    cin>>checkPrint;

    if(checkPrint=='y'||checkPrint == 'Y'){ printer = true; }

    Die Def;
    if(vectOrArr){
        Array2D<Die> dieArr(numTry, numRolls, Def);
        for(int i = 0; i<numTry; i++)
        {
            for(int j = 0; j<numRolls; j++)
            {
                dieArr[i][j].roll();
            }
        }

        // for loop to check each row if so print for debug purposes
        for(int i = 0; i<numTry; i++){
            checker = rollCheck(dieArr, i, 0, dieArr.get(i, 0));
            if(checker){ 
                count++;
            }
        }
        //

        if(printer){
            for(int i = 0; i<numTry; i++){
                for(int j = 0; j<numRolls; j++){
                    cout<<dieArr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        cout<<"There were "<<count<<" matches of equal die in the "<<numTry<<" trials of the simulation."<<endl;
    }
    else{
        Vector2D<Die> dieArr(numTry, numRolls, Def);
        for(int i = 0; i<numTry; i++)
        {
            for(int j = 0; j<numRolls; j++)
            {
                dieArr[i][j].roll();
            }
        }

        // for loop to check each row if so print for debug purposes
        for(int i = 0; i<numTry; i++){
            checker = rollCheck(dieArr, i, 0, dieArr.get(i, 0));
            if(checker){ 
                count++;
            }
        }
        //

        if(printer){
            for(int i = 0; i<numTry; i++){
                for(int j = 0; j<numRolls; j++){
                    cout<<dieArr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        cout<<"There were "<<count<<" matches of equal die in the "<<numTry<<" trials of the simulation."<<endl;
    }

    

    return 0;


}

/*
* Return Type: Boolean
* Parameters: Referance to an array2D in memory, integer for row num and int for cols, and the starting value
* Description: This recursive function checks a trial for matching results
* The purpose of this function was to practice recursion.
*/
bool rollCheck(Vector2D<Die> &Arr, int t, int y, Die value)
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
* Return Type: Boolean
* Parameters: Referance to an array2D in memory, integer for row num and int for cols, and the starting value
* Description: This recursive function checks a trial for matching results
* The purpose of this function was to practice recursion.
*/
bool rollCheck(Array2D<Die> &Arr, int t, int y, Die value)
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