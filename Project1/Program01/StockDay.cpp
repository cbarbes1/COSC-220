/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/16/23
*/
#include "StockDay.h"
#include <iomanip>

// enum for the types
enum TYPE{OPEN = 0, CLOSE = 1, ADJCLOSE = 2, HIGH = 3, LOW = 4, VOLUME = 5};

/*
Description: default constructor
*/
StockDay::StockDay()
{
    date.setDate(01, 02, 1960);
    for(int i = 0; i<5; i++)
    {
        data[i] = 0;
    }
}

/*
Description: Constructor
Parameters: Date and arr holding data
*/
StockDay::StockDay(Date& newDate, double arr[])
{
    date.setDate(newDate.getMonth(), newDate.getDay(), newDate.getYear());
    for(int i = 0; i<SIZE; i++){
        data[i] = arr[i];
    }
}

/*
Description: Set the stock day 
Parameters: Date and array holding data
*/
void StockDay::setStockDay(Date& newDate, double arr[])
{
    date.setDate(newDate.getMonth(), newDate.getDay(), newDate.getYear());
    for(int i = 0; i<SIZE; i++){
        data[i] = arr[i];
    }
}

/*
Description: get the date
return the date
*/
Date& StockDay::getDate()
{
    return date;
}

/*
Description: get the open
return the open
*/
double StockDay::getOpen()
{
    return data[OPEN];
}

/*
Description: get the close
return the close
*/
double StockDay::getClose()
{
    return data[CLOSE];
}

/*
Description: get the adj close
return the adj close
*/
double StockDay::getAdjClose()
{
    return data[ADJCLOSE];
}

/*
Description: get the high
return the high
*/
double StockDay::getHigh()
{
    return data[HIGH];
}

/*
Description: set the low
return the low
*/
double StockDay::getLow()
{
    return data[LOW];
}

/*
Description: set the volume
return the volume
*/
double StockDay::getVolume()
{
    return data[VOLUME];
}

/*
Description: overload the = operator
Parameters: the right obj
return the result
*/
StockDay StockDay::operator=(const StockDay& right)
{
    date = right.date;
    for(int i = 0; i<SIZE; i++){
        data[i] = right.data[i];
    }
    return *(this);
}

/*
Description: Overload the stream
return the strm
*/
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