/*
Created by: Cole Barbes
Date Created: 02/16/23
*/
#include <iostream>
#include "Sphere.h"

using namespace std;

double randDouble();

int main()
{
    int numSpheres = 0;
    int collisionCount = 0;
    cout<<"Input the number of spheres: ";
    cin>>numSpheres;
    cout<<endl;

    Sphere *SphereArr = nullptr;
    SphereArr = new Sphere[numSpheres];
    int *collisions = new int[numSpheres];

    for(int i = 0; i<numSpheres; i++){
        SphereArr[i].setCenter(randDouble()*10, randDouble()*10, randDouble()*10);
        SphereArr[i].setRadius(randDouble()+0.1);
    }
    for(int i = 0; i<(numSpheres-1); i++){
        if(SphereArr[i].collide(SphereArr[(i+1)])){
            collisionCount++;
            collisions[i] = (i+1);
            collisions[(i+1)] = (i);
        }
        if((i+1)==numSpheres){
            if(SphereArr[(i+1)].collide(SphereArr[0])){
                collisionCount++;
                collisions[0] = (i+1);
                collisions[(i+1)] = 0;   
            }
        }
    }
    cout<<"The number of collisions is: "<<collisionCount<<endl;

    cout<<"Collision List: "<<endl;
    for(int i = 0; i<(numSpheres-1); i++){
        if(SphereArr[i].collide(SphereArr[(i+1)])){
           cout<<i<<" - "<<(i+1)<<endl;
        }
        if((i+1)==numSpheres){
            if(SphereArr[(i+1)].collide(SphereArr[0])){
                  cout<<0<<" - "<<(i+1)<<endl;
            }
        }
    }

    delete[] SphereArr;
    SphereArr = nullptr;
    delete[] collisions;
    collisions = nullptr;
    return 0;
}
double randDouble()
{
    double randNum = (double)rand()/RAND_MAX;

    return randNum;
}