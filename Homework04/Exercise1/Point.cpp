#include "Point.h"
#include <cmath>
#include <cstdlib>
using namespace std;

Point::Point()
{
    x = 0;
    y = 0;
    z = 0;
}
Point::Point(int n, int m, int s)
{
    x = n;
    y = m;
    z = s;
}
Point::Point(double n, double m, double s)
{
    x = n;
    y = m;
    z = s;
}
void Point::setXYZ(int n, int m, int s)
{
    x = n;
    y = m;
    z = s;
}
void Point::setXYZ(double n, double m, double s)
{
    x = n;
    y = m;
    z = s;
}
void Point::setX(double n)
{
    x = n;
}
void Point::setY(double m)
{
    y = m;
}
void Point::setZ(double s)
{
    z = s;
}
void Point::setX(int n)
{
    x = n;
}

void Point::setY(int m)
{
    y = m;
}

void Point::setZ(int s)
{
    z = s;
}

double Point::getX()
{
    return x;
}
double Point::getY()
{
    return y;
}
double Point::getZ()
{
    return z;
}
double Point::length()
{
    return sqrt(pow(x, 2)+pow(y, 2)+pow(z, 2));
}
ostream& operator<<(ostream &strm, const Point &obj)
{
    strm<<'('<<obj.x<<','<<' '<<obj.y<<','<<' '<<obj.z<<')';
    return strm;
}
Point Point::operator=(const Point &right)
{
    setXYZ(right.x, right.y, right.z);
    return *this;
}
Point Point::operator+(const Point &right)
{
    Point temp(x+right.x, y+right.y, z+right.z);
    return temp;
}
Point Point::operator-(const Point &right)
{
    Point temp(x-right.x, y-right.y, z-right.z);
    return temp;
}
Point Point::operator*(int right)
{
    Point temp(x*right, y*right, z*right);
    return temp;
}
Point operator*(int left, Point &right)
{
    Point temp(left*right.getX(), left*right.getY(), left*right.getZ());
    return temp;
}
double Point::operator*(const Point &right)
{
    double temp = (x*right.x + y*right.y + z*right.z);
    return temp;
}
Point Point::operator/(const Point &right)
{
    Point temp(x/right.x, y/right.y, z/right.z);
    return temp;
}
Point Point::operator/(int right)
{
    Point temp(x/right, y/right, z/right);
    return temp;
}
bool Point::operator==(const Point &right)
{
    if(x==right.x&&y==right.y&&z==right.z){
        return true;
    }
    else{
        return false;
    }
}