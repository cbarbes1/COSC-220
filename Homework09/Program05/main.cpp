/*
Author: Cole Barbes
Creation Date: 04/21/23
Last Update: 04/21/23
Description: This program implements a permute function that permutes a vector of 1-n numbers
User Interface: simple user input interface
*/
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int factorial(int); // function to find the factorial
void permute(vector<int>, int); // functino to find the permutations of an n number

int main()
{
    int size; // hold the size of the array
    vector<int> permuted; // permute array
    
    // take the input
    cout<<"Enter the size of the permutation list: ";
    cin>>size;

    // get the string of 1----n
    for(int i = 1; i<=size; i++){
        permuted.push_back(i);
    }

    permute(permuted, 0); // permute the string 

    return 0;
}

/*
* Description: This function derives the factorial of an n number
* Parameters: Integer to get the factorial
* Return: the factorial
*/
int factorial(int n)
{
    if(n==1){
        return n;
    }else {
        return (n*factorial(n-1));
    }
}

/*
* Description: This function permutes a given vector of numbers
* Parameters: a vector of numbers and an index
*/
void permute(vector<int> permList, int index)
{
    int count; // count for use in the else
    static int numPermuted = 0; // static member for verification
    if(index == static_cast<int>(permList.size())){
        numPermuted++; // add to the static member
        // for loop to print the list
        for(int i = 0; i<index; i++){
            cout<<permList[i]<<" ";
            
        }
        cout<<endl;
        // if it reaches the end print the number of permutations 
        if(permList[0] == static_cast<int>(permList.size()) && numPermuted == factorial(static_cast<int>(permList.size()))){
            cout<<"The number of permutations is: "<<numPermuted<<endl;
        }
    }
    else{
        count = index; // set the count to index
        while(count < static_cast<int>(permList.size())){ // while the number is not at the end continue
            swap(permList[index], permList[count]); //swap the number with the given other number
            permute(permList, index+1); // recurse 
            swap(permList[index], permList[count]); //reset
            count++; // add to the count
        }
    }
}