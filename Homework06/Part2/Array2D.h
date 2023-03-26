#ifndef ARRAY2D_H
#define ARRAY2D_H

#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std; 

template<class T>
class Array2D{
    private:
        vector<vector<T>> A;
        //size variables
        int rows;
        int cols;

        T defval;
    
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
        vector<T>& operator[](int); // overload [] array accessor
        bool operator==(const Array2D&);// overload equals relational operator ==
        bool operator!=(const Array2D&); // overload does not equal operator

};

template<class T>
Array2D<T>::Array2D(int r, int c, T d)
{
    //set and validate the index
    rows = r;
    cols = c;
    if(r<1){ rows=1;}
    if(c<1){ cols = 1;}
    defval = d;

    A.resize(rows);

    // loop to create the sub arrays and the default value
    for(int i = 0; i<rows; i++)
    {
        A[i].resize(cols);
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
    A.clear();
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
    defval = other.defval;

    A.resize(rows);
    // fill the array with addresses of dynamic double arrays
    for(int i = 0; i<rows; i++)
    {
        A[i].resize(cols);
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
    // init the rows and cols
    rows = right.rows; 
    cols = right.cols;
    defval = right.defval;

    A.resize(rows);
    // fill the array with addresses of dynamic double arrays
    for(int i = 0; i<rows; i++)
    {
        A[i].resize(cols);
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

    vector<vector<T>> temp(r);
    
    // create the inner arrays and set the value
    for(int i = 0; i<r; i++){
        temp[i].resize(c);
        for(int j = 0; j<c; j++){
            if(j>=cols||i>=rows){
                temp[i][j] = defval;
            }
            else{
                temp[i][j] = A[i][j];
            }
        }
    }

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
* Description: overload the [] operator to return an address at a specifies index
*/
template<class T>
vector<T>& Array2D<T>::operator[](int n)
{
    
    return A[n];
}

template<class T>
bool Array2D<T>::operator==(const Array2D &right)
{
    if(rows == right.rows && cols == right.cols){
        int countSame = 0;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++)
            {
                if(A[i][j] == right.A[i][j]){
                    countSame++;
                }
            }
        }
        if(countSame == (rows*cols)){
            return true;
        }
        else {
            return false;
        }
    }
    else{
        return false;
    }
}

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