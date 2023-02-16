/*
Created by: Cole Barbes
Date Created: 02/16/23
*/
#include <iostream>
#include <cmath>
#include "Sphere.h"

using namespace std;

/*
*/
Sphere::Sphere(double ix, double iy, double iz, double ir)
{
    x = ix;
    y = iy;
    z = iz;
    if(ir<0){
        rad = 0;
    }
    else{
        rad = ir;
    }

}

/*
*/
void Sphere::setCenter(double ix, double iy, double iz)
{
    x = ix;
    y = iy;
    z = iz;
}

/*
*/
void Sphere::setRadius(double ir)
{
    if(ir<0){
        rad = 0;
    }
    else{
        rad = ir;
    }
}

/*
*/
double Sphere::getRadius()
{
    return rad;
}

/*
*/
double Sphere::getX()
{
    return x;
}

/*
*/
double Sphere::getY()
{
    return y;
}

/*
*/
double Sphere::getZ()
{
    return z;
}

/*
*/
double Sphere::distance(double x2, double y2, double z2)
{
    double diff1 = (x2-x)*(x2-x);
    double diff2 = (y2-y)*(y2-y);
    double diff3 = (z2-z)*(z2-z);
    double formula = (diff1) + (diff2) + (diff3);
    double d = sqrt(formula);

    return d;
}

/*
*/
bool Sphere::collide(Sphere s)
{
    double d = distance(s.getX(), s.getY(), s.getZ());
    double radSum = (rad + s.getRadius());
    bool collider = false;
    if(d < radSum){
        collider = true;
    }
    return collider;
}

/*
*/
void Sphere::printSphereInfo()
{
    cout<<"Center: ("<<x<<", "<<y<<", "<<z<<") Radius: "<<rad<<endl;
}


