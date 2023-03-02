#include "Array2D.h"


using namespace std;

/*
*/
Array2D::Array2D(int r, int c, int defval)
{
    rows = r;
    cols = c;
    if(r<1){ rows=1;}
    if(c<1){ cols = 1;}
    A = new int*[rows];
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
*/
int Array2D::getRows()
{
    return rows;
}

/*
*/
int Array2D::getCols()
{
    return cols;
}

void Array2D::set(int r, int c, int var)
{
    if((r>=0&&r<rows)&&(c>=0&&c<cols)){
        A[r][c] = var;
    }
    else{
        cout<<"Index is out of bounds"<<endl;
    }
}

/*
*/
int Array2D::get(int r , int c)
{
    if((r>=0&&r<rows)&&(c>=0&&c<cols)){
        return A[r][c];
    }
    else{
        cout<<"Index is out of bounds"<<endl;
        return 0;
    }
}

/*
*/
void Array2D::resize(int r, int c, int defval)
{
    if(r<1){ r = 1;}
    if(c<1){ c = 1;}
    int** temp = new int*[r];
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
    
    for(int i = 0; i<rows; i++){
        delete[] A[i];
    }
    delete[] A;
    A = temp;

    for(int i = 0; i<r; i++){
        A[i] = temp[i];
    }

    rows = r;
    cols = c;
}

/*
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

/*
*/
void Array2D::rowPrint(int rowNum)
{
    for(int i = 0; i<cols; i++){
        cout<<A[rowNum][i]<<" ";
    }
    cout<<endl;
}