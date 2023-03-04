#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;


class Point{
    private:
        double x;
        double y;
        double z;
    public:
        Point();
        Point(int n, int m, int s);
        Point(double n, double m, double s);
        void setXYZ(int, int, int);
        void setXYZ(double, double, double);
        void setX(double);
        void setY(double);
        void setZ(double);
        void setX(int);
        void setY(int);
        void setZ(int);
        double getX();
        double getY();
        double getZ();
        double length();
        friend ostream& operator<<(ostream &, const Point&);
        Point operator=(const Point &);
        double operator*(const Point&);
        friend Point operator*(int, Point&);
        Point operator*(int);
        Point operator+(const Point &);
        Point operator-(const Point &);
        Point operator/(const Point &);
        Point operator/(int);
        bool operator==(const Point &);

};

#endif