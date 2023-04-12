/*
Author: Cole Barbes
Creation Date: 03/10/23
Last Update: 03/16/23
Description: This is a class to hold date of stocks
*/
#ifndef DATE_H
#define DATE_H
#include <iostream>// include iostream for overload
#include <string>

using namespace std;

class Date{
    private:
        // variable to hold month, day, year
        int month;
        int day;
        int year;
    public:
        Date();//default constructor
        Date(int, int, int); //constructor
        // accessors and mutators
        void setDate(int, int, int);
        void setMDY(string);
        int getMonth(); 
        int getDay();
        int getYear();
        bool operator==(const Date&); // overload == 
        bool operator!=(const Date&); // overload !=
        bool operator<(const Date&);// overload <
        bool operator>(const Date&); // overload >
        bool operator<=(const Date&); // overload <=
        bool operator>=(const Date&); // overload >=
        friend ostream& operator<<(ostream &, const Date&);// overload out stream

        string toString();
};
#endif