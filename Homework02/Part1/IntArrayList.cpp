/*
Created by: Cole Barbes
Creation Date: 02/17/2023
Last Updated: 02/17/2023 
Purpose: Implement class functions
*/
#include "IntArrayList.h"

using namespace std;

/*
Description:
*/
IntArrayList::IntArrayList()
{
    list = nullptr;
    size = 0;
}
/*
Description:
*/
IntArrayList::~IntArrayList()
{
    delete[] list;
    list = nullptr;
}
/*
Description:
*/
void IntArrayList::duplicate(IntArrayList& L2)
{
    L2.resize(size);
    for(int i = 0; i<size; i++){
        L2.set(list[i], i);
    }
}
/*
Description:
*/
void IntArrayList::display(bool vert)
{
    for(int i = 0; i<size; i++){
        if(vert){
            cout<<list[i]<<" "<<"\n";
        }
        else{
            cout<<list[i]<<" ";
        }
    }
    cout<<endl;
}
/*
Description:
*/
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

/*
Description:
*/
bool IntArrayList::sorted()
{
    bool checker = true;
    for(int i = 0; i<size-1; i++){
        if(list[i]>list[(i+1)]){
            checker = false;
        }
    }
    if(list[0]>list[size]){
        checker = false;
    }
    return checker;
}

/*
Description:
*/
void IntArrayList::add(int newE)
{
    size +=1;

    int* tmpArr = new int[size];

    for(int i = 0; i<size; i++){
        if(i<size-1){
            tmpArr[i] = list[i];
        }
        else{
            tmpArr[i] = newE;
        }
    }

    delete [] list;
    
    list = tmpArr;
}

/*
Description:
*/
void IntArrayList::concat(const IntArrayList& L2)
{
    int s2 = L2.length();
    if(s2>0){

        int OGSize = size;
        size = size + s2;

        int* tmpArr = new int[size];
        int count = 0;
        for(int i = 0; i<size; i++){
            if(i<OGSize){
                tmpArr[i] = list[i];
            }
            else{
                tmpArr[i] = L2.get(count);
                count++;
            }
        }

        delete[] list;
        list = tmpArr;
    }
}
/*
Description:
*/
void IntArrayList::remove(int StartI, int EndI)
{
    if(StartI<0){
        StartI = 0;
    }
    int d = EndI - StartI;
    size = size-d;
    if(d!=0){
        if(d>(size-1)){
            size = 0;
            delete[] list;
            list = nullptr;
        }
        else if(EndI>(size-1)){
            EndI = (size-1);
        }
        int *tmpList = new int[size];
        int count = 0;
        for(int i = 0; i<size; i++){
            if(i<StartI){
                tmpList[i] = list[i];
            }
            else {
                tmpList[i] = list[(EndI+count)];
                count++;
            }
        }
    delete[] list;
    list = tmpList;
    }
}
/*
Description:
*/
void IntArrayList::shuffle()
{
    random_shuffle(list, list+size);
}

/*
Description:
*/
void IntArrayList::sub(int StartI, int EndI)
{
    int S = StartI;
    int* tmpList;
    if(S<0){
        S=0;
    }
    int d = EndI-S;
    if(d>=1){
        tmpList = new int[d];
        for(int i = 0; i<d; i++){
            tmpList[i] = list[(S+i)];
        }
    }
    size = d;
    delete[] list;
    list = tmpList;
}

/*
Description:
*/
void IntArrayList::insert(const IntArrayList& otherList, int n)
{
    if(n<0){
        n = 0;
    }
    int s2 = otherList.length();
    size = size+s2;
    int* tmpList = new int[size];
    
    int count = 0;
    for(int i = 0; i<size; i++)
        if(i<n){
            tmpList[i] = list[i];
        }
        else if(i>=n&&i<(n+s2)){
            tmpList[i] = otherList.get(count);
            count++;
        }
        else{
            tmpList[i] = list[(i-n)];
        }
    delete[] list;
    list = tmpList;
}
void IntArrayList::insert(int insertValue, int index)
{
    if(index<size&&index>=0){
        size = size+1;
        int *tmpList = new int[size];
        for(int i = 0; i<size; i++){
            if(i<index||i>index){
                tmpList[i] = list[i];
            }
            else{
                tmpList[i] = insertValue;
            }
        }
        delete [] list;
        list = tmpList;
    }
}
int IntArrayList::get(int n) const
{
    if(n<0){
        n = 0;
    }
    else if(n>size){
        n = (size-1);
    }
    if(size>0){
        return list[n];
    }
    else {
        return 0;
    }
    
}
void IntArrayList::set(int newValue, int index) const
{
    if(index>=0&&index<size){
        list[index] = newValue;
    }
    else{
        cout<<"Error: The index is out of range!"<<endl;
    }
}
void IntArrayList::resize(int newSize)
{
    int oldSize = size;
    size = newSize;
    int *tmpList = new int[size];
    for(int i = 0; i<size; i++){
        if(i<oldSize){
            tmpList[i] = list[i];
        }
        else{
            tmpList[i] = 0;
        }
    }
    delete[] list;
    list = tmpList;
}
int IntArrayList::length() const
{
    return size;
}