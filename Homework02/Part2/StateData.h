/*
Author: Cole Barbes
Creation Date: 02/21/23
Last Update: 02/22/23
Description: This class was created to hold data for a state in regards to carbon emmissions
Notes: The idea used here is similar to a vector safeguarding memory leaks and multiple frees
*/
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
