/*
Author: Cole Barbes
Creation Date: 04/07/23
Last Update: 04/07/23
Description: This program simply times a few data structures

Run the program on sizes of 100,000, 500,000, and 1,000,000. How do the insertion
times compare?
The vector seems to be the slowest of any of the data structures
The linked list is the fastest of the data structures

*/
#include <list>
#include <vector>
#include <iostream>
#include <ctime>
#include <chrono> // include for the timer
#include "LinkedList.h"

using namespace std;
using namespace std::chrono;

int main()
{
    srand(time(0)); // set the seed

    int SIZE = 0; // init the size var

    LinkedList<int> dataLink; // create linked list
    vector<int> dataVector; // create vector list
    list<int> dataList; // create STL list

    // take size in from user
    cout<<"How many numbers would you like to store? ";
    cin>>SIZE;

    auto start = high_resolution_clock::now(); // init start the clock

    // push values onto the front of the linked link
    for(int i = 0; i<SIZE; i++){
        dataLink.push_front(rand());
    }

    auto stop = high_resolution_clock::now(); // init stop the timer
    auto duration = duration_cast<microseconds>(stop-start); // find duration

    // print the output
    cout << "Time to append to the front with linked list: " << duration.count() / 1000000.0<< " seconds" << endl;

    start = high_resolution_clock::now(); // start

    // insert items to vector front
    for(int i = 0; i<SIZE; i++){
        dataVector.insert(dataVector.begin(), rand());
    }

    stop = high_resolution_clock::now(); // stop 
    duration = duration_cast<microseconds>(stop-start); // duration

    // print the output
    cout << "Time to append to the front with a vector: " << duration.count() / 1000000.0<< " seconds" << endl;

    start = high_resolution_clock::now(); // start

    // push values to the front of the list
    for(int i = 0; i<SIZE; i++){
        dataList.push_front(rand());
    }

    stop = high_resolution_clock::now();// stop
    duration = duration_cast<microseconds>(stop-start); // duration

    //print the outpu
    cout << "Time to append to the front with STL list: " << duration.count() / 1000000.0<< " seconds" << endl;


    start = high_resolution_clock::now(); // start

    // place items on the end of the linked list
    for(int i = 0; i<SIZE; i++){
        dataLink.push_back(rand());
    }
    stop = high_resolution_clock::now(); // stop
    duration = duration_cast<microseconds>(stop-start); // duration

    // print the output 
    cout << "Time to append to the back with linked list: " << duration.count() / 1000000.0<< " seconds" << endl;

    start = high_resolution_clock::now(); // start

    // set values in the back of the vector
    for(int i = 0; i<SIZE; i++){
        dataVector.push_back(rand());
    }

    stop = high_resolution_clock::now(); // stop
    duration = duration_cast<microseconds>(stop-start); // duration

    //print the output
    cout << "Time to append to the back with a vector: " << duration.count() / 1000000.0<< " seconds" << endl;

    start = high_resolution_clock::now(); // start 

    // set values in the back of the list
    for(int i = 0; i<SIZE; i++){
        dataList.push_back(rand());
    }

    stop = high_resolution_clock::now(); // stop
    duration = duration_cast<microseconds>(stop-start); // duration

    //print the output
    cout << "Time to append with back STL list: " << duration.count() / 1000000.0<< " seconds" << endl;

    return 0;
}