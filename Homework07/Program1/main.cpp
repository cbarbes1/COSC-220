/*
Author: Cole Barbes
Creation Date: 03/30/23
Last Update: 03/30/23
Description: This program will test the speed of appending and sorting data structures 
User Interface: The interface simply askes the user for number of data items to append and sort
Notes: <Any notes that a user of the program should know about>
*/
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "LinkedList.h"

using namespace std;
using namespace std::chrono; 

template<class T> // template class creation
void bubbleSort(T[], int); // function prototype for bubble sort function
template<class T> 
void selectionSort(T[], int); // function prototype for a selection sort function
template<class T> 
void insertionSort(T[], int); // function prototype for a insertion sort function

int main()
{
    int numData = 0; // init the size holder

    srand(time(0)); // seed the random

    // prompt the user for the number of data items
    cout<<"How many data items do you wish to store? ";
    cin>>numData;

    LinkedList<int> dataList; // create a linked list for the data
    vector<int> dataVector; // create a vector for the data
    int *dataArray = new int[numData]; // create a dynamic array for other testing

    // place the elements into the array
    for(int i = 0; i<numData; i++){
        dataVector.push_back(rand());
    }

    // this segment of code times the process of sorting the linked list
    auto start = high_resolution_clock::now();

    // insert the elements into the linked list which will also sort the list using the insert node function
    for(int i = 0; i<numData; i++){
        dataList.insertNode(dataVector[i]);
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    cout << "Time to append and sort with linked list: " << duration.count() / 1000000.0<< " seconds" << endl;
    //

    // this segment of code times appending to an array and then sorting using bubble sort
    start = high_resolution_clock::now();

    // place the data from the vector into the array
    for(int i = 0; i<numData; i++){
        dataArray[i] = dataVector[i];
    }
    // sort the array using bubble sort
    bubbleSort(dataArray, numData);
    
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << "Time to append and sort the array (Bubble Sort):" << duration.count() / 1000000.0<< " seconds" << endl;
    //

    //this segment times the process of placing elements into the array then sorting the array using insertion sort
    start = high_resolution_clock::now();

    for(int i = 0; i<numData; i++){
        dataArray[i] = dataVector[i];
    }
    insertionSort(dataArray, numData);
    
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << "Time to append and sort the array (Insertion Sort):" << duration.count() / 1000000.0<< " seconds" << endl;
    //

    //this segment times the process of placing elements into the array then sorting the array using selection sort
    start = high_resolution_clock::now();

    for(int i = 0; i<numData; i++){
        dataArray[i] = dataVector[i];
    }
    selectionSort(dataArray, numData);
    
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop-start);
    cout << "Time to append and sort the array (Selection Sort):" << duration.count() / 1000000.0<< " seconds" << endl;
    //

    return 0;
}

template<class T> void bubbleSort(T array[], int size) {
    int maxElement;
    int index;

    for (maxElement = size - 1; maxElement > 0; maxElement--){
        for (index = 0; index < maxElement; index++){
            if (array[index] > array[index + 1]){
                swap(array[index], array[index + 1]);
            }
        }
    }
}

template<class T> 
void selectionSort(T array[], int size) {
    int minIndex;
    T minValue;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = array[start];
        for (int index = start + 1; index < size; index++) {
            if (array[index] < minValue) {
                minValue = array[index];
                minIndex = index;
            }
        }      
        swap(array[minIndex], array[start]);
    }
}

template<class T> 
void insertionSort(T array[], int size) {
    for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {
        T temp = array[itemsSorted];
        int loc = itemsSorted - 1;
        while (loc >= 0 && array[loc] > temp) {
            array[loc + 1] = array[loc];
            loc = loc - 1;
        }
        array[loc + 1] = temp;
    }
}