/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/16/23
Description: class declaration for a stock day which holds data pertaining to a single day of stock values and trade numbers
*/
#ifndef STOCKDAY_H
#define STOCKDAY_H

#include <iostream>
#include "Date.h" // include needed class

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

        // overload equals 
        StockDay operator=(const StockDay&);
        // overload for the output
        friend ostream& operator<<(ostream &strm, const StockDay&);
};
#endif