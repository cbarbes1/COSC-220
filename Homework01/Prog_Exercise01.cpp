/*
 * Author: <Cole Barbes>
 * Creation Date: <02/06/23>
 * Last Update: <02/06/23>
 * Description: <One paragraph describing the function of the program>
 * User Interface: <List of all user options and short descriptions of each option>
 * Notes: <Any notes that a user of the program should know about>
 */
#include <iostream> 
#include <ctime>

using namespace std;

void div();
int* duplicateArray(int* arr, int n);
void display(int* arr, int n);
int* getRandomNumbers(int n);
void sort(int* &arr, int n);
bool sorted(int* arr, int n);
void concat(int* arr1, int n1, int* arr2, int n2);
void remove(int* &arr, int n, int StartI, int EndI);
void sub(int* arr, int n, int StartI, int EndI);
void insert(int* arr1, int size1, int* arr2, int size2, int itervar);
void resize(int* arr, int n, int newSize);

int main() {
    int size = 0;
    
    cout << "Input array size: ";
    cin >> size;
    
    int *A = getRandomNumbers(size);
    
    display(A, size);
    sort(A, size);
    display(A, size);
    
    if (sorted(A, size))
        cout << "Array is sorted." << endl;
    else
        cout << "Array is not sorted." << endl;
    
    div();
    
    delete[] A;
    A = new int[10];
    size = 10;
    
    for (int i = 0; i < size; i++)
        A[i] = i + 1;
    int *copyA = duplicateArray(A, size);
    
    display(A, size);
    shuffle(A, size);
    display(A, size);
    cout << sorted(A, size) << endl;
    sort(A, size);
    display(A, size);
    cout << sorted(A, size) << endl;
    
    div();
    
    int *B = new int[5];
    int sizeB = 5;
    
    for (int i = 0; i < sizeB; i++)
        B[i] = rand() % 100;
    
    display(B, sizeB);
    display(A, size);
    concat(A, size, B, sizeB);
    display(B, sizeB);
    display(A, size);
    
    div();
    
    // Reset A to original data.
    delete[] A;
    size = 10;
    A = duplicateArray(copyA, size);
    
    display(A, size);
    remove(A, size, 3, 7);
    display(A, size);
    
    div();
    
    // Reset A to original data.
    delete[] A;
    size = 10;
    A = duplicateArray(copyA, size);
    
    display(A, size);
    sub(A, size, 3, 7);
    display(A, size);
    
    div();
    
    // Reset A to original data.
    delete[] A;
    size = 10;
    A = duplicateArray(copyA, size);
    
    display(A, size);
    display(B, sizeB);
    insert(A, size, B, sizeB, 2);
    display(A, size);
    
    div();
    
    // Reset A to original data.
    delete[] A;
    size = 10;
    A = duplicateArray(copyA, size);
    
    display(A, size);
    resize(A, size, 20);
    display(A, size);
    
    div();
    
    // Reset A to original data.
    delete[] A;
    size = 10;
    A = duplicateArray(copyA, size);
    
    display(A, size);
    resize(A, size, 5);
    display(A, size);
    
    delete[] A;
    A = nullptr;
    delete[] copyA;
    copyA = nullptr;
    delete[] B;
    B = nullptr;
    
    return 0;
}
