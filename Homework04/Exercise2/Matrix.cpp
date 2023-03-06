/*
* Author: Cole Barbes
* Creation Date: 03/05/23
* Last Update: 03/05/23
*/
#include "Matrix.h"// include header file
#include <string>


using namespace std;

/*
* Description: Constructor that sets the Array to the entered row and cols and if applicable the default value
* Parameters: integer parameters for rows, cols and default value
*/
Matrix::Matrix(int r, int c, double defval)
{
    //set and validate the index
    rows = r;
    cols = c;
    if(r<1){ rows=1;}
    if(c<1){ cols = 1;}

    A = new double*[rows]; // create the array

    // loop to create the sub arrays and the default value
    for(int i = 0; i<rows; i++)
    {
        A[i] = new double[cols];
        for(int j = 0; j<cols; j++)
        {
            A[i][j] = defval;
        }
    }
}

/*
* Description: Copy Constructor that takes another object as its parameter to copy the contents into a new obj on declaration 
* Parameters: another Matrix constant by reference
*/
Matrix::Matrix(const Matrix&other)
{
    // init the rows and cols
    rows = other.rows; 
    cols = other.cols;

    A = new double*[rows]; // init pointer array

    // fill the array with addresses of dynamic double arrays
    for(int i = 0; i<rows; i++)
    {
        A[i] = new double[cols];
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
Matrix Matrix::operator=(const Matrix& right)
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

    A = new double*[rows];// create pointer array

    // set each double array into the pointer array
    for(int i = 0; i<rows; i++)
    {
        A[i] = new double[cols];
        // set each spot to identical value as the const array
        for(int j = 0; j<cols; j++)
        {
            A[i][j] = right.A[i][j];
        }
    }
    return *this;
}

/*
* Description: Delete used memory to avoid memory leak
*/
Matrix::~Matrix()
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
void Matrix::display()
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
void Matrix::display(int spaceX)
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
int Matrix::getRows()
{
    return rows;
}

/*
* Description: return the value of the private member cols
*/
int Matrix::getCols()
{
    return cols;
}

/*
* Description: set a value into  the array 
* Parameters: integers for the location and the value
*/
void Matrix::set(int r, int c, double var)
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
int Matrix::get(int r , int c)
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
void Matrix::resize(int r, int c, double defval)
{
    // check if the index is valid
    if(r<1){ r = 1;}
    if(c<1){ c = 1;}

    double** temp = new double*[r];// create the array of pointers
    
    // create the inner arrays and set the value
    for(int i = 0; i<r; i++){
        temp[i]= new double[c];
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

Matrix Matrix::transpose()
{
    Matrix temp(cols, rows);
    for(int i = 0; i<cols; i++)
    {
        for(int j = 0; j<rows; j++)
        {
            temp[i][j] = A[j][i];
        }
    }

    return temp;
    
}
        

Matrix Matrix::operator+(const Matrix& other)
{
    if(rows == other.rows&&cols==other.cols){
        Matrix temp(rows, cols);
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                temp.A[i][j] = A[i][j] + other.A[i][j];
            }
        }
        return temp;
    }
    else{
        Matrix temp(1, 1, 0);
        cout<<"Addition of unequivalent sized matrices is strictly prohibited in this library!"<<endl;
        return temp;
    }
}
Matrix Matrix::operator-(const Matrix& other)
{
    if(rows == other.rows&&cols==other.cols){
        Matrix temp(rows, cols);
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                temp.A[i][j] = A[i][j] - other.A[i][j];
            }
        }
        return temp;
    }
    else{
        Matrix temp(1, 1, 0);
        cout<<"Subtraction of unequivalent sized matrices is strictly prohibited in this library!"<<endl;
        return temp;
    }
}
Matrix operator*(double left, const Matrix& right)
{
    Matrix temp(right.rows, right.cols);
    for(int i = 0; i<right.rows; i++)
    {
        for(int j = 0; j<right.cols; j++)
        {
            temp.A[i][j] = right.A[i][j]*left;
        }
    }
    return temp;
}
Matrix Matrix::operator*(double right)
{
    Matrix temp(rows, cols);
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            temp.A[i][j] = A[i][j]*right;
        }
    }
    return temp;
}
Matrix Matrix::operator*(const Matrix& right)
{
    if(cols==right.rows){
        int sum = 0;
        Matrix temp(rows, right.cols, 0);
        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<right.cols; j++)
            {
                sum = 0;
                for(int k = 0; k<cols; k++)
                {
                    sum += (A[i][k])*(right.A[k][j]);
                }
                temp[i][j] = sum;
            }
        }
        return temp;
    }
    else{
        Matrix temp(1, 1, 0);
        cout<<"Multiplication of unequivalent sized matrices is strictly prohibited in this library!"<<endl;
        return temp;
    }
}

ostream& operator<<(ostream &strm, const Matrix& val)
{
    strm<<"[";
    for(int i = 0; i<val.rows; i++)
    {
        strm<<"[";
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
    return strm;
}

double* Matrix::operator[](int n)
{
    if(n<rows){
        return A[n];
    }
    else{
        return nullptr;
    }
}