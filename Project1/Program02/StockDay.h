#ifndef STOCKDAY_H
#define STOCKDAY_H

#include <iostream>
#include "Date.h"

using namespace std;

class StockDay{
    private:
        Date date;// hold the date
        const string type[6] = {"Open", "Close", "Adj. Close", "High", "Low", "Volume" };// array for each piece of data to have a cleaner print
        static const int SIZE = 6;
        double data[SIZE]; // array to hold each data input

    public: 
        StockDay(); // default constructor
        StockDay(Date&, double []); // constructor
        // accessors and mutators 
        void setStockDay(Date&, double []); 
        Date& getDate();
        double getOpen(); 
        double getClose();
        double getAdjClose();
        double getHigh();
        double getLow();
        double getVolume();

        StockDay operator=(const StockDay&);
        // overload for the output
        friend ostream& operator<<(ostream &strm, const StockDay&);
};
#endif