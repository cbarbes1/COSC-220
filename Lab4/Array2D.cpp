#include "Array2D.h"

#include <iostream>
using namespace std;

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
Array2D::~Array2D()
{
    for(int i = 0; i<rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}

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
int Array2D::getRows()
{
    return rows;
}
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