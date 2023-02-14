#ifndef ARRAYFUNC_H
#define ARRAYFUNC_H

#include <iostream> 
#include <ctime>
#include <algorithm>

using namespace std;

void div();// divider function
int* duplicateArray(int*, int);//duplicate array
void display(int*, int);// display array
int* getRandomNumbers(int);// get random number array
void swap(int*, int, int);// swap 2 elements
bool sorted(int*, int);//sorted checker
void sort(int* , int);//sort array
void concat(int*, int, const int*, int);//concatenate 2 arrays
void remove(int* &, int&, int, int);// remove section of the array
void shuffle(int*, int);// shuffle the array
void sub(int* &, int&, int, int);// substitute 
void insert(int* &, int&, int*, int, int); // insert 
void resize(int* &, int&, int);// resize 

#endif