/*
* Author: Cole Barbes
* Creation Date: 03/03/23
* Last Update: 03/07/23
* Description: This header hold all declaration for a point class
*/
#ifndef POINT_H
#define POINT_H

#include <iostream> // include io stream for stream overload 
using namespace std;

// point class
class Point{
    private:
    // variables to hold the points quordinant
        double x;
        double y;
        double z;
    public:
        Point(); // default constructor
        Point(int n, int m, int s); // integer constructor
        Point(double n, double m, double s); // double constructor
        void setXYZ(int, int, int); // set for integers
        void setXYZ(double, double, double); // set for doubles
        // accessors and mutators
        void setX(double);
        void setY(double);
        void setZ(double);
        void setX(int);
        void setY(int);
        void setZ(int);
        double getX();
        double getY();
        double getZ();

        // get the length 
        double length();

        friend ostream& operator<<(ostream &, const Point&); // overload outstream for this class

        Point operator=(const Point &);// overload = sign to set data after declaration

        // overloaded math operators
        double operator*(const Point&);
        friend Point operator*(int, Point&);
        Point operator*(int);
        Point operator+(const Point &);
        Point operator-(const Point &);
        Point operator/(const Point &);
        Point operator/(int);

        // overloaded relational operator == 
        bool operator==(const Point &);
};

#endif