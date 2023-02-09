/************************************************************************************************************
 *  Author: <Cole Barbes>
*   Creation Date: <02/09/23>
*   Last Update: <02/09/23>
*   Description: <The expressed purpose of this program is to create a dice roller. 
*                 Which will ask the user to enter the amount of dice to roll and the amount of rolls.>
*   User Interface: <One use>
*   Notes: <Cosc 220 is fun, take it some time. >
 ************************************************************************************************************/
#include <iostream>
#include <ctime>
using namespace std;

// main function to which all code is executed
int main()
{
    srand(time(0));
    int size; //Hold size of array
    int range;//Hold Range of n random nums
    int* randomUserArray;//Array to hold the nums
    int* counts;//array for amount of each rand
    char printVerif;//Hold the yes or no answer for printing
    
    //The below blocks take all necessary input from the user
    cout<<"Input the number of rolls: ";
    cin>>size;
    cout<<endl;
    
    cout<<"Input the number of dice: ";
    cin>>range;
    cout<<endl; 
    
    cout<<"Do you want to print out the array? (Y/N) :";
    cin>>printVerif;
    cout<<endl;
    //end of user input blocks
    
    randomUserArray = new int[size];//dynamically allocated array for random ints 
    counts = new int[range];//dynamically allocated array for counts of each random 1 to range
    
    //for loop to populete the array
    for(int i = 0; i<size; i++)
    {
        randomUserArray[i] = (rand()%range+1);// set random number into the array
        counts[i] = 0;// initialize counts to 0
    }
            
    //print array if user requested
    if(printVerif=='Y'||printVerif=='y')
    {
        cout<<"Rolls"<<endl;
        //for loop to print using brackets
        for(int i = 0; i<size; i++)
        {
            cout<<randomUserArray[i]<<" ";
        }
        cout<<endl;
    }
    
    // nested for loops to populate the counts array with each number of rands
    for(int i = 1; i<=range; i++)
    {
        for (int j = 0; j<size; j++)
        {
            if(randomUserArray[j]==i)// check each number for counts of each number
                counts[i-1] += 1;
        }
    }
    
    cout<<"Counts"<<endl;
    // for loop to print the counts
    for(int i = 0; i<range; i++)
    {
        cout<<(i+1)<<": "<<counts[i]<<" ";
    }
    cout<<endl;
    
    //delete memory for user array
    delete[] randomUserArray;
    randomUserArray = nullptr;
    
    //delete memory for counts of random numbers
    delete[] counts;
    counts = nullptr;
    
    return 0;
}
