<<<<<<< HEAD
/*
Created by: Cole Barbes
Creation Date: 02/17/2023
Last Updated: 02/17/2023 
Purpose: Implement class functions
*/
=======
#ifndef STATEDATA_H
#define STATEDATA_H
#include <iostream>
#include <cstdlib>

using namespace std;

class StateData{
    private:
        string StateName;
        int size;
        double *data;
    public:
        StateData();
        ~StateData();

        void setStateName(string);
        string getStateName();
        void add(double);
        double get(int);
};

#endif
>>>>>>> f2c1dae2f3bbed71ac58ec11b0196d041268b0e3
