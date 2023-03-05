/*
Created by: Cole Barbes
Creation date: 02/23/23
Description: simple class to create a 2d array in a safer manner
*/
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <iomanip>

class Matrix;

ostream& operator<<(ostream &, const Matrix&);

class Matrix{
    private:
        double** A = nullptr;// Init the array double pointer to null
        //size variables
        int rows;
        int cols;
    
    public:
        // functions that assign value
        Matrix(int r = 3, int c = 3, double defval = 0);// constructor with default values
        Matrix(const Matrix&); // copy constructor
        Matrix operator=(const Matrix&); // overload assignment for this class
        ~Matrix();//destructor to get rid of the memory 

        // display or print functions
        void display();//display the array 
        void display(int);// display with a column width
        
        // accessors and mutators
        int getRows(); //return the row count
        int getCols(); // return the column count
        void set(int, int, double);// set an element into the array
        int get(int, int); // return the element at the spot in the array
        void resize(int r = 3, int c = 3, double defval = 0);// resize the array to given parameters or default resize 
        Matrix transpose();
        
        //overloaded math operators
        Matrix operator+(const Matrix&); // overload +
        Matrix operator-(const Matrix&); // overload -
        friend Matrix operator*(double left, const Matrix&); // overload * left side
        Matrix operator*(double); // overload * right side
        Matrix operator*(const Matrix&); // overload * for 2 matrices

        // overloaded iostream operators
        friend ostream& operator<<(ostream &, const Matrix&); // overload out stream

        // overload access operators
        double* operator[](int); // overload [] array accessor
};

#endif