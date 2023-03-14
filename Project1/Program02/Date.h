#ifndef DATE_H
#define DATE_H
#include <iostream>// include iostream for overload

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
        void setDate(int, int, int);// set the date after declaration
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
};
#endif