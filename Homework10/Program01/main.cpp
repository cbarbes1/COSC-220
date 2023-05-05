/*
Author: Cole Barbes
Creation Date: 05/05/23
Last Update: 05/05/23
Description: This program tests each sort by speed that is entered by the user
*/
#include <iostream>
#include <chrono>
#include <stdlib.h>
#include "BinaryTree.h"
#include <fstream>

using namespace std;
using namespace std::chrono;

template<class T>
void treeSort(T[], int);

template <class T> 
void merge(T A[], T Temp[], int startA, int startB, int end);
template <class T> 
void mergeSort(T A[], T Temp[], int start, int end);
template <class T> 
void mergeSort(T A[], int size);
template <class T> 
void quickSort(T A[], int left, int right);
template <class T> 
void quickSort(T A[], int size);

int main()
{
    ofstream outFile; // init the file stream

    outFile.open("sortData.txt", ios::app);// open the file and start at the end 

    void (*chosenFunction)(int A[], int size); // create a function pointer

    // take input from user
    int sortMethod = 0;
    cout << "Select Sorting Algorithm: 1. Merge Sort   2. Quick Sort   3. "
            "Tree Sort: ";
    cin >> sortMethod;
    int size = 0;
    cout << "Input Array Size: ";
    cin >> size;

    int *A = new int[size];// create array 
    srand(time(NULL)); // seed the rand 

    // init to random numbers
    for (int i = 0; i < size; i++)
        A[i] = rand();

    // set the function type
    if (sortMethod == 1)
        chosenFunction = mergeSort;
    else if (sortMethod == 2)
        chosenFunction = quickSort;
    else
        chosenFunction = treeSort;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    chosenFunction(A, size); // call the given function
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    outFile<< "Execution Time: " << time_span.count() << " seconds." << endl;
    
    
    delete[] A;
    outFile.close(); // close the file
    return 0;
}

/*
Description: This function takes an array and the size 
Parameters: the array and the size
*/
template<class T>
void treeSort(T A[], int size)
{
    BinaryTree<int> sortTree;
    for(int i = 0; i<size; i++){
        sortTree.insertNode(A[i]);
    }

    sortTree.loadInOrder(A);
}

// Sorting Algorithms

template <class T>
void merge(T A[], T Temp[], int startA, int startB, int end) {
    int aptr = startA;
    int bptr = startB;
    int i = startA;

    while (aptr < startB && bptr <= end)
        if (A[aptr] < A[bptr])
            Temp[i++] = A[aptr++];
        else
            Temp[i++] = A[bptr++];

    while (aptr < startB)
        Temp[i++] = A[aptr++];

    while (bptr <= end)
        Temp[i++] = A[bptr++];

    for (i = startA; i <= end; i++)
        A[i] = Temp[i];
}

template <class T> void mergeSort(T A[], T Temp[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(A, Temp, start, mid);
        mergeSort(A, Temp, mid + 1, end);
        merge(A, Temp, start, mid + 1, end);
    }
}

template <class T> void mergeSort(T A[], int size) {
    T *Temp = new T[size];
    mergeSort(A, Temp, 0, size - 1);
    delete[] Temp;
}

///////////////////////////////////////////////////////////

template <class T> void quickSort(T A[], int left, int right) {
    int i = left;
    int j = right;
    int mid = (left + right) / 2;

    T pivot = A[mid];

    while (i <= j) {
        while (A[i] < pivot)
            i++;

        while (A[j] > pivot)
            j--;

        if (i <= j) {
            T tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(A, left, j);

    if (i < right)
        quickSort(A, i, right);
}

template <class T> void quickSort(T A[], int size) {
    quickSort(A, 0, size - 1);
}