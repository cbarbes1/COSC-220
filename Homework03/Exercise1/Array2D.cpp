/*
* Author: Cole Barbes
* Creation Date: 02/19/23
* Last Update: 03/02/23
*/
#include "Array2D.h"// include header file


using namespace std;

/*
* Description: Constructor that sets the Array to the entered row and cols and if applicable the default value
* Parameters: integer parameters for rows, cols and default value
*/
Array2D::Array2D(int r, int c, int defval)
{
    //set and validate the index
    rows = r;
    cols = c;
    if(r<1){ rows=1;}
    if(c<1){ cols = 1;}

    A = new int*[rows]; // create the array

    // loop to create the sub arrays and the default value
    for(int i = 0; i<rows; i++)
    {
        A[i] = new int[cols];
        for(int j = 0; j<cols; j++)
        {
            A[i][j] = defval;
        }
    }
}

/*
* Description: Delete used memory to avoid memory leak
*/
Array2D::~Array2D()
{
    for(int i = 0; i<rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}

/*
* Description: display the array with spaces in between elements
*/
void Array2D::display()
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
* Description: return the value of the private member rows
*/
int Array2D::getRows()
{
    return rows;
}

/*
* Description: return the value of the private member cols
*/
int Array2D::getCols()
{
    return cols;
}

/*
* Description: set a value into  the array 
* Parameters: integers for the location and the value
*/
void Array2D::set(int r, int c, int var)
{
    // if in bounds set the value
    if((r>=0&&r<rows)&&(c>=0&&c<cols)){
        A[r][c] = var;
    }
    // if not print error message
    else{
        cout<<"Index is out of bounds"<<endl;
    }
}

/*
* Description: get the value at the specified index
*/
int Array2D::get(int r , int c)
{
    // if in bounds send out the value
    if((r>=0&&r<rows)&&(c>=0&&c<cols)){
        return A[r][c];
    }
    // if not print message and return 0
    else{
        cout<<"Index is out of bounds"<<endl;
        return 0;
    }
}


/*
* Description: resize the array to the given size and if greater than original size set defval into it
*/
void Array2D::resize(int r, int c, int defval)
{
    // check if the index is valid
    if(r<1){ r = 1;}
    if(c<1){ c = 1;}

    int** temp = new int*[r];// create the array of pointers
    
    // create the inner arrays and set the value
    for(int i = 0; i<r; i++){
        temp[i]= new int[c];
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

    // set the inner memory addresses
    for(int i = 0; i<r; i++){
        A[i] = temp[i];
    }

    // set the size
    rows = r;
    cols = c;
}

/*
* Description: print a specific row for testing 
*/
void Array2D::display(int spaceX)
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