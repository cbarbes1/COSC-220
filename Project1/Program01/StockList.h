/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/16/23
Description: Stock list which is a safe array for the stock data from each day, able to expand the array at a given point
*/
#ifndef STOCKLIST_H
#define STOCKLIST_H

#include <iostream>
#include "StockDay.h" // include the header of the used class

class StockList{
    private:
        StockDay* data; // data array pointer
        int size, capacity; // size and capacity
        bool isValid(int); // check if the spot is valid
        void IncreaseCapacity(); // increase size
    public:
        StockList(); // stock list default constructor
        StockList(int); // stock list constructor 
        StockList(const StockList&); // copy constructor
        ~StockList();// destructor
        //overload equals
        StockList operator=(const StockList&);
        // accessors and mutators
        void setElement(int, const StockDay&);
        StockDay getElement(int);
        int getSize();
        int getCapacity();
        void displayList();
        void append(const StockDay&);
        int find(const Date&); // find function
        StockDay operator[](int); // overload the array accessor
        friend ostream& operator<<(ostream& strm, const StockList&); // overload the stream 
};
#endif