/*
Created by: Cole Barbes
Date Created: 02/16/23
*/
#ifndef SPHERE_H
#define SPHERE_H

class Sphere{
    private:
        double x;
        double y;
        double z;
        double rad;

        double distance(double, double, double);

    public:
        Sphere(double ix = 0, double iy = 0, double iz = 0, double ir = 0);
        //~Sphere();
        void setCenter(double ix = 0, double iy = 0, double iz = 0);
        void setRadius(double ir = 1);
        double getRadius();
        double getX();
        double getY();
        double getZ();
        bool collide(Sphere s);
        void printSphereInfo();
};
#endif