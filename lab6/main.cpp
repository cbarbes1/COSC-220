/*
Author: Cole Barbes
Creation Date: 03/30/23
Last Update: 03/30/23
Description: This program times the process of appending to 2 types of data structures a linked list and a vector
User Interface: simple question and answer
Notes: Wow what a difference
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "LinkedList.h"

using namespace std;
using namespace std::chrono;

/*
Here is my output for the count addition:
How many data items do you wish to store? 100000
4999850001
Time to append with linked list: 18.9771 seconds
Time to append with Vector: 0.003748 seconds

How many data items do you wish to store? 20000 
199970001
Time to append with linked list: 0.85306 seconds
Time to append with Vector: 0.00086 seconds
*/

int main()
{
    srand(time(0)); // seed the rand

    int numData = 0; // hold the number of data

    // take the input from the user
    cout<<"How many data items do you wish to store? ";
    cin>>numData;

    LinkedList<int> dataList; // create a linked list of integers
    vector<int> dataVector; // create a vector of integers

    auto start = high_resolution_clock::now(); // start the timer
    
    // iterate through the list
    for(int i = 0; i<numData; i++){

        dataList.appendNode(rand()); // append values to the list

    }

    auto stop = high_resolution_clock::now(); // stop the timer
    auto duration = duration_cast<microseconds>(stop - start); // find the duration

    // print the count that we stored in the linked list
    cout <<dataList.count<<endl;
    // print the result
    cout<< "Time to append with linked list: " << duration.count()/1000000.0<< " seconds" << endl;

    start = high_resolution_clock::now(); // start the count

    // iterate through the loop
    for(int i = 0; i<numData; i++){

        dataVector.push_back(rand()); // append values to the vector using the pushback function
    }

    stop = high_resolution_clock::now(); // stop the count
    duration = duration_cast<microseconds>(stop - start); // find the duration
    cout << "Time to append with Vector: " << duration.count()/1000000.0<< " seconds" << endl; // print the result
    
    return 0;
}