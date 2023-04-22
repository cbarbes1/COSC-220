/*
Author: Cole Barbes
Creation Date: 04/21/23
Last Update: 04/21/23
Description: This program find the n choose k value
*/
#include <iostream>

using namespace std;

int NChooseK(int, int); // prototype for n choose k function

int main()
{
    // init values to 0 for safety
    int nValue = 0;
    int kValue = 0;

    // take input from user of the n and k value seperated by a space
    cout<<"Enter n and k (integer) with a space between them: "<<endl;
    cin>>nValue>>kValue;

    // print the result
    cout<<nValue<<" Choose "<<kValue<<" = "<<NChooseK(nValue, kValue)<<endl;

    return 0;
}

/*
Description: Recursize n choose k function to return a value from pascals triangle
Parameters: n value and k value to check the n choose k
return the pascals triangle value 
*/
int NChooseK(int n, int k)
{
    // if Statement to check the default cases
    if(k>n || n<0 || k<0){
        return 0;
    }
    else if(n==0 || k==0|| n==k){
        return 1;
    }
    // base case **
    if(k==1){
        return n;
    }else{ // recursive step pretty simple :)
        return NChooseK(n-1, k) + NChooseK(n-1, k-1);
    }

}