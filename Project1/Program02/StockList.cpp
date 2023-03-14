#include "StockList.h"
#include "Date.h"

StockList::StockList()
{
    size = 0;
    capacity = 10;
    data = new StockDay[capacity];
}
StockList::StockList(int s)
{
    size = 0;
    capacity = s;
    data = new StockDay[capacity];
}
StockList::StockList(const StockList& other)
{
    size = other.size;
    capacity = other.capacity;
    data = new StockDay[capacity];
    for(int i = 0; i<size; i++){
        data[i] = other.data[i];
    }
}
StockList::~StockList()
{
    delete [] data;
}
StockList StockList::operator=(const StockList &right)
{
    size = right.size;
    capacity = right.capacity;
    for(int i = 0; i<size; i++){
        data[i] = right.data[i];
    }
    return *(this);
}
void StockList::setElement(int itervar, const StockDay &elem)
{
    if(itervar >= capacity){ cout<<"Please use the increase capacity function to change the size!"<<endl;}
    else { data[itervar] = elem; }
}
StockDay StockList::getElement(int n)
{
    if(isValid(n)){ return data[n];}
    else {return StockDay();}
}
int StockList::getSize()
{
    return size;
}
int StockList::getCapacity()
{
    return capacity;
}
void StockList::displayList()
{
    for( int i = 0; i<size; i++){
        cout<<data[i];
    }
}
void StockList::append(const StockDay &newElem)
{
    if(size == capacity){ IncreaseCapacity();}
    else { 
        data[size] = newElem;
        size++;
        if(size == capacity){ IncreaseCapacity();}
    }
}
int StockList::find(const Date &target)
{
    for(int i = 0; i<size; i++){
        if(data[i].getDate() == target){ return i;}
    }
    return -1;
}
StockDay StockList::operator[](int n)
{
    return data[n];
}
ostream& operator<<(ostream& strm, const StockList &obj)
{
    for(int i = 0; i<obj.size; i++){
        strm<<obj.data[i];
    }
    return strm;
}
bool StockList::isValid(int n)
{
    return (n<size)&&(n>=0);
}
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