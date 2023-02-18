/*
Created by: Cole Barbes
Creation Date: 02/17/2023
Last Updated: 02/17/2023 
Purpose: Implement class functions
*/
#include "IntArrayList.h"

/*
Description:
*/
IntArrayList::IntArrayList()
{
    list = nullptr;
    size = 0;
}
IntArrayList::-IntArrayList()
{
    delete[] list;
    list = nullptr;
}
void IntArrayList::duplicate(IntArrayList& L2)
{
    int s = size;
    if(s>L2..length()){
        s = L2.length();
    }
    for(int i = 0; i<s; i++){
        L2[i] = list[i];
    }
}
void IntArrayList::display(bool vert)
{
    for(int i = 0; i<size; i++){
        if(vert){
            cout<<list[i]<<"\n";
        }
        else{
            cout<<list[i];
        }
    }
}
void IntArrayList::displayAddress()
{
    cout<<list<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//
//                   <This function swaps 2 elements>
//
////////////////////////////////////////////////////////////////////////////////////////////
void IntArrayList::swap(int* arr, int n1, int n2) {
    int temp = *(arr + n1);
    *(arr + n1) = *(arr + n2);
    *(arr + n2) = temp;
}

void IntArrayList::sort()
{
    int i, minIdx;
    for(i=0; i<size-1; i++){
        minIdx = i;
        for(int j = i+1; j<size; j++){
            if(list[j]<list[minIdx]){
                minIdx = j;
            }
        }
        
        if(minIdx != i){
            swap(list, minIdx, i);
        }
    }
}

bool IntArrayList::sorted()
{
    bool checker = true;
    for(int i = 0; i<size-1; i++){
        if(list[i]>list[(i+1)]){
            checker = false;
        }
    }
}
void IntArrayList::add(int newE)
{
    size +=1;

    int* tmpArr = new int[size];

    for(int i = 0; i<size; i++){
        if(i<size-2){
            tmpArr[i] = list[i];
        }
        else{
            tmpArr[i] = newE;
        }
    }

    delete [] list;
    
    list = tmpArr;
}
void IntArrayList::concat(const IntArrayList& L2)
{
    if(L2.length()>0){

        int OGSize = size;
        size = size + L2.length();

        int* tmpArr = new int[size];

        for(int i = 0; i<size; i++){
            if(i<OGSize){
                tmpArr[i] = list[i];
            }
            else{
                tmpArr[i] = L2[(i-OGSize-1)];
            }
        }

        delete[] list;
        list = tmpArr;
    }
}
void IntArrayList::remove(int StartI, int EndI)
{
    int d = EndI - StartI;
}
void IntArrayList::shuffle()
{

}
void IntArrayList::sub(int, int)
{

}
void IntArrayList::insert(const IntArrayList&, int)
{

}
void IntArrayList::insert(int, int)
{

}
int IntArrayList::get(int)
{

}
void IntArrayList::set(int, int)
{

}
void IntArrayList::resize(int)
{

}
int IntArrayList::length()
{
    return size;
}