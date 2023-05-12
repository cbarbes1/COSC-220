/*
Author: Cole Barbes
Creation Date: 05/10/23
Last Update: 05/10/23
Description: This program gets the speed of many differents searches and sorts for a given number of elements and searches
*/
#include <iostream>
#include <algorithm>
#include "AVLTree.h" // include for tree
#include "BinaryTree.h" // include for tree 
#include <chrono>

using namespace std;

// prototype for the binary search function
template<class T> 
int BinarySearch(T[], int, int, T);

int main()
{
    srand(time(NULL)); // set the seed

    // create needed variables to hold each piece of data
    // the totals and the number of items and searches
    int numInt = 0;
    int numSearch = 0;
    int target = 0;
    double total_BinaryTime = 0;
    double total_AVLTime = 0;
    double total_ArrayTime = 0;

    BinaryTree<int> BTree; // init the binary tree
    AVLTree<int> ATree; // init the avl tree

    // take the input from the user
    cout<<"Please enter the number of integers you wish to use:";
    cin>>numInt;

    cout<<"Please enter the number of searches you wish to perform:";
    cin>>numSearch;
    //
    cout<<endl;
    int *array = new int[numInt]; // init the array of integers for the values to be sorted

    // fill the array with randoms 
    for(int i = 0; i<numInt; i++){
        array[i] = (rand()%1000000000)+1;
    }

    // time for the Binary tree sort
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

    // place the code to be timed here
    for(int i = 0; i<numInt; i++){
        BTree.insertNode(array[i]); // insert nodes into the tree
    }
    //
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    // print the output data
    cout<<"Time to insert into the Binary Tree: "<<time_span.count()<<" Seconds."<<endl;
    total_BinaryTime = time_span.count(); // save the time to the total
    //

    // time for the AVL tree insert
    t1 = chrono::high_resolution_clock::now();

    // place the code to be timed here
    for(int i = 0; i<numInt; i++){
        ATree.insertNode(array[i]); // insert nodes into the avl tree
    }
    //
    t2 = chrono::high_resolution_clock::now();

    time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    // print the output 
    cout<<"Time to insert into the AVL Tree: "<<time_span.count()<<" Seconds."<<endl;
    total_AVLTime = time_span.count(); // save the time span

    // time for the sort of the array
    t1 = chrono::high_resolution_clock::now();

    // place the code to be timed here
    sort(array, array+(numInt-1));
    //
    t2 = chrono::high_resolution_clock::now();

    time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    // output the data
    cout<<"Time to sort array (algorithm library method): "<<time_span.count()<<" Seconds."<<endl;
    total_ArrayTime = time_span.count();
    //
    cout<<endl;
    // time for the binary tree search node function
    t1 = chrono::high_resolution_clock::now();

    // place the code to be timed here
    for(int i = 0; i<numSearch; i++){
        target = (rand()%1000000000)+1;
        BTree.searchNode(target); // search the tree
    }
    //
    t2 = chrono::high_resolution_clock::now();

    time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    // output the data
    cout<<"Time to search binary tree: "<<time_span.count()<<" Seconds."<<endl;
    total_BinaryTime += time_span.count();

    // time for the AVL tree seach node function
    t1 = chrono::high_resolution_clock::now();

    // place the code to be timed here
    for(int i = 0; i<numSearch; i++){
        target = (rand()%1000000000)+1;
        ATree.searchNode(target); // search the tree
    }
    //
    t2 = chrono::high_resolution_clock::now();

    time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    // output the data
    cout<<"Time to search AVL tree: "<<time_span.count()<<" Seconds."<<endl;
    total_AVLTime +=time_span.count();

    // time for the binary search function
    t1 = chrono::high_resolution_clock::now();

    // place the code to be timed here
    for(int i = 0; i<numSearch; i++){
        target = (rand()%1000000000)+1;
        BinarySearch(array, 0, (numInt-1), target); // search the array
    }
    //
    t2 = chrono::high_resolution_clock::now();

    time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    // output the data
    cout<<"Time to search array: "<<time_span.count()<<" Seconds."<<endl;
    total_ArrayTime += time_span.count(); 

    cout<<endl;
    // output the total data
    cout<<"Total Times in Seconds "<<endl;
    cout<<"Binary Tree  "<<total_BinaryTime<<endl;
    cout<<"AVLTree      "<<total_AVLTime<<endl;
    cout<<"Array        "<<total_ArrayTime<<endl;


    delete [] array; // deallocate the array

    return 0;
}

/*
Description: This function searches for a value using a recursive binary search algorithm
Parameters: the array the start the end and the key
*/
template<class T>
int BinarySearch(T A[], int start, int end, T key)
{
    if(start<=end){ // if start overtakes the end done
        int mid = (start+end)/2; // recalculate the middle

        if(key == A[mid]){ // if found return
            return mid;
        }
        else if(key < A[mid]){ // cut last half off
            return BinarySearch(A, start, mid-1, key);
        }
        else{ // cut first half off
            return BinarySearch(A, mid+1, end, key);
        }
    }
    return -1;
}