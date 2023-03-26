/*
* Author: Cole Barbes
* Creation Date: 03/25/23
* Last Update: 03/26/23
* Description: This class is a templated version of an already created class for 2d array creation using pointers
* Notes: This code is taken from a collection of different homeworks and edited to be implemented for any data type
*/
#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; 

template<class T> // this templates a type for needed declarations
class Array2D{
    private:
        T** A = nullptr;// Init the array double pointer to null
        //size variables
        int rows; // row count
        int cols; // column count
        T defval; // default value
    
    public:
        Array2D(int, int, T);// constructor with default values 
        ~Array2D();//destructor to get rid of the memory 
        Array2D(const Array2D&); // copy constructor
        Array2D operator=(const Array2D&); // overload assignment for this class
        void display();
        void display(int);// display with a column width
        int getRows(); //return the row count
        int getCols(); // return the column count
        void set(int, int, T);// set an element into the array
        T get(int, int); // return the element at the spot in the array
        void resize(int r, int c);// resize the array to given parameters or default resize 
        
        // overloaded iostream operators
        template<class U>
        friend ostream& operator<<(ostream &, const Array2D<U>&); // overload out stream
        // overload access operators
        T* operator[](int); // overload [] array accessor
        bool operator==(const Array2D&);// overload equals relational operator ==
        bool operator!=(const Array2D&); // overload does not equal operator

};

/*
Description: this is the constructor for this class
Parameters: the rows and column count as well as the default value
*/
template<class T>
Array2D<T>::Array2D(int r, int c, T d)
{
    //set and validate the index
    rows = r;
    cols = c;
    if(r<1){ rows=1;}
    if(c<1){ cols = 1;}
    defval = d;

    A = new T*[rows]; // create the array

    // loop to create the sub arrays and the default value
    for(int i = 0; i<rows; i++)
    {
        A[i] = new T[cols];
        for(int j = 0; j<cols; j++)
        {
            A[i][j] = defval;
        }
    }
}

/*
* Description: Delete used memory to avoid memory leak
*/
template<class T>
Array2D<T>::~Array2D()
{
    for(int i = 0; i<rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}

/*
* Description: Copy Constructor that takes another object as its parameter to copy the contents into a new obj on declaration 
* Parameters: another Matrix constant by reference
*/
template<class T>
Array2D<T>::Array2D(const Array2D& other)
{
    // init the rows and cols
    rows = other.rows; 
    cols = other.cols;

    A = new T*[rows]; // init pointer array

    // fill the array with addresses of dynamic double arrays
    for(int i = 0; i<rows; i++)
    {
        A[i] = new T[cols];
        for(int j = 0; j<cols; j++)
        {
            A[i][j] = other.A[i][j];
        }
    }
}
/*
* Description: Overload the equal sign to assign new value to the object, this is done after declaration so previous memory and elems will be overwritten
* Parameters: another constant Matrix reference
*/
template<class T>
Array2D<T> Array2D<T>::operator=(const Array2D &right)
{
    // delete actual arrays contained in pointer array
    for(int i = 0; i<rows; i++){
        delete[] A[i];
    }
    delete[] A; // delete old memory for the full pointer array
    A = nullptr; // set the array to null

    // set the rows and cols size
    rows = right.rows;
    cols = right.cols;

    A = new T*[rows];// create pointer array

    // set each double array into the pointer array
    for(int i = 0; i<rows; i++)
    {
        A[i] = new T[cols];
        // set each spot to identical value as the const array
        for(int j = 0; j<cols; j++)
        {
            A[i][j] = right.A[i][j];
        }
    }
    return *this;
}

/*
* Description: display the array with spaces in between elements
*/
template<class T>
void Array2D<T>::display()
{
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

/*
* Description: print a specific row for testing 
*/
template<class T>
void Array2D<T>::display(int spaceX)
{
    for(int i = 0; i<rows; i++)
    {
        
        for(int j = 0; j<cols; j++)
        {
            cout<<setw(spaceX)<<A[i][j];
        }
        cout<<endl;
    }
}

/*
* Description: return the value of the private member rows
*/
template<class T>
int Array2D<T>::getRows()
{
    return rows;
}

/*
* Description: return the value of the private member cols
*/
template<class T>
int Array2D<T>::getCols()
{
    return cols;
}

/*
* Description: set a value into  the array 
* Parameters: integers for the location and the value
*/
template<class T>
void Array2D<T>::set(int r, int c, T var)
{
    // if in bounds set the value
    if((r>=0&&r<rows)&&(c>=0&&c<cols)){
        A[r][c] = var;
    }
    // if not print error message
    else{
        cout<<"Index is out of bounds, no change to the array."<<endl;
    }
}

/*
* Description: get the value at the specified index
*/
template<class T>
T Array2D<T>::get(int r , int c)
{
    // if in bounds send out the value
    if((r>=0&&r<rows)&&(c>=0&&c<cols)){
        return A[r][c];
    }
    // if not print message and return 0
    else{
        cout<<"Index is out of bounds, returning default value."<<endl;
        return defval;
    }
}


/*
* Description: resize the array to the given size and if greater than original size set defval into it
*/
template<class T>
void Array2D<T>::resize(int r, int c)
{
    // check if the index is valid
    if(r<1){ r = 1;}
    if(c<1){ c = 1;}

    T** temp = new T*[r];// create the array of pointers
    
    // create the inner arrays and set the value
    for(int i = 0; i<r; i++){
        temp[i]= new T[c];
        for(int j = 0; j<c; j++){
            if(j>=cols||i>=rows){
                temp[i][j] = defval;
            }
            else{
                temp[i][j] = A[i][j];
            }
        }
    }
    
    // delete the memory
    for(int i = 0; i<rows; i++){
        delete[] A[i];
    }
    delete[] A; // delete the outer memory
    A = temp;// set the array memory locations

    // set the size
    rows = r;
    cols = c;
}

/*
* Description: overload the print stream so that the matrix class can be printed
* Parameters: the stream and the matrix
* return: the stream
*/
template<class T>
ostream& operator<<(ostream &strm, const Array2D<T> &val)
{
    strm<<"["; 
    // loop through the outer array 
    for(int i = 0; i<val.rows; i++)
    {
        strm<<"[";
        // loop through the inner array
        for(int j = 0; j<val.cols; j++)
        {
            if(j<(val.cols-1)){
                strm<<val.A[i][j]<<" ";
            }
            else{
                strm<<val.A[i][j];
            }
        }
        strm<<"]";
    }
    strm<<"]";
    return strm; // return stream
}

/*
* Description: overload the [] operator to return an address at a specified index
*/
template<class T>
T* Array2D<T>::operator[](int n)
{
    // if n is less than size then get the element
    if(n<rows){
        return A[n];
    }
    else{
        return nullptr;
    }
}

/*
Description: this function will check if two 2d array class objects are the same by size and by content by overloading the ==
Parameters: the right hand side array
*/
template<class T>
bool Array2D<T>::operator==(const Array2D &right)
{
    // if the size is the same, continue
    if(rows == right.rows && cols == right.cols){
        int countSame = 0;
        // loop through the arrays
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++)
            {
                // if equal add to the count
                if(A[i][j] == right.A[i][j]){
                    countSame++;
                }
            }
        }
        // if count is the same as the size of the array return true
        if(countSame == (rows*cols)){
            return true;
        }
        // if not return false
        else {
            return false;
        }
    }
    // return false if size is not same
    else{
        return false;
    }
}

/*
Description: this function uses the above overwritten operator to find if something is not equal
Parameters: the right hand side array
Return: boolean true false whether somethinh is not equal
*/
template<class T>
bool Array2D<T>::operator!=(const Array2D &right)
{
    if(*this==right){
        return false;
    }
    else{
        return true;
    }
}


#endif