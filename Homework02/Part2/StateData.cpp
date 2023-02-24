/*
Author: Cole Barbes
Creation Date: 02/21/23
Last Update: 02/23/23
*/
#include "StateData.h"

using namespace std;

/*
* Default constructor to initialize the object
*/
StateData::StateData(){
    StateName = "";
    size = 0;
    data = nullptr;
}

/*
* Destructor for the object to delete used memory
*/
StateData::~StateData(){
    delete[] data;
    data = nullptr;
}

/*
* set the state name given a parameter
* name is the only parameter
*/
void StateData::setStateName(string name){
    StateName = name;
}

/*
* get the state name 
*/
string StateData::getStateName(){
    return StateName;
}

/*
* add an Description:element to the end of the data array
*/
void StateData::add(double number){
    if(size==0){ 
        size =1;
        double* tmpArr = new double[size];
        tmpArr[(size-1)] = number;
        delete [] data;
    
        data = tmpArr;
    }
    else{
        size+=1;
    
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

    
}

/*
* Get an element at the specified index
*/
double StateData::get(int index){
    if(index<size&&index>=0){
        return data[index];
    }
    else if(index<0){
        return data[0];
    }
    else if(index==size){
        return data[(size-1)];
    }
    else{
        return 0;
    }
}
