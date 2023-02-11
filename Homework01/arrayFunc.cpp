#include "arrayFunc.h"
/*
* This is the implementation file for my functions.
* Creater: Cole Barbes
* Creation date: 2/11/23
*/







/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <This function simply prints space and a line to seperate output later.>
//Parameters: <no parameters>
//Return: <No return>
//Notes: <This function is reusable.>
////////////////////////////////////////////////////////////////////////////////////////////
void div()
{
    cout<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
    cout<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <This array takes and existing array and copies it. >
//Parameters: <A pointer to an array and the size of the array>
//Return: <return value is the new dynamic array>
//Notes: <Make sure the memory gets deleted as this only dynamically allocates the array.>
////////////////////////////////////////////////////////////////////////////////////////////
int* duplicateArray(int* arr, int n)
{
    int* newArr = new int[n];
    
    for(int i = 0; i<n;i++)
        newArr[i]=arr[i];
    
    return newArr;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <This function prints a given array>
//Parameters: <pointer to a dynamic array of size n, integer n>
//Return: <no return, just print >
//Notes: <Any notes that a user of the program should know about, e.g. pre/post conditions>
////////////////////////////////////////////////////////////////////////////////////////////
void display(int* arr, int n)
{
    for(int i =0; i<n; i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <One paragraph describing what the function does>
//Parameters: <List of parameters and their descriptions>
//Return: <What is returned by the function, if anything is returned>
//Notes: <Any notes that a user of the program should know about, e.g. pre/post conditions>
////////////////////////////////////////////////////////////////////////////////////////////
int* getRandomNumbers(int n)
{
    int* tmpArr = new int[n];
    
    for(int i = 0; i<n; i++)
        *(tmpArr+i) = (rand()%10)+1;
    
    return tmpArr;
    
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <This function swaps 2 elements>
//Parameters: <List of parameters and their descriptions>
//Return: <What is returned by the function, if anything is returned>
//Notes: <Any notes that a user of the program should know about, e.g. pre/post conditions>
////////////////////////////////////////////////////////////////////////////////////////////
void swap(int* arr, int n1, int n2) {
    int temp = *(arr + n1);
    *(arr + n1) = *(arr + n2);
    *(arr + n2) = temp;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <One paragraph describing what the function does>
//Parameters: <List of parameters and their descriptions>
//Return: <What is returned by the function, if anything is returned>
//Notes: <Any notes that a user of the program should know about, e.g. pre/post conditions>
////////////////////////////////////////////////////////////////////////////////////////////
void sort(int* arr, int n)
{
    int i, j, minIdx;
    for(i=0; i<n-1; i++){
        minIdx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[minIdx]){
                minIdx = j;
            }
        }
        
        if(minIdx != i){
            swap(arr, minIdx, i);
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <This Function recursively checks if the array is sorted.>
//Parameters: <List of parameters and their descriptions>
//Return: <What is returned by the function, if anything is returned>
//Notes: <Any notes that a user of the program should know about, e.g. pre/post conditions>
////////////////////////////////////////////////////////////////////////////////////////////
bool sorted(int* arr, int n)
{
    int size = n-1;
    if(size==0||size == 1){
        return true;
    }
    else if(arr[size-1]>arr[size]){
        return false;
    }
    else
        return sorted(arr, size);
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <One paragraph describing what the function does>
//Parameters: <List of parameters and their descriptions>
//Return: <What is returned by the function, if anything is returned>
//Notes: <Any notes that a user of the program should know about, e.g. pre/post conditions>
////////////////////////////////////////////////////////////////////////////////////////////
void concat(int* arr1, int n1, const int* arr2, int n2)
{
    for(int i = 0; i<n2; i++)
    {
        arr1[i] += arr2[i];
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <One paragraph describing what the function does>
//Parameters: <List of parameters and their descriptions>
//Return: <What is returned by the function, if anything is returned>
//Notes: <Any notes that a user of the program should know about, e.g. pre/post conditions>
////////////////////////////////////////////////////////////////////////////////////////////
void remove(int* &arr, int& n, int StartI, int EndI)
{
    int d = EndI-StartI;
    if(d>n){
        delete[] arr;
        arr = nullptr;
    }
    else if(StartI<EndI){
        int* tmpArr = new int[(n-d)];
        int count = 0;
        for(int i = 0; i<(n-d); i++){
            if(i<StartI){
                tmpArr[i] = arr[i];
            }
            else {
                tmpArr[i] = arr[(EndI+count)];
                count++;
            }
        }
        n = (n-d);
        delete[] arr;
        arr = tmpArr;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <One paragraph describing what the function does>
//Parameters: <List of parameters and their descriptions>
//Return: <What is returned by the function, if anything is returned>
//Notes: <Any notes that a user of the program should know about, e.g. pre/post conditions>
////////////////////////////////////////////////////////////////////////////////////////////
void shuffle(int* arr, int n)
{
    random_shuffle(arr, arr+n-1);
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <One paragraph describing what the function does>
//Parameters: <List of parameters and their descriptions>
//Return: <What is returned by the function, if anything is returned>
//Notes: <Any notes that a user of the program should know about, e.g. pre/post conditions>
////////////////////////////////////////////////////////////////////////////////////////////
void sub(int* &arr, int& n, int StartI, int EndI)
{
    int S = StartI;
    int* tmpArr;
    if(S<0){
        S=0;
    }
    int d = EndI-S;
    if(d>=1){
        tmpArr = new int[d];
        for(int i = 0; i<d; i++){
            tmpArr[i] = arr[(S+i)];
        }
    }
    n = d;
    delete[] arr;
    arr = tmpArr;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <One paragraph describing what the function does>
//Parameters: <List of parameters and their descriptions>
//Return: <What is returned by the function, if anything is returned>
//Notes: <Any notes that a user of the program should know about, e.g. pre/post conditions>
////////////////////////////////////////////////////////////////////////////////////////////
void insert(int* &arr1, int& size1, int* arr2, int size2, int itervar)
{
    int k = itervar;
    int* tmpArr = new int[size1+size2];
    if(k<0){
        k=0;
    }
    int count = 0;
    for(int i = 0; i<size1+size2; i++)
        if(i<k){
            tmpArr[i] = arr1[i];
        }
        else if(i>(k+size2-1)){
            tmpArr[i] = arr1[(i-size2)];
        }
        else{
            tmpArr[i] = arr2[count];
            count++;
        }
    size1 = size1+size2;
    delete[] arr1;
    arr1 = tmpArr;
}
/////////////////////////////////////////////////////////////////////////////////////////////
//Description: <One paragraph describing what the function does>
//Parameters: <List of parameters and their descriptions>
//Return: <What is returned by the function, if anything is returned>
//Notes: <Any notes that a user of the program should know about, e.g. pre/post conditions>
//////////////////////////////////////////////////////////////////////////////////////////// 
void resize(int* &arr, int& n, int newSize)
{
    int* tmpArr = new int[newSize];
    for(int i = 0; i<newSize; i++)
        if(i<n){
            tmpArr[i] = arr[i];
        }
        else {
            tmpArr[i] = 0;
        }
    n=newSize;
    delete[] arr;
    arr=tmpArr;
}