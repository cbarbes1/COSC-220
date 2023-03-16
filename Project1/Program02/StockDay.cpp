/*
*/
#include "StockDay.h"
#include <iomanip>

enum TYPE{OPEN = 0, CLOSE = 1, ADJCLOSE = 2, HIGH = 3, LOW = 4, VOLUME = 5};

StockDay::StockDay()
{
    date.setDate(01, 02, 1960);
    for(int i = 0; i<5; i++)
    {
        data[i] = 0;
    }
}
StockDay::StockDay(Date& newDate, double arr[])
{
    date.setDate(newDate.getMonth(), newDate.getDay(), newDate.getYear());
    for(int i = 0; i<SIZE; i++){
        data[i] = arr[i];
    }
}
void StockDay::setStockDay(Date& newDate, double arr[])
{
    date.setDate(newDate.getMonth(), newDate.getDay(), newDate.getYear());
    for(int i = 0; i<SIZE; i++){
        data[i] = arr[i];
    }
}
Date& StockDay::getDate()
{
    return date;
}
double StockDay::getOpen()
{
    return data[OPEN];
}
double StockDay::getClose()
{
    return data[CLOSE];
}
double StockDay::getAdjClose()
{
    return data[ADJCLOSE];
}
double StockDay::getHigh()
{
    return data[HIGH];
}
double StockDay::getLow()
{
    return data[LOW];
}
double StockDay::getVolume()
{
    return data[VOLUME];
}
StockDay StockDay::operator=(const StockDay& right)
{
    date = right.date;
    for(int i = 0; i<SIZE; i++){
        data[i] = right.data[i];
    }
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
    strm<<setw(12)<<"Volume: "<<stock.data[VOLUME]<<endl;
    return strm;
}