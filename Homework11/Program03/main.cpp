/*
Author: Cole Barbes
Creation Date: 05/11/23
Last Update: 05/11/23
Description: This program tests different sort algorithms using a function pointer which is given to a function and used on that given sort
*/
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

//  Function Prototypes

template<class T>
void bubble(T A[], int size);

template<class T>
void insertion(T A[], int size);

template<class T>
void selection(T A[], int size);

template<class T>
void merge(T A[], T Temp[], int startA, int startB, int end);

template<class T>
void mergeSort(T A[], T Temp[], int start, int end);

template<class T>
void mergeSort(T A[], int size);

template<class T>
void quickSort(T A[], int left, int right);

template<class T>
void quickSort(T A[], int size);

template<class T> 
void Copy(T [], T [], int size);

template<class T>
void SortTiming(T [], int, string, void (*)(T[], int));

int main()
{
    srand(time(NULL)); // seed the rand

	// init needed vars
    int numInt = 0;
    int *A = nullptr;
    int *B = nullptr;

	// take the input
    cout<<"Enter the number of integers to use: ";
    cin>>numInt;

	// init the arrays
    A = new int[numInt];
    B = new int[numInt];

	// set randoms into the array
    for(int i = 0; i<numInt; i++){
        A[i] = (rand()%1000000000)+1;
    }

	// init vector of function pointers
    vector<void(*)(int[], int)> fcts;

	// create the vector
    fcts = {bubble, insertion, selection, mergeSort, quickSort};

	// create array of the corresponding names
    string names[] = {"Bubble", "Insertion", "Selection", "Merge", "Quick"};

	// for loop to time each sort
    for (unsigned long i = 0; i < fcts.size(); i++) {
        Copy(A, B, numInt);
        SortTiming(B, numInt, names[i], fcts[i]);
    }

    delete [] A;
    delete [] B;

    return 0;
}

// Sorting Algorithms

///////////////////////////////////////////////////////////

template<class T>
void bubble(T A[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (A[j] > A[j + 1]) {
				T temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

///////////////////////////////////////////////////////////

template<class T>
void insertion(T A[], int size) {
	for (int i = 0; i < size; i++) {
		int j = 0;
		T val = A[i];
		for (j = i; j > 0 && A[j - 1] > val; j--)
			A[j] = A[j - 1];

		A[j] = val;
	}
}

///////////////////////////////////////////////////////////

template<class T>
void selection(T A[], int size) {
	int minindex;

	for (int i = 0; i < size; i++) {
		minindex = i;
		for (int j = i; j < size; j++)
			if (A[j] < A[minindex])
				minindex = j;

		T val = A[i];
		A[i] = A[minindex];
		A[minindex] = val;
	}
}

///////////////////////////////////////////////////////////

template<class T>
void merge(T A[], T Temp[], int startA, int startB, int end) {
	int aptr = startA;
	int bptr = startB;
	int i = startA;

	while (aptr < startB && bptr <= end)
		if (A[aptr] < A[bptr])
			Temp[i++] = A[aptr++];
		else
			Temp[i++] = A[bptr++];

	while (aptr < startB)
		Temp[i++] = A[aptr++];

	while (bptr <= end)
		Temp[i++] = A[bptr++];

	for (i = startA; i <= end; i++)
		A[i] = Temp[i];
}

template<class T>
void mergeSort(T A[], T Temp[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(A, Temp, start, mid);
		mergeSort(A, Temp, mid + 1, end);
		merge(A, Temp, start, mid + 1, end);
	}
}

template<class T>
void mergeSort(T A[], int size) {
	T *Temp = new int[size];
	mergeSort(A, Temp, 0, size - 1);
    delete [] Temp;
}

///////////////////////////////////////////////////////////

template<class T>
void quickSort(T A[], int left, int right) {
	int i = left;
	int j = right;
	int mid = (left + right) / 2;

	T pivot = A[mid];

	while (i <= j) {
		while (A[i] < pivot)
			i++;

		while (A[j] > pivot)
			j--;

		if (i <= j) {
			T tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(A, left, j);

	if (i < right)
		quickSort(A, i, right);
}

template<class T>
void quickSort(T A[], int size) {
	quickSort(A, 0, size - 1);
}

///////////////////////////////////////////////////////////

/*
Description: This function copies the contents of an array A into an array B 
Parameters: array A, B and the size of both the arrays
Caution: assuming that both arrays are the same size means the arrays must come in formatted to the same size
*/
template<class T>
void Copy(T A[], T B[], int size)
{
    for(int i = 0; i<size; i++){
        B[i] = A[i];
    }
}

/*
Description: This function times a given sort function using a pointer to a function
*/
template<class T>
void SortTiming(T Array[], int size, string sortName, void (*fct)(T[], int))
{
    chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

    // sort the array
    fct(Array, size);
    //
    chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    cout<<"Time to sort with "<<sortName<<" Sort: "<<time_span.count()<<" seconds."<<endl;
}