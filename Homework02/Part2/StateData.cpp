<<<<<<< HEAD
/*
Created by: Cole Barbes
Creation Date: 02/17/2023
Last Updated: 02/17/2023 
Purpose: Implement class functions
*/
=======
#include "StateData.h"

using namespace std;

StateData::StateData(){
    StateName = "";
    size = 0;
    data = nullptr;
}

StateData::~StateData(){
    delete[] data;
    data = nullptr;
}

void StateData::setStateName(string name){
    StateName = name;
}
string StateData::getStateName(){
    return StateName;
}
void StateData::add(double number){
    size +=1;

    double* tmpArr = new double[size];

    for(int i = 0; i<size; i++){
        if(i<size-1){
            tmpArr[i] = data[i];
        }
        else{
            tmpArr[i] = number;
        }
    }

    delete [] data;
    
    data = tmpArr;
}
double StateData::get(int index){
    if(size == 0){
        return 0;
    }
    else if(index<0){
        return data[0];
    }
    else if(index>=size){
        return data[(size-1)];
    }
    else{
        return 0;
    }
}
>>>>>>> f2c1dae2f3bbed71ac58ec11b0196d041268b0e3
