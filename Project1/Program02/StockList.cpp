/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/16/23
*/
#include "StockList.h"
#include "Date.h"

/*
Description: default constructor
*/
StockList::StockList()
{
    size = 0;
    capacity = 10;
    data = new StockDay[capacity];
}

/*
Description: constructor to size
*/
StockList::StockList(int s)
{
    size = 0;
    capacity = s;
    data = new StockDay[capacity];
}

/*
Description: copy constructor
*/
StockList::StockList(const StockList& other)
{
    size = other.size;
    capacity = other.capacity;
    data = new StockDay[capacity];
    for(int i = 0; i<size; i++){
        data[i] = other.data[i];
    }
}

/*
Description: delete memory 
*/
StockList::~StockList()
{
    delete [] data;
}

/*
Description: overload the equals 
return the result
*/
StockList StockList::operator=(const StockList &right)
{
    size = right.size;
    capacity = right.capacity;
    for(int i = 0; i<size; i++){
        data[i] = right.data[i];
    }
    return *(this);
}

/*
Description: set the element into the array
if the spot is invalid print error, if not set elem into the array
*/
void StockList::setElement(int itervar, const StockDay &elem)
{
    if(itervar >= capacity){ cout<<"Please use the increase capacity function to change the size!"<<endl;}
    else { data[itervar] = elem; }
}

/*
Description: get the element
if valid spot return, if not return blank obj
*/
StockDay StockList::getElement(int n)
{
    if(isValid(n)){ return data[n];}
    else {return StockDay();}
}

/*
Description: get the size
Return the size
*/
int StockList::getSize()
{
    return size;
}

/*
Description: get the capacity
Return the capacity
*/
int StockList::getCapacity()
{
    return capacity;
}

/*
Description: print the array
*/
void StockList::displayList()
{
    for( int i = 0; i<size; i++){
        cout<<data[i]<<endl;
    }
    
}

/*
Description: append elem to the array 
Parameters: a stock day object
if size == capacity resize, if not then add elem and add to the size, check again
*/
void StockList::append(const StockDay &newElem)
{
    if(size == capacity){ IncreaseCapacity();}
    else { 
        data[size] = newElem;
        size++;
        if(size == capacity){ IncreaseCapacity();}
    }
}

/*
Description: Find the date given
return the index, if not return -1
*/
int StockList::find(const Date &target)
{
    for(int i = 0; i<size; i++){
        if(data[i].getDate() == target){ return i;}
    }
    return -1;
}

/*
Description: override the access brackets
Parameters: the int location
return the data
*/
StockDay StockList::operator[](int n)
{
    return data[n];
}

/*
Description: override the print stream
Parameters: the stream, and the object
return the stream
*/
ostream& operator<<(ostream& strm, const StockList &obj)
{
    for(int i = 0; i<obj.size; i++){
        strm<<obj.data[i];
    }
    return strm;
}

/*
Description: check if a location is valid
return true or false
*/
bool StockList::isValid(int n)
{
    return (n<size)&&(n>=0);
}

/*
Description: increase the capacity
*/
void StockList::IncreaseCapacity()
{
    capacity = capacity*2;
    StockDay* temp = new StockDay[capacity];
    for(int i = 0; i<size; i++){
        temp[i] = data[i];
    }
    delete [] data;
    data = nullptr;
    data = temp;
}