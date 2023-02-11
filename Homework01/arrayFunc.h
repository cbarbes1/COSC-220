#ifndef ARRAYFUNC_H
#define ARRAYFUNC_H

#include <iostream> 
#include <ctime>
#include <algorithm>

using namespace std;

void div();
int* duplicateArray(int*, int);
void display(int*, int);
int* getRandomNumbers(int);
void swap(int*, int, int);
bool sorted(int*, int);
void sort(int* , int);
void concat(int*, int, const int*, int);
void remove(int* &, int&, int, int);
void shuffle(int*, int);
void sub(int* &, int&, int, int);
void insert(int* &, int&, int*, int, int);
void resize(int* &, int&, int);

#endif