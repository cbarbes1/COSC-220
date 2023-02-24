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
    if(size==0){ 
        size +=1;
        double* tmpArr = new double[size];
        tmpArr[size] = number;
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
