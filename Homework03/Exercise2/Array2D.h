/*
Created by: Cole Barbes
Creation date: 02/23/23
Description: simple class to create a 2d array in a safer manner
*/
#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <cmath>
#include <iomanip>

class Array2D{
    private:
        int** A = nullptr;// Init the array double pointer to null
        //size variables
        int rows;
        int cols;
    
    public:
        Array2D(int r = 3, int c = 3, int defval = 0);// constructor with default values 
        ~Array2D();//destructor to get rid of the memory 

        void display();//display the array 
        int getRows(); //return the row count
        int getCols(); // return the column count
        void set(int, int, int);// set an element into the array
        int get(int, int); // return the element at the spot in the array
        void resize(int r = 3, int c = 3, int defval = 0);// resize the array to given parameters or default resize 
        void display(int);// display with a column width
        void rowPrint(int); // print 1 row
};

#endif