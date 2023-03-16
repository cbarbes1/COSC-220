/*
*/
#include "StockDay.h"
#include <iomanip>

enum TYPE{OPEN = 0, CLOSE = 1, ADJCLOSE = 2, HIGH = 3, LOW = 4};

StockDay::StockDay()
{
    date.setDate(01, 02, 1960);
    for(int i = 0; i<5; i++)
    {
        data[i] = 0;
    }
    volume = 0;
}
StockDay::StockDay(Date& newDate, float arr[], int v)
{
    date.setDate(newDate.getMonth(), newDate.getDay(), newDate.getYear());
    for(int i = 0; i<SIZE; i++){
        data[i] = arr[i];
    }
    volume = v;
}
void StockDay::setStockDay(Date& newDate, float arr[], int v)
{
    date.setDate(newDate.getMonth(), newDate.getDay(), newDate.getYear());
    for(int i = 0; i<SIZE; i++){
        data[i] = arr[i];
    }
    volume = v;
}
Date& StockDay::getDate()
{
    return date;
}
float StockDay::getOpen()
{
    return data[OPEN];
}
float StockDay::getClose()
{
    return data[CLOSE];
}
float StockDay::getAdjClose()
{
    return data[ADJCLOSE];
}
float StockDay::getHigh()
{
    return data[HIGH];
}
float StockDay::getLow()
{
    return data[LOW];
}
int StockDay::getVolume()
{
    return volume;
}
StockDay StockDay::operator=(const StockDay& right)
{
    date = right.date;
    for(int i = 0; i<SIZE; i++){
        data[i] = right.data[i];
    }
    volume = right.volume;
    return *(this);
}
ostream& operator<<(ostream &strm, const StockDay &stock)
{
    strm<<setw(12)<<"Date: "<<stock.date<<endl;
    strm<<setw(12)<<"Open: "<<stock.data[OPEN]<<endl;
    strm<<setw(12)<<"Close: "<<stock.data[CLOSE]<<endl;
    strm<<setw(12)<<"Adj. Close: "<<stock.data[ADJCLOSE]<<endl;
    strm<<setw(12)<<"High: "<<stock.data[HIGH]<<endl;
    strm<<setw(12)<<"Low: "<<stock.data[LOW]<<endl;
    strm<<setw(12)<<"Volume: "<<stock.volume<<endl;
    return strm;
}