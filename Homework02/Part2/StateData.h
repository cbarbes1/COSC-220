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
