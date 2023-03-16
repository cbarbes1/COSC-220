/*
*/
#ifndef STOCKLIST_H
#define STOCKLIST_H

#include <iostream>
#include "StockDay.h"

class StockList{
    private:
        StockDay* data;
        int size, capacity;
        bool isValid(int);
        void IncreaseCapacity();
    public:
        StockList();
        StockList(int);
        StockList(const StockList&);
        ~StockList();
        StockList operator=(const StockList&);
        // accessors and mutators
        void setElement(int, const StockDay&);
        StockDay getElement(int);
        int getSize();
        int getCapacity();
        void displayList();
        void append(const StockDay&);
        int find(const Date&);
        StockDay operator[](int);
        friend ostream& operator<<(ostream& strm, const StockList&);
};
#endif