#ifndef STOCKDAY_H
#define STOCKDAY_H

#include <iostream>
#include "Date.h"

using namespace std;

class StockDay{
    private:
        Date date;// hold the date
        const string type[6] = {"Open", "Close", "Adj. Close", "High", "Low", "Volume" };// array for each piece of data to have a cleaner print
        static const int SIZE = 5;
        float data[SIZE]; // array to hold each data input
        int volume; // hold the volume

    public: 
        StockDay(); // default constructor
        StockDay(Date&, float [], int); // constructor
        // accessors and mutators 
        void setStockDay(Date&, float [], int); 
        Date& getDate();
        float getOpen(); 
        float getClose();
        float getAdjClose();
        float getHigh();
        float getLow();
        int getVolume();

        StockDay operator=(const StockDay&);
        // overload for the output
        friend ostream& operator<<(ostream &strm, const StockDay&);
};
#endif