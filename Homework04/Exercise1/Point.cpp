/*
* Author: Cole Barbes
* Creation Date: 03/03/23
* Last Update: 03/07/23
*/
#include "Point.h" // include header file
#include <cmath> // cmath to sqrt
#include <cstdlib>
using namespace std;

/*
* Description: this constructs a default point 0
*/
Point::Point()
{
    x = 0;
    y = 0;
    z = 0;
}

/*
* Description: This contructs a defined point at n,m,s
* Parameters: integer values for the point
* Return: no return
* Notes: 
*/
Point::Point(int n, int m, int s)
{
    x = n;
    y = m;
    z = s;
}

/*
* Description: This constructs a defined point at n,m,s
* Parameters: double variables n,m,s
* Return: no return
* Notes: 
*/
Point::Point(double n, double m, double s)
{
    x = n;
    y = m;
    z = s;
}

/*
* Description: set the point to a different n,m,s point
* Parameters: integer values for a new point
* Return: 
* Notes: 
*/
void Point::setXYZ(int n, int m, int s)
{
    x = n;
    y = m;
    z = s;
}

/*
* Description: set the point to a different n,m,s point
* Parameters: integer values for a new point
* Return: no return
* Notes: 
*/
void Point::setXYZ(double n, double m, double s)
{
    x = n;
    y = m;
    z = s;
}

/*
* Description: set x
* Parameters: double n
* Return: 
* Notes: 
*/
void Point::setX(double n)
{
    x = n;
}

/*
* Description: set y
* Parameters: double m
* Return: 
* Notes: 
*/
void Point::setY(double m)
{
    y = m;
}


/*
* Description: set z
* Parameters: double s
* Return: 
* Notes: 
*/
void Point::setZ(double s)
{
    z = s;
}

/*
* Description: set x 
* Parameters: integer n
* Return: 
* Notes: 
*/
void Point::setX(int n)
{
    x = n;
}

/*
* Description: set y 
* Parameters: integer m
* Return: 
* Notes: 
*/
void Point::setY(int m)
{
    y = m;
}

/*
* Description: set z
* Parameters: integer s
* Return: 
* Notes: 
*/
void Point::setZ(int s)
{
    z = s;
}

/*
* Description: get x
* Parameters: none
* Return: the value of x
* Notes: 
*/
double Point::getX()
{
    return x;
}

/*
* Description: get y
* Parameters: none
* Return: the value of y
* Notes: 
*/
double Point::getY()
{
    return y;
}

/*
* Description: get z
* Parameters: none
* Return: the value of z
* Notes: 
*/
double Point::getZ()
{
    return z;
}

/*
* Description: this function returns the length of the point
* Parameters: none
* Return: return the length
* Notes: 
*/
double Point::length()
{
    return sqrt(pow(x, 2)+pow(y, 2)+pow(z, 2));
}

/*
* Description: this function overloads the out stream to print this distinct data type 
* Parameters: the strm its being sent into and the object reference 
* Return: return the stream
* Notes: 
*/
ostream& operator<<(ostream &strm, const Point &obj)
{
    strm<<'('<<obj.x<<','<<' '<<obj.y<<','<<' '<<obj.z<<')';
    return strm;
}

/*
* Description: this function overloads the = sign to assign new value to the object
* Parameters: take the value being assigned as another object
* Return: return the dereferenced pointer to this object
* Notes: 
*/
Point Point::operator=(const Point &right)
{
    setXYZ(right.x, right.y, right.z);
    return *this;
}
/*
* Description: this function overloads the + sign to add two object together
* Parameters: the right point
* Return: return the value as anther point
* Notes: 
*/
Point Point::operator+(const Point &right)
{
    Point temp(x+right.x, y+right.y, z+right.z);
    return temp;
}

/*
* Description: this function overloads the - sign to subtract a point from another
* Parameters: the right point
* Return: return the value of the point
* Notes: 
*/
Point Point::operator-(const Point &right)
{
    Point temp(x-right.x, y-right.y, z-right.z);
    return temp;
}

/*
* Description: this function overloads the * sign to multiply a point by a number
* Parameters: the integer on the right
* Return: return the value of the point
* Notes: 
*/
Point Point::operator*(int right)
{
    Point temp(x*right, y*right, z*right);
    return temp;
}

/*
* Description: this function overloads the * sign but on the left of the object
* Parameters: the left integer and the right point 
* Return: return the value of the point
* Notes: 
*/
Point operator*(int left, Point &right)
{
    Point temp(left*right.getX(), left*right.getY(), left*right.getZ());
    return temp;
}

/*
* Description: this function overloads the * sign to muliply two objects
* Parameters: the right point
* Return: return the value of the point
* Notes: 
*/
double Point::operator*(const Point &right)
{
    double temp = (x*right.x + y*right.y + z*right.z);
    return temp;
}

/*
* Description: this function divides one point by another overloading the / sign
* Parameters: the right point 
* Return: the value of the point
* Notes: 
*/
Point Point::operator/(const Point &right)
{
    Point temp(x/right.x, y/right.y, z/right.z);
    return temp;
}

/*
* Description: this function divides a point by a number
* Parameters: the number on the right
* Return: return the value of the point
* Notes: 
*/
Point Point::operator/(int right)
{
    Point temp(x/right, y/right, z/right);
    return temp;
}

/*
* Description: this function finds if two points are equal, this is done by overloading the == sign
* Parameters: the right point
* Return: return whether the points are equal
* Notes: 
*/
bool Point::operator==(const Point &right)
{
    if(x==right.x&&y==right.y&&z==right.z){
        return true;
    }
    else{
        return false;
    }
}